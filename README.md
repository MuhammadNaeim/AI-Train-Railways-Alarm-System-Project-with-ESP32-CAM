![train railways](https://github.com/MuhammadNaeim/Train-Railways-Alarm-System-Project-with-ESP32-CAM/assets/74180779/dd561cf0-4a51-41ab-a4c4-dd237c148f45)
# Train-Railways-Alarm-System-Project-with-ESP32-CAM
## This is my project for the second communications engineering year. throughout this article I'll walk you through the system and the components and how they work together.
![design](https://github.com/MuhammadNaeim/Train-Railways-Alarm-System-Project-with-ESP32-CAM/assets/74180779/0ee69485-b88e-40dd-bec9-69bf39798e2d)

**When I started working on this project, I created this design based on my imagination which my teammates and I managed to bring to life.
## The components used:
- 3 Ultrasonic sensors
- 2 Hall Effect sensors
- 2 Servo motors
- 2 Servo Linear Actuator (3d printed)
- ESP32-CAM Board
- FTDI Module
- LDR sensor
- LEDs & Buzzers
- Magnets
- Working Mechanism (the system)
### This design has 4 mechanisms to maintain passengers' safety
1. The 2 gates on the railway (represented by no. 2&3): each one carries an Ultrasonic sensor to initiate the alarm system to alert the passenger whether at the station or on the road that the train is coming whenever it passes through them.
2. The 2 Hall Effect sensors: they are placed before and after the road to close the road gate which is controlled by a Servo motor (represented by no. 5) to prevent vehicles from crossing over the railway whenever the train is passing. and opens after it has passed.

![train railways5](https://github.com/MuhammadNaeim/Train-Railways-Alarm-System-Project-with-ESP32-CAM/assets/74180779/9eb24171-8c2b-421f-b4d2-577cac2b1226)

3. The Servo motor (represented by no. 6): controls the station block (represented by no. 8) to prevent passengers from falling or going down the station. we used a 3D-printed servo linear actuator to convert the rotary motion of the Servo into a linear motion. so whenever the train is detected by the Ultrasonic (represented by no. 1) the block goes down to allow passengers to enter the train, otherwise, it stays up to keep them safe.

![train railways2](https://github.com/MuhammadNaeim/Train-Railways-Alarm-System-Project-with-ESP32-CAM/assets/74180779/988aef53-7213-469d-9e68-ec74d0de9546)

4. The ESP32-CAM (represented by no. 7): runs an object detection program to detect objects on the railway, so when it detects a human when the train is coming, it initiates the alarm system.

- The LDR sensor detects the sunlight, so it lights up station lights when the sun goes down.
