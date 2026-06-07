import pickle
import numpy as np

# === Step 1: Load the model ===
with open("xgb_watering_model.pkl", "rb") as file:
    model = pickle.load(file)

# === Step 2: Prepare input ===
# Replace these with your actual values: hum, temp, soil mois
input_features = [60, 32, 850]
input_array = np.array(input_features).reshape(1, -1)  # Reshape to (1, 3)

# === Step 3: Get prediction ===
prediction = model.predict(input_array)

# === Step 4: Output ===
print("Prediction:", prediction[0])  # Will be 0 or 1