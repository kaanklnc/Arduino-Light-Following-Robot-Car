Arduino Light-Following Robot Car

This project is a light-following autonomous robot built with Arduino, L298N motor driver, and dual digital LDR (Light Dependent Resistor) sensors.
The robot detects light direction and moves toward the brightest area using differential motor control.

🚗 Features

Follows light automatically

Stops when no light is detected

Turns toward the light smoothly

PWM-based speed control

Reliable digital LDR sensing (DO pins)

🧩 Hardware Used

Arduino Uno / Nano

L298N Motor Driver

2× DC Motors

2× Digital LDR Sensors (DO output)

2× Wheels + Chassis

Battery Pack (6–12V)

⚙️ Pin Configuration
Motor Driver (L298N)
Function	Pins
Left Motor	IN1=4, IN2=5, ENA=6
Right Motor	IN3=9, IN4=10, ENB=11
LDR Sensors
Sensor	Arduino Pin
Right LDR	D3
Left LDR	D2
🧠 Logic

Both sensors detect light (0/0) → Move forward

No light (1/1) → Stop

Light only left (0/1) → Turn left

Light only right (1/0) → Turn right

The LDR modules send LOW when detecting light and HIGH when dark.

📄 Code

Full code is included in main.ino.
