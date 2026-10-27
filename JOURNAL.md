# ESP32-C3 BLE MacroPad — Development Journal

**Project Name:** ESP32-C3 BLE MacroPad with OLED Display  
**Developer:** Hardik Purbia 
**Project Duration:** 21–25 October 2026  
**Platform:** ESP32-C3 SuperMini  
**Programming Language:** C++ (Arduino IDE)  
**Project Category:** Electronics, Embedded Systems, Bluetooth HID, DIY Hardware

---

# 📅 Day 1 — 21 October 2026
## Project Planning and Component Selection

### 🎯 Today's Goal
Plan and begin developing a compact, wireless macro pad capable of performing useful keyboard shortcuts on a Windows computer.

### 🛠️ Work Done
I started working on my DIY macro pad using an ESP32-C3 SuperMini microcontroller.

The main idea was to create a small keyboard accessory with four mechanical switches. Each switch would perform a different computer shortcut.

I selected an OLED display to show the name of the shortcut whenever a button was pressed.

### 🔧 Components Selected
- 1 × ESP32-C3 SuperMini
- 1 × 0.96-inch OLED display (128 × 64)
- 4 × Mechanical keyboard switches
- Jumper wires
- USB cable
- Arduino IDE

### 💡 Planned Features
1. Wireless Bluetooth keyboard functionality.
2. Four programmable shortcut buttons.
3. OLED display showing the selected action.
4. Compact and portable design.
5. Support for Windows keyboard shortcuts.

### 🧠 What I Learned
I learned that the ESP32-C3 supports Bluetooth Low Energy (BLE), which can be used to build wireless human interface devices such as keyboards.

I also learned about I2C communication and how an OLED display communicates with a microcontroller.

### ✅ Progress
Project concept, component selection, and initial pin planning completed.

---

# 📅 Day 2 — 22 October 2026
## Hardware Connections and OLED Testing

### 🎯 Today's Goal
Connect the OLED display and four mechanical switches to the ESP32-C3 and test their functionality.

### 🛠️ Work Done
I worked on the hardware connections for my macro pad.

The OLED display was connected using the I2C communication protocol.

I assigned four GPIO pins to the mechanical switches. Each switch was connected between its assigned GPIO pin and GND.

The internal pull-up resistors of the ESP32-C3 were used to detect button presses.

### 🔌 OLED Connections

| OLED Pin | ESP32-C3 Pin |
|---|---|
| GND | GND |
| VCC | 3V3 |
| SDA | GPIO8 |
| SCL | GPIO9 |

### 🔌 Mechanical Switch Connections

| Switch | ESP32-C3 Pin |
|---|---|
| Switch 1 | GPIO0 → GND |
| Switch 2 | GPIO1 → GND |
| Switch 3 | GPIO3 → GND |
| Switch 4 | GPIO6 → GND |

### 🧪 Testing
I tested the OLED display using the Adafruit SSD1306 library.

The display successfully showed text.

I also tested the four buttons using a simple Arduino sketch.

Whenever a button was pressed, the OLED displayed its corresponding button number.

The Serial Monitor was also used to verify button detection.

### 🧠 What I Learned
- How to communicate with an SSD1306 OLED display.
- How to configure custom I2C pins.
- How to use `INPUT_PULLUP` for push buttons.
- How to detect button presses using GPIO inputs.
- How to display changing information on an OLED screen.

### ✅ Progress
OLED and button input testing completed successfully.

---

# 📅 Day 3 — 23 October 2026
## Bluetooth Keyboard Programming

### 🎯 Today's Goal
Develop the software that allows the ESP32-C3 to work as a Bluetooth keyboard.

### 🛠️ Work Done
I started integrating Bluetooth Low Energy keyboard functionality into my macro pad.

The idea was to make the ESP32-C3 send keyboard shortcuts to a Windows computer whenever a mechanical switch was pressed.

I worked with BLE keyboard libraries and Arduino code.

### ⌨️ Planned Button Functions

| Button | Keyboard Shortcut | Action |
|---|---|---|
| Button 1 | Ctrl + C | Copy |
| Button 2 | Ctrl + V | Paste |
| Button 3 | Windows + R | Open Run |
| Button 4 | F5 | Refresh |

### 💻 Programming
I worked on integrating three major parts of the project:

1. Mechanical switch input detection.
2. OLED display updates.
3. Bluetooth keyboard commands.

The OLED was programmed to show the corresponding action when a button was pressed.

### ⚠️ Challenges
During development, I encountered compilation problems involving BLE keyboard libraries.

Some libraries were not fully compatible with my ESP32-C3 configuration.

I investigated the errors and compared different library options.

### 🧠 What I Learned
- Basics of Bluetooth HID devices.
- How BLE keyboards send keyboard commands.
- How Arduino libraries are installed and used.
- Why library compatibility matters.
- How to read Arduino compiler error messages.

### ✅ Progress
Keyboard shortcut logic developed; BLE library compatibility still required debugging.

---

# 📅 Day 4 — 24 October 2026
## Debugging and Software Improvements

### 🎯 Today's Goal
Troubleshoot BLE keyboard compilation problems and improve the macro pad software.

### 🛠️ Work Done
I continued working on the software side of my macro pad.

I encountered problems involving multiple BLE keyboard libraries installed in Arduino IDE.

Some compilation errors were related to missing C++ definitions and incompatible library versions.

One of the errors involved:

```cpp
std::function
```

The compiler indicated that the `<functional>` header was missing.

To investigate the issue, I opened the BLE keyboard library files using Visual Studio Code.

I identified the relevant header file:

```text
BleKeyboard.h
```

The proposed correction was to include:

```cpp
#include <functional>
```

I also reviewed the installed BLE keyboard libraries to identify possible conflicts.

### 🔍 Problems Investigated
- BLE library compatibility.
- Duplicate Arduino libraries.
- Missing C++ header definitions.
- ESP32-C3 Bluetooth keyboard compilation errors.
- Keyboard commands not being received despite Bluetooth connectivity.

### 🧠 What I Learned
I learned how to inspect Arduino library source files and understand compiler errors.

I also learned the difference between `.h` header files and `.cpp` source files.

This debugging process helped me understand how Arduino libraries work internally.

### ✅ Progress
Major software problems identified and troubleshooting steps prepared.

Further verification was required before considering the BLE keyboard functionality complete.

---

# 📅 Day 5 — 25 October 2026
## Zero PCB Layout and Final Hardware Planning

### 🎯 Today's Goal
Plan a permanent hardware layout for the macro pad using a Zero PCB instead of temporary jumper-wire connections.

### 🛠️ Work Done
I started planning the physical layout of the macro pad on a Zero PCB.

The purpose was to create a compact and permanent electronic circuit similar to a custom-manufactured PCB.

I selected a Zero PCB with the following dimensions:

**27 holes × 18 holes**

Total available holes:

**27 × 18 = 486 holes**

I planned the placement of the ESP32-C3 SuperMini, OLED display, and four mechanical keyboard switches.

### 🔧 Hardware Layout Planning
The design includes:

- ESP32-C3 SuperMini as the main controller.
- OLED display for visual feedback.
- Four mechanical switches for keyboard shortcuts.
- Power connections for the OLED.
- GPIO connections for button inputs.
- Common ground connections.

### 🔌 Final
