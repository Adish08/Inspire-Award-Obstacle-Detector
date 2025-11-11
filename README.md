# Blind Navigation Assistant – Ultrasonic Proximity Beeping System

A compact Arduino-based **navigation assistant** designed to help visually impaired users detect obstacles using **progressive audio feedback**.  
The system uses an **HC-SR04 ultrasonic sensor** to measure distance and a **piezo buzzer** to provide graded beeping patterns depending on proximity.

---

## ✅ Features

- 📡 Ultrasonic distance sensing (HC-SR04)
- 🔊 Adaptive audio alerts with increasing urgency
- ⚙️ Real-time distance calculation
- 🧠 Lightweight, simple, and fully Arduino-compatible
- 🔌 Works with USB or battery power

---

## ✅ How It Works

1. The ultrasonic sensor emits a high-frequency pulse.
2. It measures how long it takes for the echo to return.
3. Distance is computed using the speed of sound.
4. The buzzer produces different beep speeds and pitches:
   - Closer object → Faster + higher-pitch beeps
   - Farther object → Slower beeps or silence

---

## ✅ Hardware Requirements

| Component | Quantity |
|----------|----------|
| Arduino UNO / Nano | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Piezo Buzzer | 1 |
| Jumper Wires | As needed |
| (Optional) Breadboard | 1 |

---

## ✅ Pin Connections

| Arduino Pin | Component Pin | Description |
|-------------|---------------|-------------|
| 9           | HC-SR04 TRIG  | Trigger pulse output |
| 10          | HC-SR04 ECHO  | Echo return input |
| 11          | Piezo Buzzer  | Audio output |
| 5V / GND    | Sensor & Buzzer | Power |

---

## ✅ Wiring Diagram (ASCII)

           HC-SR04 Ultrasonic Sensor
      +---------------------------------+
      |        VCC --- 5V               |
      |        GND --- GND              |

    Arduino   |       TRIG — Pin 9      |
    UNO       |       ECHO — Pin 10     |
              
              +———————————+

              Piezo Buzzer
      +-----------------------------+
      |   + (Signal) ---- Pin 11    |
      |   - (GND) ------ GND        |
      +-----------------------------+

---

## ✅ Distance-Based Alerts

| Distance Range | Alert Level | Behavior |
|----------------|-------------|----------|
| 0–15 cm        | 🚨 Immediate Danger | Continuous high-pitch beep |
| 15–25 cm       | High Alert | Very fast beeps |
| 25–50 cm       | Caution | Fast beeps |
| 50–80 cm       | Awareness | Moderate beeps |
| 80–120 cm      | Early Warning | Slow beeps |
| >120 cm        | Safe | No beep |

---

## ✅ How to Use

1. Install the Arduino IDE.
2. Clone this repository:
   git clone https://github.com/YourUsername/BlindNavigationAssistant.git
3. Open the `.ino` file in Arduino IDE.
4. Connect your Arduino UNO/Nano.
5. Select:
   - Board: Arduino UNO / Nano
   - Port: COMx (Windows) / ttyUSBx (Linux) / cu.usbmodem (Mac)
6. Upload the code.
7. Open Serial Monitor at 9600 baud to see distance logs.


⸻

## ✅ Future Improvements
	•	Add vibration motor for silent haptic feedback
	•	Integrate an OLED display
	•	Add Kalman filtering for stable readings
	•	Make it wearable (cap, glasses, wristband, etc.)

⸻

## ✅ License

This project is open-source and available for modification and enhancement.
