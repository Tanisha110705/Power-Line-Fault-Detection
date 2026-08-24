# Low-Cost Embedded System for Electrical Fault Detection and Physical Anomaly Monitoring in Power Lines

## 📌 Overview

This project presents a low-cost embedded system designed for real-time electrical fault detection and physical anomaly monitoring in power transmission lines.

Traditional electrical fault detection systems can be expensive, complex and unsuitable for educational laboratory environments. This project develops a low-cost prototype using an Arduino Uno as the central embedded controller.

The system combines:

- Electrical current monitoring using an ACS712 current sensor
- Physical proximity monitoring using an HC-SR04 ultrasonic sensor
- Real-time status display using a 16×2 I2C LCD
- LED-based fault indication
- Serial communication for data monitoring and analysis
- MATLAB-based real-time visualization
- Machine-learning-based vision analysis using YOLOv8

The embedded prototype classifies the monitored system into:

- NORMAL
- OPEN CIRCUIT
- OVERCURRENT
- OBSTACLE

The project also explores vision-based person detection to provide an additional layer of physical hazard monitoring.

---

# 🎯 Objectives

The main objectives of this project are:

1. Detect electrical overcurrent conditions.
2. Detect open-circuit conditions.
3. Monitor physical proximity around the monitored power-line prototype.
4. Detect nearby obstacles using an ultrasonic sensor.
5. Display system parameters and fault states in real time.
6. Reduce measurement noise through sensor averaging and filtering.
7. Provide visual fault indication.
8. Transfer sensor data through serial communication.
9. Visualize sensor data using MATLAB.
10. Integrate machine-learning-based object detection using YOLOv8.
11. Develop an affordable and safe prototype suitable for educational applications.

---

# 🏗️ System Architecture

```text
                         POWER-LINE
                         PROTOTYPE
                              │
                              ▼
                    ┌──────────────────┐
                    │  ACS712 Current  │
                    │      Sensor      │
                    └────────┬─────────┘
                             │
                             │ Analog
                             ▼
                    ┌──────────────────┐
                    │                  │
                    │   ARDUINO UNO    │
                    │                  │
                    │ Fault Detection  │
                    │ Signal Processing│
                    └───────┬──────────┘
                            │
              ┌─────────────┼─────────────┐
              │             │             │
              ▼             ▼             ▼
          HC-SR04        16×2 LCD        LED
       Ultrasonic        Display       Indicator
          Sensor
              │
              ▼
       Distance Measurement

                    Arduino Serial
                           │
                           ▼
                       MATLAB
                           │
                           ▼
                  Data Visualization


                         CAMERA
                           │
                           ▼
                         YOLOv8
                           │
                           ▼
                   Object Detection
                           │
                           ▼
                  Person Detection
                           │
                           ▼
               "DANGER: PERSON DETECTED"
