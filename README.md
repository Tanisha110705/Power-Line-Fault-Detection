# Low-Cost Embedded System for Electrical Fault Detection and Physical Anomaly Monitoring in Power Lines

## Overview

This project is an affordable embedded system which is developed to monitor and detect faults in power transmission lines.

Conventional electrical fault detection systems can be costly and complicated as well as not suitable for laboratory use. This project is an affordable prototype which makes use of the Arduino Uno as the central embedded controller.

This system has been built through:

- Electrical current measurement by an ACS712 current sensor 
- Proximity measurement by an HC-SR04 ultrasonic sensor 
- Real time status monitoring by 16×2 I2C LCD
- LED based fault identification
- Serial Communication for data monitoring and analysis 
- Real time visualization in MATLAB 
- Vision analysis through machine learning using YOLOv8

The embedded prototype will classify the monitored system into three categories:

- NORMAL 
- OPEN CIRCUIT 
- OVERCURRENT
- OBSTACLE

The project also explores vision-based person detection to provide an additional layer of physical hazard monitoring.

---

#  Objectives

The key goals of this project include:

1. Identification of electrical overcurrent faults.
2. Identification of open circuit faults.
3. Detection of physical proximity to the monitored power-line prototype.
4. Identification of obstacles in the vicinity of the prototype with an ultrasonic sensor.
5. Real-time display of system parameters and fault conditions.
6. Minimization of measurement errors via averaging and filtering of sensor values.
7. Visual identification of faults.
8. Transmission of the sensors’ measurements through serial interface.
9. Visualization of sensors' values via MATLAB.
10. Integration of machine learning-based object recognition with YOLOv8 algorithm.
11. Design of an affordable and safe prototype suitable for educational purposes.

---

#  System Architecture

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
