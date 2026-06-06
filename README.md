# Smart Water Quality Monitoring System with Multi-Level Usability and Waterborne Disease Risk Prediction

## Project Overview

Water contamination is one of the most significant environmental and public health challenges worldwide. This project presents an IoT-enabled Smart Water Quality Monitoring System that combines real-time sensing and Machine Learning techniques to classify water usability and predict potential waterborne disease risks.

## Research Publication

**Title:** Smart Water Quality Monitoring System with Multi-Level Usability and Waterborne Disease Risk Prediction

**Conference:** IEEE ICONAT 2026

**Role:** Primary Author

**Status:** Submitted for Review

## Objectives

- Monitor water quality in real time using IoT devices.
- Classify water based on usability levels.
- Predict disease risks associated with contaminated water.
- Develop lightweight ML models suitable for embedded systems.
- Create a scalable and cost-effective monitoring solution.

## System Architecture

```text
Water Sample
      │
      ▼
Temperature Sensor
      │
      ▼
Turbidity Sensor
      │
      ▼
ESP32 Microcontroller
      │
      ▼
Real-Time Data Collection
      │
      ▼
Machine Learning Model
      │
      ├── Water Usability Classification
      │
      └── Disease Risk Prediction
      │
      ▼
Monitoring Dashboard
```

## Hardware Components

- ESP32 Microcontroller
- Turbidity Sensor
- Temperature Sensor
- Power Supply Module
- Wi-Fi Communication Module

## Methodology

### 1. Data Collection

Water quality measurements were collected using a turbidity sensor connected to an ESP32 microcontroller.

### 2. Data Preprocessing

- Data Cleaning
- Missing Value Handling
- Feature Preparation
- Label Encoding

### 3. Machine Learning Model Development

A lightweight Machine Learning classification model was trained using water quality datasets.

### 4. Water Usability Classification

| Category | Description |
|-----------|------------|
| Drinkable | Safe for human consumption |
| Usable | Suitable for limited non-drinking purposes |
| Dangerous | Unsafe due to high contamination levels |

### 5. Disease Risk Prediction

The system predicts potential disease risks associated with contaminated water, providing more detailed insights than traditional monitoring systems.

## Machine Learning Pipeline

```text
Sensor Data
      │
      ▼
Data Preprocessing
      │
      ▼
Feature Engineering
      │
      ▼
Model Training
      │
      ▼
Water Usability Prediction
      │
      └── Disease Risk Prediction
```

## Key Features

- Real-Time Water Quality Monitoring
- IoT-Based Architecture
- Multi-Level Water Classification
- Disease Risk Prediction
- Lightweight ML Deployment
- Cost-Effective Solution

## Technologies Used

### Programming

- Python

### Machine Learning

- Scikit-learn
- Classification Models
- Model Evaluation

### IoT

- ESP32
- Sensor Integration

### Data Analysis

- Pandas
- NumPy
- Matplotlib

## Results

- Successful real-time water quality monitoring.
- Multi-level water usability classification.
- Disease risk prediction based on contamination levels.
- Lightweight model suitable for embedded deployment.

## Impact

The proposed system contributes toward:

- Smart Environmental Monitoring
- Public Health Awareness
- Rural Water Quality Assessment
- Sustainable Water Management

## Future Scope

- Additional water quality sensors
- Cloud dashboard integration
- Mobile application support
- Explainable AI for predictions
- Large-scale deployment
