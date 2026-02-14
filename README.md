# I2C Byte Write to LCD using 24AA256 with SPI Debugger

## 📌 Project Description
This project demonstrates I2C byte write communication using a PIC microcontroller, 
24AA256 EEPROM, and an LCD display. The PIC acts as the I2C master and writes a 
single byte of data into the EEPROM memory. The stored data is then read back 
and displayed on the LCD.

An SPI debugger (logic analyzer) is used to monitor SDA and SCL signals to verify 
proper I2C communication.

---

## 🔧 Components Used
- PIC Microcontroller (Example: PIC16F877A)
- 24AA256 I2C EEPROM
- 16x2 LCD
- 4.7kΩ Pull-up Resistors (SDA & SCL)
- SPI Debugger / Logic Analyzer
- 5V Power Supply

---

## 🔁 I2C Byte Write Sequence
1. Start Condition
2. Send Slave Address + Write Bit
3. Send Memory Address
4. Send Data Byte
5. Stop Condition

Each byte is followed by an ACK from the EEPROM.

---

## ⚙️ Working Principle
- PIC initializes I2C using MSSP module.
- Master sends device address (0xA0 for write).
- Memory location address is transmitted.
- Data byte is written into EEPROM.
- Data is read back and displayed on LCD.
- SPI debugger monitors SDA and SCL signals.

---


## 🎯 Learning Outcomes
- Understanding I2C protocol
- EEPROM byte write operation
- LCD interfacing
- Debugging serial communication using SPI debugger
