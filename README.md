# Digital Password Lock using PIC18F4580

## 📌 Project Overview

This project implements a **Digital Password Lock system** using the **PIC18F4580 microcontroller**.

The system allows the user to enter a 4-digit password using switches. The stored password is saved in the **internal EEPROM** of the PIC18F4580. The entered password is compared with the stored password, and the system indicates whether the password is correct or incorrect.

A **4-digit Seven Segment Display (SSD)** is used to interact with the user, and an LED indicates successful password entry.

## 🎯 Aim

To design and implement a simple digital password lock system using a PIC18F4580 microcontroller with password storage in internal EEPROM.

## 💡 Why I Developed This Project

The main purpose of this project was to understand how a microcontroller can interact with input switches, display devices, LEDs, and non-volatile memory.

It helped me learn how to:

* Interface switches with a microcontroller
* Control a 4-digit SSD
* Store and read data from internal EEPROM
* Compare user input with a stored password
* Control an LED based on the password result
* Develop a simple embedded control application

## 🔧 Hardware Used

* PIC18F4580 Microcontroller
* 4-Digit Seven Segment Display
* Digital Switches / Keypad
* LED
* Resistors
* Embedded development board

## 💻 Software / Tools Used

* Embedded C
* MPLAB X IDE
* XC8 Compiler
* PIC18F4580
* Microcontroller peripherals

## ⚙️ Working Principle

1. The system initializes the digital keypad, SSD, and LED.
2. A 4-digit password is stored in the PIC18F4580 internal EEPROM.
3. The stored password is read back from EEPROM.
4. The SSD initially displays `ENTR`, indicating that the user can enter a password.
5. The switches are used to select and enter each password digit.
6. After entering the password, the user presses the enter switch.
7. The entered password is compared with the password stored in EEPROM.
8. If the password matches:

   * SSD displays `PASS`
   * LED is turned ON
9. If the password does not match:

   * SSD displays `FAIL`
   * LED remains OFF
10. The system resets the display and waits for the next password entry.

## 🔐 Password Storage

For demonstration, the password used in the project is:

`1234`

The individual digits are stored in the internal EEPROM:

| EEPROM Address | Stored Data |
| -------------- | ----------: |
| `0x00`         |           1 |
| `0x01`         |           2 |
| `0x02`         |           3 |
| `0x03`         |           4 |

The values are then read from EEPROM and combined to form the password `1234`.

## 🎛️ Switch Functions

| Switch  | Function                         |
| ------- | -------------------------------- |
| SWITCH1 | Change/select the password digit |
| SWITCH2 | Move to the next digit           |
| SWITCH3 | Enter and verify the password    |
| SWITCH4 | Clear/reset the entered digits   |

## 🖥️ SSD Indications

The 4-digit SSD displays different messages depending on the system state:

* `ENTR` → Waiting for password entry
* `PASS` → Correct password
* `FAIL` → Incorrect password
* `0000` → Clear/reset indication

## 📂 Project Structure

```text
Digital-Password-Lock-PIC18F4580/
│
├── Digital_Password_lock.X/
│   ├── main.c
│   ├── digital_keypad.c
│   ├── digital_keypad.h
│   ├── ssd_display.c
│   ├── ssd_display.h
│   ├── eeprom.c
│   ├── eeprom.h
│   └── Makefile
│
├── README.md
└── .gitignore
```

## 📚 Concepts Learned

* PIC18F4580 microcontroller programming
* Embedded C programming
* GPIO configuration
* Digital keypad/switch interfacing
* Seven Segment Display interfacing
* SSD multiplexing
* Internal EEPROM read/write operations
* Bit-level register configuration
* Password comparison logic
* Basic embedded system design

## 🚀 Future Improvements

* Allow the user to change the password
* Hide the password while entering it
* Add a buzzer for incorrect password attempts
* Add a maximum retry limit
* Implement a lockout period after multiple incorrect attempts
* Improve SSD refresh using a timer/interrupt instead of delay loops

## 👨‍💻 Project Type

**Embedded Systems | Microcontroller | Embedded C**

**Microcontroller:** PIC18F4580
**Language:** Embedded C
**IDE:** MPLAB X
**Compiler:** XC8

