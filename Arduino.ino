import numpy as np
import pandas as pd
import joblib
import serial
import time

# =========================
# LOAD MACHINE LEARNING MODEL
# =========================

model = joblib.load("water_quality_model.pkl")
scaler = joblib.load("scaler.pkl")

# =========================
# CONNECT ESP32
# =========================

ser = serial.Serial('COM3', 115200)   # Change COM port if needed
time.sleep(2)

print("\nWater Quality Detection Started...\n")

# Variables
temperature = 0
humidity = 0
turbidity = 0

# =========================
# MAIN LOOP
# =========================

while True:

    try:

        if ser.in_waiting:

            # Read serial data
            line = ser.readline().decode('utf-8').strip()

            # =========================
            # READ TEMPERATURE
            # =========================

            if "Temperature:" in line:

                temperature = float(line.split(":")[1])

            # =========================
            # READ HUMIDITY
            # =========================

            elif "Humidity:" in line:

                humidity = float(line.split(":")[1])

            # =========================
            # READ TURBIDITY
            # =========================

            elif "Turbidity:" in line:

                turbidity = int(line.split(":")[1])

                # =========================
                # DUMMY SENSOR VALUES
                # =========================

                ph = 7
                hardness = 200
                solids = turbidity * 10
                sulfate = 300
                conductivity = 500

                # =========================
                # CREATE DATAFRAME
                # =========================

                data = pd.DataFrame([{
                    'ph': ph,
                    'Hardness': hardness,
                    'Solids': solids,
                    'Sulfate': sulfate,
                    'Conductivity': conductivity,
                    'Turbidity': turbidity
                }])

                # =========================
                # SCALE DATA
                # =========================

                data_scaled = scaler.transform(data)

                # =========================
                # MACHINE LEARNING PREDICTION
                # =========================

                prediction = model.predict(data_scaled)
                probability = model.predict_proba(data_scaled)

                confidence = round(max(probability[0]) * 100, 2)

                # =========================
                # WATER QUALITY LOGIC
                # =========================

                if turbidity < 1300:

                    quality = "SAFE"
                    disease = "NONE"

                elif turbidity < 2000:

                    quality = "MODERATE"
                    disease = "Stomach Infection Risk"

                else:

                    quality = "DANGEROUS"
                    disease = "Cholera, Typhoid Risk"

                # =========================
                # DISPLAY REPORT
                # =========================

                print("\n========== WATER REPORT ==========")

                print("Temperature   :", temperature, "°C")
                print("Humidity      :", humidity, "%")
                print("Turbidity     :", turbidity)

                print("----------------------------------")

                print("Water Quality :", quality)
                print("Confidence    :", confidence, "%")
                print("Disease Risk  :", disease)

                print("==================================\n")

        time.sleep(0.1)

    except Exception as e:

        print("Error:", e)
