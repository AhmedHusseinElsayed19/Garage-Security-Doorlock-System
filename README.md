# Garage Security Doorlock System 🚗🔐

## 📄 About the Project

This project is part of the graduation internship at **Arab Academy for Science, Technology & Maritime Transport (AAST)** in collaboration with **Valeo Egypt**.

It implements a secure **garage door locking system** using an embedded microcontroller and a keypad interface to authenticate users before granting access.

---

## 🔧 Features

- 3-attempt password entry system.
- Password confirmation via pressing the **'C' key**.
- Ability to clear digits before entering the 4th digit using the **'C' key**.
- Two types of access:
  - **Normal User**: `1111`
  - **Admin**: `2112`

> ⚠️ **Important:** Pressing any key other than **'C'** after a failed attempt will be counted as an incorrect trial and may lock the system after 3 failures.

---

## 🧰 Hardware Used

- **Microcontroller**: AVR ATmega32
- **LCD Display**: 16x2 LCD (I2C or standard interface)
- **Keypad**: 4x4 Matrix Keypad
- **Communication Interfaces**:
  - SPI
  - I2C
  - UART

---

## 💻 Software Tools

- Atmel Studio 7
- Proteus (for simulation)
- Embedded C

---


## 🛠️ How to Use

1. Power up the system.
2. Enter your 4-digit password using the keypad.
3. Press the **'C'** key to confirm.
   - If correct, access is granted.
   - If incorrect, two more trials remain.
4. You can press **'C'** at any time *before* entering the fourth digit to clear and re-enter the password.
5. After 3 incorrect attempts, the system locks and displays an error message.

---

## 🎓 Acknowledgment

This project was developed during the internship program at **AAST & Valeo Egypt** as part of the graduation requirements for Electrical & Electronics Engineering.
