# RFID-Based Book Tracking System

This project is an RFID-based system designed to track and manage book placements on a designated rack. Each book contains a unique RFID tag, and the system verifies that each book is correctly placed in its assigned segment on the rack. The placement status is displayed on an LCD, indicating the correct or incorrect segment for each scanned book.

## Features

- RFID-based identification of books.
- LCD display showing the assigned rack, row, and segment for each book.
- Serial output for monitoring book placements.
- Expandable system to support additional racks, rows, and segments.

## Hardware Requirements

- Arduino-compatible board
- MFRC522 RFID Reader Module
- I2C LCD (16x2)
- RFID tags
- Jumper wires and breadboard

## Installation Guide

### Step 1: Set up the Arduino Environment

1. Download and install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).
2. Connect the Arduino board to your computer and install the necessary drivers if prompted.

### Step 2: Install Required Libraries

In the Arduino IDE, go to **Sketch > Include Library > Manage Libraries** and search for the following libraries. Install each one:

- **MFRC522**: For interfacing with the RFID reader.
- **LiquidCrystal_I2C**: For controlling the I2C LCD display.

### Step 3: Upload the Code

1. Copy the project code (provided in `rfid_book_tracking.ino`) to your Arduino IDE.
2. Connect your hardware as per the circuit diagram in the `Schematics` section below.
3. Upload the code to your Arduino by selecting **Upload**.

### Circuit Diagram

To set up the hardware, follow these connections:

- **MFRC522 RFID Module**:
  - SS to Pin 10 on Arduino
  - RST to Pin 9 on Arduino
  - MOSI to Pin 11
  - MISO to Pin 12
  - SCK to Pin 13
  - GND to Ground
  - VCC to 3.3V
  
- **I2C LCD**:
  - SDA to SDA on Arduino
  - SCL to SCL on Arduino
  - VCC to 5V
  - GND to Ground

## Usage

1. **Power on the system** with all components connected.
2. **Place a book with an RFID tag** near the RFID reader.
3. **View placement details** on the LCD, which displays the rack, row, and segment for each book.
4. The LCD will display "Unknown ID" if an unregistered tag is scanned.
5. Use the serial monitor to see additional debug information on book placements.

## License

This project is licensed under the MIT License. Feel free to modify and distribute as needed.
