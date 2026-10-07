# Power Line Fault Detection

A low-cost embedded prototype for electrical fault detection and physical anomaly monitoring.

## Overview

The system combines current sensing, proximity sensing, a display, serial monitoring, MATLAB visualization, and a YOLOv8-based vision module.

The prototype classifies the monitored setup into:

- Normal
- Open circuit
- Overcurrent
- Obstacle

## System Architecture

ACS712 Current Sensor + HC-SR04 Sensor → Arduino Uno → LCD / LED Status / Serial Data → MATLAB

Camera → YOLOv8 → Person Detection

## Hardware

| Component | Purpose |
|---|---|
| Arduino Uno | Main controller |
| ACS712 | Current measurement |
| HC-SR04 | Proximity measurement |
| 16×2 I2C LCD | Status display |
| LED | Fault indication |
| Camera | Vision-based monitoring |

## Fault Detection

The prototype uses calibrated thresholds to classify operating conditions.

| Condition | Detection |
|---|---|
| OBSTACLE | Distance ≤ 15 cm |
| OPEN CIRCUIT | Current < 0.05 A |
| OVERCURRENT | Current > 0.2 A |
| NORMAL | Current within the defined range and no obstacle |

Current readings are averaged over **100 samples** to reduce measurement fluctuations.

## Current Measurement

The ACS712 output is converted into current using the calibrated sensor parameters used in the prototype:

- Offset voltage: **2.08 V**
- ACS712 sensitivity: **0.185 V/A**
- Averaging: **100 samples**

## Output

The system provides:

- Real-time LCD status
- LED-based fault indication
- Serial current and distance data
- MATLAB-based data visualization
- YOLOv8-based person detection

## YOLOv8 Vision Module

The camera-based module provides an additional physical-monitoring layer for person detection.

## Repository Structure

- Code/ - embedded source code
- Documentation/ - project documentation
- Hardware/ - hardware diagrams
- Results/ - test and visualization results

## Technologies

- Embedded C/C++
- Arduino
- ACS712
- HC-SR04
- MATLAB
- YOLOv8
- Serial communication

## Scope

This is a low-voltage educational and laboratory prototype. It is not intended to replace industrial power-line protection equipment.

## Author

**Tanisha Gupta**  
B.Tech Electronics Engineering, VIT Vellore  
Specialization: VLSI Design and Technology
