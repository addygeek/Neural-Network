#OR GATE USING NEURAL NETWORK
# OR GATE USING NEURAL NETWORK

import numpy as np
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

# Define the OR gate input and output
# Input: [A, B]
# Output: A OR B
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
outputs = np.array([[0], [1], [1], [1]])

# Build the neural network model
model = Sequential()
model.add(Dense(2, input_dim=2, activation='relu'))  # Input layer
model.add(Dense(1, activation='sigmoid'))  # Output layer

# Compile the model
model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])

# Train the model
model.fit(inputs, outputs, epochs=1000, verbose=0)

# Evaluate the model
loss, accuracy = model.evaluate(inputs, outputs)
print(f'Loss: {loss}, Accuracy: {accuracy}')

new_inputs= np.array([[0, 0], [0, 1], [1, 0], [1, 1]])

# Make predictions
predictions = model.predict(new_inputs).round()
print('Predictions:')
print(predictions)