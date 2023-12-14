# Conveyor-Belt-Speed-Monitor 🏭

## Overview 📖
The Conveyor-Belt-Speed-Monitor is a practical Arduino-based project designed to measure and display the speed of a conveyor belt. Utilizing an encoder and an LCD display, this tool provides real-time monitoring of the belt's RPM and calculates its speed in meters per second and meters per minute.

## Features 🌟
- Real-time RPM measurement of conveyor belts.
- Calculates belt speed in both meters per second and meters per minute.
- Displays time to complete a fixed distance (e.g., 2.7 meters).
- Utilizes an LCD for clear, on-site display of measurements.

## Hardware Requirements 🔧
- Arduino Board
- Rotary Encoder
- LiquidCrystal I2C LCD Display
- Basic Wiring Components

## Software Dependencies 📚
- Wire Library
- LiquidCrystal_I2C Library

## Setup and Installation 🛠️
1. **Hardware Assembly:**
   - Connect the rotary encoder to the Arduino interrupt pin.
   - Wire the LCD display to the Arduino using I2C communication.
2. **Arduino Configuration:**
   - Set up your Arduino IDE with the required libraries.
3. **Code Deployment:**
   - Upload the provided sketch to your Arduino board.

## How It Works 🔍
- The encoder sends pulses corresponding to the movement of the conveyor belt.
- The Arduino calculates the RPM and converts it to belt speed.
- Every 3 seconds, the LCD updates to show the current speed and estimated time to cover a fixed distance.

## Usage 🔄
Ideal for industrial settings, this tool aids in monitoring conveyor belt speeds for efficiency, safety, and operational optimization.
