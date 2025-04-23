# Calculator 2
### By: Diego J. Graham

## 📋 Description

**Calculator 2** is an Arduino-based project that uses a membrane keypad for user input and an LCD to display the calculation. The calculator can **add, subtract, multiply, and divide** two integers, and it displays the result as a **float**. It also includes a **buzzer** for audible feedback on button presses.

---

## 🔧 Features

- Accepts input via a 4x4 membrane keypad.
- Displays real-time input and output on a 16x2 LCD.
- Supports basic operations: `+`, `-`, `*`, and `/`.
- Automatically evaluates the expression when `=` is pressed.
- `C` button clears all inputs.
- Built-in buzzer beeps with every keypress.
- Handles division-by-zero errors gracefully by displaying "ERROR".

---

## 🧠 How It Works

- The user enters the **first number**.
- The user then presses an **operator** (`+`, `-`, `*`, `/`).
- The user enters the **second number**.
- Pressing `=` evaluates the expression.
- Pressing `C` clears the input and resets the calculator.

---

## 🔌 Components Used

- Arduino (Uno or compatible board)
- 4x4 Membrane Keypad
- 16x2 LCD Display
- Piezo Buzzer
- Jumper Wires
- Breadboard

---

## 📐 Schematic

A complete schematic is included in the repository under the filename:


---

## ✅ Getting Started

1. Clone the repository.
2. Open `Calculator2.ino` in the Arduino IDE.
3. Connect the components as shown in the schematic.
4. Upload the sketch to your Arduino board.
5. Use the keypad to input and calculate!

---

## 💬 Notes

- The result is always displayed as a float (e.g., `4.00`).
- Make sure your keypad wiring matches the `rowPins` and `colPins` defined in the code.
- LCD must be initialized using pins `7, 8, 9, 10, 11, 12`.

---

## 🚀 Future Improvements

- Add decimal support for more precise inputs.
- Improve input validation (e.g., multiple operators).
- Add support for chained calculations.

---

## 📜 License

This project is open source and free to use with credit.

---

