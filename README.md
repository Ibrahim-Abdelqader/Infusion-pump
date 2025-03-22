# Fluid Flow Control & Monitoring System 💧  

![Image](https://github.com/user-attachments/assets/092e6a33-489a-420c-b7c5-94748cf17c35)

<img src="https://github.com/user-attachments/assets/74a89fc4-ddc7-44c1-8fde-d24d625044af" alt="Flow Control Demo" width="250" />  
<img src="https://github.com/user-attachments/assets/dcf29b05-12b0-4451-a113-fb090d97c7eb" alt="Flow Control Demo" width="250" />  
<img src="https://github.com/user-attachments/assets/3c376a1f-1283-4e38-a57c-5abc3e8c59de" alt="Flow Control Demo" width="250" />  

**Arduino-based system to monitor and control fluid flow using a flow sensor, pump, and LCD display.**  
*(Developed for "Embedded Systems Project")*  

---  

## 📋 Table of Contents  
- [📝 Overview](#-overview)  
- [🌟 Features](#-features)  
- [🛠️ Components](#-components)  
- [🔧 Setup](#-setup)  
- [🔌 Circuit Diagram](#-circuit-diagram)  
- [🎮 Usage](#-usage)  
- [📊 Project Goals](#-project-goals)  
- [👥 Team Roles](#-team-roles)  
- [📜 License](#-license)  

---  

## 📝 Overview  
This project implements a **fluid flow control and monitoring system** using an Arduino. It integrates a **YF-S401 flow sensor**, a **pump controlled via PWM mosfet transistor**, and an **I2C LCD** for real-time monitoring of flow rate and pump speed. The system also features a **potentiometer for speed adjustment**, a **buzzer for alerts**, and a **push button** for pausing the alert system.  

---  

## 🌟 Features  
- **Real-time Flow Monitoring**: Measures and displays the fluid flow rate.  
- **PWM-based Pump Control**: Adjusts speed based on user input.  
- **LCD Display**: Shows live data of flow rate and pump speed.  
- **User Interaction**: Adjust settings with a potentiometer and push button.  
- **Buzzer & Lamp Alerts**: Indicates flow irregularities or warnings.  

---  

## 🛠️ Components  
- Arduino board  
- YF-S401 flow sensor  
- TIP122 transistor (for pump control)  
- I2C LCD (16x2)  
- Potentiometer  
- Push button  
- Buzzer  
- LED or external lamp  
- Breadboard & jumper wires  

---  

## 🔧 Setup  
1. **Wire the Circuit**:  
   - **LCD**: `SDA → A4`, `SCL → A5`, `VCC → 5V`, `GND → GND`  
   - **Flow Sensor**: `Signal → D2`, `VCC → 5V`, `GND → GND`  
   - **Pump Control**: `PWM → D9`, `GND → GND`, `Power → External Source`  
   - **Buzzer**: `Pin 8`  
   - **Push Button**: `Pin 10` (with pull-up resistor)  
   
2. **Upload Code**:  
   - Install `LiquidCrystal_I2C` library.  
   - Upload `sketch_mar20b.ino` to Arduino.  

3. **Adjust Flow Rate**:  
   - Use the potentiometer to control pump speed.  

---  

## 🔌 Circuit Diagram  
![Image](https://github.com/user-attachments/assets/1c6ba3ab-a04e-4db7-a028-3cd283107b9f)
**⚠️ Not a completed circuit!**

---  

## 🎮 Usage  
- Adjust **pump speed** using the potentiometer.  
- Monitor **real-time flow rate** on the LCD.  
- Press the **push button** to pause the alert system.  
- The **buzzer/lamp** indicates any anomalies in the flow system.  

---  

## 📊 Project Goals  
This project aims to:  
✅ Monitor real-time fluid flow with a sensor.  
✅ Control pump speed dynamically using PWM.  
✅ Provide user interaction through an LCD and buttons.  
✅ Implement alert mechanisms for abnormal conditions.  

---  

## 👥 Team Roles  
| Member | Role | LinkedIn |  
|--------|------------------------------|----------------|  
| **Ibrahim Abdelkader** (Leader) | Hardware Setup & Integration | [LinkedIn](https://www.linkedin.com/in/ibrahim-abdelqader-93b9b124b/) |  
| **Mohamed Ehab** | Software Development & Testing | [LinkedIn](https://www.linkedin.com/in/mohamed-ehab-272394323/) |  
| **Menna Atef** | Project Design | [LinkedIn](https://www.linkedin.com/in/menna-atef-05355b32a/) |  
| **Nada Mostafa** | Documentation & Report Writing | [LinkedIn](https://www.linkedin.com/in/nada-mostafa-67853b324/) |  
| **Jana Nour** | Photographer & Presentation | [LinkedIn](https://www.linkedin.com/in/jana-nour-1510bb324/) |  

---  

## 📜 License  
Open-source under MIT License. Contribute & innovate! 🚀
