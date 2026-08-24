# Project Results

This directory contains experimental results and tests done on the power-line fault detection prototype.

## Test Cases

The prototype was subjected to the following four test cases:

1. Operating normally
2. Open circuit
3. Over current
4. Obstacle detection

## Operating Normally

Operation of the circuit under normal operation where there is no interruption to the flow of current and there is no object in the detection range of the HC-SR04.

Expected state of the system:

`NORMAL`

## Open Circuit Test

Flow of current was interrupted to mimic an open circuit.

Expected state of the system:

`OPEN`

## Over Current Test

Flow of current or load was adjusted such that it exceeds the set point.

Expected state of the system:

`OVERCURRENT`

## Obstacle Detection Test

Object was introduced into the detection range of the HC-SR04.

Expected state of the system:

`OBSTACLE`

## Data Analysis

Serial sensor data can be used for monitoring and analysis in MATLAB.
