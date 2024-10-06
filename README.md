# Digital-Goniometer-with-Arduino-and-MATLAB
A digital goniometer project using Arduino and MATLAB to measure joint angles, calculate angular velocity and acceleration, and display real-time data.

## Features

- **Angle Measurement:** Uses a potentiometer to measure angles from 0° to 270°.
- **Parameter Calculation:** Calculates angular velocity and acceleration based on the data.
- **Graphical Interface:** Displays real-time data using MATLAB.
- **Motor Control:** Adjusts a DC motor based on the potentiometer's position.
- **Adjustable Mount:** An armband to attach the potentiometer to the joint for evaluation.

## Installation

### Requirements

- **Hardware:**
  - Arduino UNO
  - 10kΩ potentiometer
  - 5V DC motor
  - H-Bridge (4 TIP31C transistors, 4 resistors of 1kΩ)
  [H-Bridge Circuit](images/HBridge.png)
  - Breadboard and connecting wires
  - 9V battery
  - Materials for the armband (straps, arm sleeve, insulating tape)

- **Software:**
  - [Arduino IDE](https://www.arduino.cc/en/software)
  - [MATLAB](https://www.mathworks.com/) (version 2014a or later)

[Example](images/goniometer.png)

## Credits

- Oscar Iván Hernández Gómez
- José Rodrigo Quintero Valdez
- Victor Manuel Mariscal Cervantes
- Yaisiri Monserrat Hernández León
