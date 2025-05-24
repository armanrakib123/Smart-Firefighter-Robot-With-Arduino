![Smart-Firefighter-Robot-With-Arduino](https://inrorwxhkjlolm5p.leadongcdn.com/cloud/mlBpqKmnRljSjljooplml/M40D-11KT.png)

# 🔥 Smart-Firefighter-Robot-With-Arduino 🚗🔥
This Arduino project combines a flame sensor system with a Bluetooth-controlled car.
The flame sensor triggers a pump through a relay when fire is detected.
A Bluetooth module allows remote control of car movement, steering, and lights.
The project integrates fire safety with remote mobility for practical applications.
Ideal for educational robotics and embedded systems learning.

## App Link : https://play.google.com/store/apps/details?id=com.SanitTech.RCBluetoothControllerHC05

#### Code
Language: Processing\
[Download Arduino](https://www.arduino.cc/en/software) to install Standard Firmata on your board\
[Download Processing](https://fritzing.org/) to simulation software.

#### Eletronic components
<table>
  <tr>
    <th>Arduino Uno</th>
    <th>Gear Motor</th>
    <th>HC-05</th>
    <th>L298N</th>
    <th>Servo Motor</th>
    <th>jumpers</th>
  </tr>
  <tr>
    <td><img width="200" src="https://user-images.githubusercontent.com/47862856/179044732-13a1cc4e-458f-4a54-916a-d736a981d54e.png"></td>
    <td><img width="200" src="https://vayuyaan-media.s3.ap-south-1.amazonaws.com/wp-content/uploads/2021/10/29074018/Dual-Shaft-BO-Motor-With-BO-Wheel-Yellow-Vayuyaan.jpg"></td>
    <td><img width="200" src="https://quartzcomponents.com/cdn/shop/products/HC05-Bluetooth-Module.jpg?v=1675065241"></td>
    <td><img width="200" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT28HC-Pq6EY8St4FXjqQtvIaZ1XmPiv5o8BQ&s"></td>
    <td><img width="200" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRWaaavfhvMZJ9nbzrzKR0OXBz-BRdtc5S0HSy3F8DHSyvThWlzHSFugNkfArCxFiinA3Q&usqp=CAU"></td>
    <td><img width="200" src="https://user-images.githubusercontent.com/47862856/179076572-7600071d-fcbd-44fe-8d71-bb4129967a6e.png"></td>
  </tr>
</table>



This Arduino project combines **flame detection** with **Bluetooth remote control** to build a smart fire-response vehicle. It monitors for flames and responds automatically, while also allowing manual control via Bluetooth.

---

## 📚 Features
- **Flame Sensor**: Detects fire and triggers a relay (for example, activating a water pump or alert system).
- **Motor Control**: Moves forward, backward, and steers via servo motor.
- **Bluetooth Commands**: Remote control with commands sent via Bluetooth (e.g., HC-05/06 module).
- **LED Lights**: Two LEDs can be toggled remotely.

---

## 🛠 Hardware Requirements
- Arduino Uno (or compatible)
- Flame sensor (digital output)
- Relay module (to control water pump or buzzer)
- L298N motor driver (or equivalent)
- Servo motor (for steering)
- Two DC motors (for driving)
- Bluetooth module (HC-05 or HC-06)
- 2 LEDs for lighting
- Jumper wires and breadboard

---

## 🔌 Pin Connections
| Component      | Pin          |
|----------------|--------------|
| Flame Sensor   | 10 (Digital) |
| Relay          | 11 (Digital) |
| Servo Motor    | 2 (PWM)      |
| Motor Driver ENA | 3 (PWM)    |
| Motor Driver IN1 | 5 (Digital) |
| Motor Driver IN2 | 6 (Digital) |
| Light 1 (LED)  | 12 (Digital) |
| Light 2 (LED)  | 13 (Digital) |
| Bluetooth RX/TX | Serial Pins |

---

## 🚀 How It Works
1. **Flame Detection**:
   - Every **500 ms**, the flame sensor checks for fire.
   - If fire is detected, it triggers the relay.

2. **Bluetooth Control**:
   - Every **50 ms**, the Arduino checks for Bluetooth commands.
   - Commands include:
     - `F`: Move Forward
     - `B`: Move Backward
     - `f`/`b`: Stop
     - `L`/`l`: Turn Left/Mid
     - `R`/`r`: Turn Right/Mid
     - `U`/`u`: Light1 On/Off
     - `V`/`v`: Light2 On/Off

3. **Servo Steering & Motor Control**:
   - Servo angles: Left (60°), Mid (90°), Right (120°).
   - Motor control with PWM speed (`vSpeed`).

---

## 🖥️ Code Highlights
- **Non-blocking timing** using `millis()`:
  - `flameInterval = 500 ms`
  - `btInterval = 50 ms`
- Organized functions for motor and servo control.
- Responsive Bluetooth communication.

---

## 📱 Bluetooth Commands
| Command | Action           |
|---------|-------------------|
| `F`     | Move Forward      |
| `B`     | Move Backward     |
| `f`/`b` | Stop              |
| `L`     | Turn Left         |
| `l`     | Turn Mid (Reset)  |
| `R`     | Turn Right        |
| `r`     | Turn Mid (Reset)  |
| `U`     | Light1 On         |
| `u`     | Light1 Off        |
| `V`     | Light2 On         |
| `v`     | Light2 Off        |

---

## 🔥 Future Improvements
- Add obstacle avoidance with ultrasonic sensors.
- Implement auto-extinguish logic with flame direction tracking.
- Integrate battery monitoring.

---

## 📦 How to Use
1. Connect components as per the pinout.
2. Upload the Arduino code.
3. Pair Bluetooth module with your phone.
4. Use a serial Bluetooth app to send commands.
5. Observe automatic flame detection and manual control.

---

## 📝 License
This project is open-source under the MIT License.

---

Happy Building! 🚀


