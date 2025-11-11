#define trigPin 9
#define echoPin 10
#define piezoPin 11

long duration, distance;

void setup()
{
  Serial.begin(9600);
  delay(100);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(piezoPin, OUTPUT);
  
  Serial.println("Blind Navigation Assistant Ready");
  Serial.println("Audio feedback increases as obstacles approach");
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance > 0 && distance <= 15)
  {
    // CONTINUOUS BEEP - IMMEDIATE DANGER
    Serial.println("CONTINUOUS ALERT - OBSTACLE TOO CLOSE!");
    tone(piezoPin, 1500); // Higher pitch for urgency
    delay(100); // Keep tone on continuously during this loop
  }
  else if (distance > 15 && distance <= 25)
  {
    // Very fast beeping - HIGH ALERT
    Serial.println("HIGH ALERT - OBSTACLE VERY CLOSE!");
    tone(piezoPin, 1200);
    delay(100);
    noTone(piezoPin);
    delay(50);
  }
  else if (distance > 25 && distance <= 50)
  {
    // Fast beeping - CAUTION
    Serial.println("CAUTION - OBSTACLE APPROACHING!");
    tone(piezoPin, 1000);
    delay(150);
    noTone(piezoPin);
    delay(150);
  }
  else if (distance > 50 && distance <= 80)
  {
    // Moderate beeping - AWARENESS
    Serial.println("AWARENESS - OBSTACLE DETECTED!");
    tone(piezoPin, 800);
    delay(150);
    noTone(piezoPin);
    delay(350);
  }
  else if (distance > 80 && distance <= 120) // Extended range for early warning
  {
    // Slow beeping - EARLY WARNING
    Serial.println("EARLY WARNING - OBSTACLE AHEAD!");
    tone(piezoPin, 600);
    delay(100);
    noTone(piezoPin);
    delay(500);
  }
  else
  {
    // No obstacle detected - silence
    noTone(piezoPin);
  }
  
  delay(30); // Faster response time for navigation
}
