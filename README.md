# 📡 STM32 Communication Protocols

## 🔥 Overview

This repository contains implementation of **STM32 communication protocols** including **SPI, UART, and I2C**. Each protocol is developed using bare-metal programming and tested using Proteus simulation and/or hardware peripherals.

The goal of this project is to understand how STM32 communicates with external devices using standard embedded communication protocols.

---

# 🧠 Protocols Implemented

## 📡 1. SPI (Serial Peripheral Interface)

### 🔹 Project: MCP3008 ADC + LCD Display

This project demonstrates SPI communication between STM32 and MCP3008 ADC to read analog sensor data and display it on a 16x2 LCD.

### 🔄 Working Flow:

```text id="spi_flow"
Potentiometer → MCP3008 (SPI ADC) → STM32 → LCD Display
```

### 📌 Features:

* SPI master communication (STM32)
* Analog to digital conversion using MCP3008
* Real-time LCD display output
* Proteus simulation support

STM32F103C8T6
MCP3008 ADC
16x2 LCD Display

---

## 📡 2. UART (Universal Asynchronous Receiver Transmitter)

### 🔹 Project: UART TX and RX Communication

This project demonstrates serial communication between STM32 and PC using UART protocol.

### 🔄 Working Flow:

```text id="uart_flow"
STM32 TX → PC (Virtual Terminal)
PC → STM32 RX
```

### 📌 Features:

* UART transmission (TX)
* UART reception (RX)
* Serial debugging using Virtual Terminal
* Real-time data exchange

### 🎯 Applications:

* Serial communication between devices
* Debugging embedded systems
* Data logging and monitoring

---

## 🔌 3. I2C (Inter-Integrated Circuit)

### 🔹 Project: DS1307 RTC + LCD Display

This project uses I2C communication to interface STM32 with DS1307 real-time clock module and display time/date on LCD.

### 🔄 Working Flow:

```text id="i2c_flow"
DS1307 RTC → I2C → STM32 → LCD Display
```

### 📌 Features:

* I2C communication protocol
* Real-time clock (DS1307)
* LCD display output
* Time and date tracking system

DS1307 RTC Module
16x2 LCD Display

---

# 📂 Repository Structure

```text id="structure"
STM32-Communication-Protocols/
│
├── SPI/
│   └── MCP3008_ADC_LCD/
│
├── UART/
│   ├── UART_TX/
│   └── UART_RX/
│
├── I2C/
│   └── DS1307_RTC_LCD/
│
└── README.md
```

---

# ⚙️ Tools Used

* STM32F103C8T6 microcontroller
* Keil uVision IDE
* Proteus Design Suite
* Virtual Terminal (UART simulation)

---

# 🎯 Key Features

✔ SPI-based ADC interfacing
✔ UART serial communication (TX/RX)
✔ I2C-based RTC interfacing
✔ LCD display integration
✔ Bare-metal embedded programming
✔ Proteus simulation support

---

# 🧠 Learning Outcomes

After completing this repository, you will understand:

* SPI, UART, and I2C protocol working
* STM32 peripheral interfacing
* Real-time embedded system design
* Sensor data acquisition techniques
* Embedded firmware development

---

# 🚀 Applications

* Embedded systems development
* IoT sensor communication base
* Industrial automation systems
* Real-time monitoring systems
* Firmware engineering roles

---

# 👨‍💻 Author

Embedded Systems / ECE Student
Focused on STM32 firmware development and communication protocols

---

# 🔥 Final Note

This repository demonstrates **core embedded communication protocols used in real-world STM32 firmware development projects** and is suitable for **placement and academic evaluation**.

---
