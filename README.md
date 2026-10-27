# ⌨️ ESP32-C3 BLE MacroPad with OLED Display

![Project Status](https://img.shields.io/badge/Status-In%20Development-orange)
![Microcontroller](https://img.shields.io/badge/Microcontroller-ESP32--C3-blue)
![Programming](https://img.shields.io/badge/Language-C%2B%2B-green)
![Platform](https://img.shields.io/badge/Platform-Arduino_IDE-teal)
![Connectivity](https://img.shields.io/badge/Connectivity-Bluetooth_LE-purple)

## 🚀 Project Overview

The **ESP32-C3 BLE MacroPad** is a compact, customizable wireless keyboard accessory designed to improve productivity by allowing users to perform frequently used computer shortcuts with a single button press.

The project uses an **ESP32-C3 SuperMini microcontroller**, a **0.96-inch OLED display**, and **four mechanical keyboard switches**.

Each mechanical switch is assigned a specific keyboard shortcut, such as copying text, pasting text, opening the Windows Run dialog, or refreshing a page.

The OLED display provides visual feedback by displaying the name of the selected action.

The project is being developed using the Arduino IDE and C++, with Bluetooth Low Energy (BLE) keyboard functionality.

The final goal is to create a fully functional, portable macro pad assembled on a compact Zero PCB.

---

## ✨ Features

- ⌨️ Four programmable mechanical keyboard switches.
- 📡 Bluetooth Low Energy keyboard functionality (under development).
- 🖥️ 0.96-inch OLED display for visual feedback.
- ⚡ ESP32-C3 SuperMini microcontroller.
- 🔧 Customizable keyboard shortcuts.
- 💻 Designed for Windows computers.
- 📦 Compact and portable hardware design.
- 🛠️ Arduino IDE programming.
- 🔌 Permanent Zero PCB assembly planned.
- 🚀 Expandable firmware for additional features.

---

## 🧰 Components Required

| Component | Quantity | Description |
|---|---:|---|
| ESP32-C3 SuperMini | 1 | Main microcontroller |
| 0.96-inch OLED Display | 1 | SSD1306 I2C display |
| Mechanical Keyboard Switches | 4 | Two-terminal switches |
| Zero PCB | 1 | 27 × 18-hole perfboard |
| Connecting Wires | As required | Electrical connections |
| USB Cable | 1 | Programming and power |
| Pin Headers | As required | Component mounting |

A detailed bill of materials is available in `BOM.csv` once completed.

---

## 🔌 Circuit Connections

### OLED Display Connections

The OLED display communicates with the ESP32-C3 using the I2C protocol.

| OLED Pin | ESP32-C3 Pin |
|---|---|
| GND | GND |
| VCC | 3V3 |
| SDA | GPIO8 |
| SCL | GPIO9 |

### Mechanical Switch Connections

Each mechanical switch is connected between its assigned GPIO pin and GND.

| Switch | ESP32-C3 Pin | Function |
|---|---|---|
| Switch 1 | GPIO0 → GND | Copy |
| Switch 2 | GPIO1 → GND | Paste |
| Switch 3 | GPIO3 → GND | Windows Run |
| Switch 4 | GPIO6 → GND | Refresh |

The switches use the ESP32-C3's internal pull-up resistors.

When a switch is pressed, its GPIO pin is connected to GND, allowing the microcontroller to detect the button press.

---

## ⌨️ Keyboard Shortcut Configuration

| Button | Shortcut | Action |
|---|---|---|
| Button 1 | Ctrl + C | Copy selected text |
| Button 2 | Ctrl + V | Paste copied text |
| Button 3 | Windows + R | Open Windows Run |
| Button 4 | F5 | Refresh |

These shortcuts are intended to be transmitted to the computer using Bluetooth Low Energy.

The OLED display shows the corresponding action whenever a button is pressed.

---

## 🖥️ OLED Display

The project uses a 128 × 64-pixel SSD1306 OLED display.

The OLED provides a simple user interface.

### Example Display

```text
+--------------------+
|                    |
|     MACROPAD       |
|                    |
|   Button Pressed   |
|                    |
|       COPY         |
|                    |
+--------------------+
```

The display updates depending on which mechanical switch is pressed.

### Display States

- Welcome screen
- Button 1: COPY
- Button 2: PASTE
- Button 3: RUN
- Button 4: REFRESH

---

## 🧪 Hardware Testing

Before integrating the complete Bluetooth keyboard functionality, I tested the OLED display and mechanical switches.

### OLED Testing

The SSD1306 display was successfully initialized using the Adafruit SSD1306 library.

Text was displayed correctly on the screen.

### Button Testing

All four button inputs were tested using Arduino code.

When a button was pressed:

1. The ESP32-C3 detected the input.
2. The OLED displayed the corresponding button number.
3. The Serial Monitor displayed button information.

These tests confirmed that the basic input and display hardware worked.

---

## 📡 Bluetooth Keyboard Development

The ESP32-C3 supports Bluetooth Low Energy, allowing it to communicate with compatible devices.

The macro pad is intended to act as a BLE keyboard.

When a mechanical switch is pressed, the ESP32-C3 should send the assigned keyboard shortcut to the connected computer.

### Development Challenges

During development, I encountered several issues involving BLE keyboard libraries.

Some problems included:

- Library compatibility errors.
- Missing C++ header definitions.
- Conflicting BLE keyboard libraries.
- Compilation errors involving `std::function`.
- Bluetooth connectivity without successful keyboard input.

These issues are being investigated and resolved during development.

**Current status:** OLED and button testing succeeded. Complete BLE shortcut functionality still requires final verification.

---

## 💻 Firmware

The firmware is written in C++ using the Arduino IDE.

### Required Libraries

- Wire
- Adafruit GFX Library
- Adafruit SSD1306
- A compatible ESP32-C3 BLE keyboard library

### Firmware Location

```text
Firmware/
└── macropad.ino
```

### Uploading the Firmware

1. Install Arduino IDE.
2. Install ESP32 board support by Espressif Systems.
3. Connect the ESP32-C3 SuperMini using a USB cable.
4. Select the appropriate ESP32-C3 board and COM port.
5. Install the required libraries.
6. Open `Firmware/macropad.ino`.
7. Verify the sketch.
8. Upload the firmware.

BLE library compatibility must be confirmed before using the complete keyboard functionality.

---

## 🔧 Zero PCB Design

The final macro pad is planned to be assembled on a Zero PCB.

### Board Dimensions

**27 holes × 18 holes**

Total available holes:

**486**

The board will contain:

- ESP32-C3 SuperMini
- OLED display connections
- Four mechanical keyboard switches
- Power connections
- Ground connections
- GPIO signal connections

### Front View

The front side contains the electronic components.

### Back View

The back side contains the solder joints and electrical connections.

Because soldering is performed from the opposite side, the back-view layout must be mirrored relative to the front view.

The physical layout and component pin positions must be verified before soldering.

---

## 📸 Project Images

The following image paths are reserved for actual project photographs and verified design screenshots.

### Hardware Prototype

![Hardware Prototype](Images/prototype.jpg)

### Complete 3D Assembly

![Complete Assembly](Images/full-assembly.png)

### PCB Layout

![PCB Layout](Images/pcb-layout.png)

### Wiring Diagram

![Wiring Diagram](Images/wiring-diagram.png)

**Note:** These images must be uploaded to the `Images` folder before the links will display correctly. The 3D assembly and PCB design are planned deliverables.

---

## 📅 Development Journal

The project development journal covers the period from **21 October 2026 to 25 October 2026**.

The journal documents:

- Project planning
- Component selection
- Hardware wiring
- OLED testing
- Mechanical switch testing
- BLE keyboard development
- Library troubleshooting
- Zero PCB planning

Read the complete development journal in:

**[JOURNAL.md](JOURNAL.md)**

The journal should include actual progress, development screenshots, and photographs.

---

## 📁 Repository Structure

```text
ESP32-C3-MacroPad/
│
├── README.md
├── JOURNAL.md
├── BOM.csv
│
├── Firmware/
│   └── macropad.ino


---

## 🚧 Current Project Status

| Feature | Status |
|---|---|
| Project planning | ✅ Completed |
| Component selection | ✅ Completed |
| OLED testing | ✅ Completed |
| Mechanical switch testing | ✅ Completed |
| Keyboard shortcut assignments | ✅ Planned |
| BLE keyboard integration | 🔄 In progress |
| Zero PCB layout planning | 🔄 In progress |
| Permanent soldering | ⏳ Pending |
| Complete 3D CAD assembly | ⏳ Pending |
| PCB schematic and layout | ⏳ Pending |
| Final hardware testing | ⏳ Pending |

---

## 🔮 Future Improvements

I plan to improve this project by adding:

1. Fully functional Bluetooth keyboard shortcuts.
2. Customizable button assignments.
3. Improved OLED animations.
4. Battery-powered operation.
5. A custom-designed enclosure.
6. Additional keyboard shortcuts.
7. Better cable management.
8. A professionally designed PCB.

---

## 🎓 What I Learned

This project helped me learn about:

- ESP32-C3 microcontroller programming.
- Bluetooth Low Energy communication.
- I2C communication protocols.
- SSD1306 OLED displays.
- Mechanical switch interfacing.
- Internal pull-up resistors.
- Arduino IDE programming.
- C++ library debugging.
- Electronic circuit planning.
- Zero PCB assembly.
- GitHub project documentation.

---

## ❤️ Conclusion

The ESP32-C3 BLE MacroPad is a DIY electronics project combining hardware design, programming, and wireless communication.

The main objective is to create a compact and useful productivity tool capable of performing common computer shortcuts using four mechanical switches.

The OLED display provides visual feedback, while the ESP32-C3 handles button inputs and the planned BLE keyboard communication.

Although the complete device is still under development, the project has already provided valuable experience in electronics, programming, troubleshooting, and hardware design.

**Built with curiosity, creativity, and a passion for electronics! 🚀**

<img width="3000" height="4000" alt="1793103307446" src="https://github.com/user-attachments/assets/25539e73-cdde-4465-a0e1-e87509971d15" />
<img width="3000" height="4000" alt="1793103307492" src="https://github.com/user-attachments/assets/09f72dee-ed5b-449d-b5fc-62854e1f7c54" />
<img width="3000" height="4000" alt="1793103307514" src="https://github.com/user-attachments/assets/919a51ad-a4d6-4039-8b45-8b3a4577bde0" />


