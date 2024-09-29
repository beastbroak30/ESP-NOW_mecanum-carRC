# ESP-NOW_mecanum-carRC
# Mecanum Wheel Robot with Custom Library and ESP-NOW Remote Control

This project is a Mecanum wheel robot controlled by an ESP32-based remote. It uses ESP-NOW for communication between the robot and the remote. The project also includes a custom library (`mecmotor`) for controlling the motors through two L298N motor drivers. The remote uses two joysticks to control the movement and speed of the robot.

## Features

- **Mecanum wheels** for omnidirectional movement.
- **ESP-NOW** communication between the ESP32 robot and remote control.
- Custom **'mecmotor' library** for controlling motors with predefined pin configuration.
- **Remote control** with two joysticks for movement and speed adjustment.
- Full circuit diagrams for both the robot and the remote.

## Project Components

### Robot (ESP32)
- 4 Mecanum wheels powered by 4 DC motors.
- 2 L298N motor drivers for motor control.
- ESP32 microcontroller to handle movement logic and communication.
- Custom `mecmotor` library for easy control of Mecanum wheels.
  
### Remote Control (ESP32)
- 2 analog joysticks for controlling movement and speed.
- 1 potentiometer for speed adjustment.
- ESP32 microcontroller to send joystick data over ESP-NOW to the robot.

## Hardware Requirements

- **ESP32 x 2** (One for the robot, one for the remote)
- **Mecanum wheels x 4**
- **DC motors x 4**
- **L298N motor drivers x 2**
- **Joysticks x 2** (For remote control)
- **Potentiometer x 1** (For speed control)
- Various resistors, wires, and a breadboard.

## Software Requirements

- **Arduino IDE** (or PlatformIO)
- ESP32 board support package installed
- Custom `mecmotor` library (included in the repository)
- ESP-NOW communication library (built-in with ESP32 Arduino core)

## Custom `mecmotor` Library

The `mecmotor` library provides functions for controlling two L298N motor drivers with predefined pins. The library allows easy manipulation of the Mecanum wheels for forward, backward, strafe, and diagonal movements.

### Library Functions

```cpp
void forward(int speed);
void backward(int speed);
void strafeL(int speed);
void strafeR(int speed);
void left(int speed);
void right(int speed);
void pivotfl(int speed);
void pivotfr(int speed);
void pivotbl(int speed);
void pivotbr(int speed);
```

## Circuit Diagrams

### Robot Circuit

![Robot Circuit Diagram](https://res.cloudinary.com/dccbfaydp/image/upload/b64ifizufgucxbh4ubnm.jpg)

### Remote Control Circuit

![Remote Circuit Diagram](https://res.cloudinary.com/dccbfaydp/image/upload/gtwbm1q8bhn3mhxqwn4s.jpg)

## Installation

### Dependencies
Add the `mecmotor` library to your Arduino libraries folder. To do this, copy the `mecmotor` folder into the libraries folder of your Arduino IDE.

Ensure the ESP32 board is set up in Arduino IDE. If not, follow these instructions to install it.

## Wiring Setup
Follow the circuit diagrams provided above to connect your robot and remote components to the ESP32.

## Upload the Code
- Upload the `robot.ino` file to the ESP32 that controls the Mecanum wheels.
- Upload the `remote.ino` file to the ESP32 used for the remote control.

## Power Up the Hardware
- Power the robot's ESP32 and motors using a power supply (e.g., a battery pack).
- Power the remote control's ESP32 using a separate power source (e.g., USB or battery).

## Test the Setup
Use the joysticks on the remote to control the robot's movement. The robot should move in all directions according to the joystick inputs (forward, backward, left, right, diagonal, and rotational movement).

## Example Usage
Here's a sample code snippet showing how to use the `mecmotor` library to control the Mecanum wheels.

```cpp
#include <mecmotor.h>

// Motor setup and pin configuration
MecMotor mec(12, 13, 14, 15); // Example pin configuration

void setup() {
  mec.begin();
}

void loop() {
  mec.forward(255);  // Full speed forward
  delay(1000);       // Wait for 1 second
  mec.strafeLeft(150);  // Strafe left at medium speed
  delay(1000);       // Wait for 1 second
}
