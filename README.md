# Hand Gesture Recognition and Arduino Integration Project

This project combines **computer vision** and **embedded systems** to detect hand gestures and control various outputs using an Arduino. It leverages Python for hand gesture detection with the Mediapipe library and Arduino to process the received data for hardware interfacing.

## Features

1. **Real-Time Hand Gesture Detection**:
   - Detects individual fingers' states (up or down) using Mediapipe's Hand Tracking module.
   - Outputs the state of each finger as a binary array (e.g., `[1, 0, 1, 1, 0]`).

2. **Hardware Integration**:
   - Sends the detected finger states to an Arduino over a serial connection.
   - Controls LEDs and a servo motor based on the detected gestures.

3. **User Feedback**:
   - Provides real-time updates on an I2C LCD display connected to the Arduino.
   - Indicates the number of fingers up and down dynamically.

4. **Servo Motor Control**:
   - Maps the number of fingers detected as "up" to servo angles (0° to 180°).

---

## Project Architecture

### Software Components
1. **Python Script**:
   - Uses OpenCV to capture video and process hand gestures.
   - Utilizes Mediapipe for detecting and classifying finger positions.
   - Sends gesture data to Arduino via serial communication.

2. **Arduino Code**:
   - Receives gesture data from Python.
   - Controls LEDs to indicate individual finger states.
   - Updates an LCD display with the number of fingers "up" and "down."
   - Moves a servo motor based on the number of fingers "up."

---

## Installation and Setup

### Hardware Requirements
- Arduino Uno or compatible microcontroller
- 5 LEDs with resistors
- Servo motor
- I2C-compatible LCD (e.g., 16x2 display with I2C module)
- Breadboard and connecting wires
- Webcam for video input

### Software Requirements
- Python 3.7+
- Mediapipe
- OpenCV
- PySerial
- Arduino IDE

### Wiring Diagram
1. **LEDs**:
   - Connect LEDs to Arduino pins (8–12).
   - Ensure proper grounding with resistors.
   
2. **Servo Motor**:
   - Signal pin connected to pin 13 on Arduino.
   - Power and ground connected appropriately.

3. **I2C LCD**:
   - SDA and SCL connected to Arduino's A4 and A5 pins (for Uno).
   - Ensure proper power connections.

---

## How to Run

1. **Set Up the Hardware**:
   - Assemble the components as per the wiring diagram.

2. **Upload the Arduino Code**:
   - Open the Arduino IDE.
   - Upload the provided Arduino code to your microcontroller.

3. **Run the Python Script**:
   - Install the necessary Python libraries:
     ```bash
     pip install opencv-python mediapipe pyserial
     ```
   - Execute the Python script:
     ```bash
     python hand_tracking.py
     ```

4. **Interact**:
   - Display your hand in front of the camera to see live detection.
   - Observe the LEDs, LCD, and servo motor responding to your gestures.

---

## Technical Details

### Python Code
- **Hand Gesture Detection**:
  - Identifies the positions of key hand landmarks.
  - Determines if each finger is up or down based on landmark positions.
- **Serial Communication**:
  - Sends the detected finger states to the Arduino in a comma-separated format.

### Arduino Code
- **Serial Parsing**:
  - Reads the incoming string and extracts finger states.
- **LED Control**:
  - Updates the state of LEDs based on finger states.
- **LCD Feedback**:
  - Dynamically displays the number of fingers up and down.
- **Servo Motor**:
  - Maps finger count to servo angles for proportional movement.

---

## Future Improvements

1. **Gesture Customization**:
   - Add recognition for specific hand gestures (e.g., thumbs-up, peace sign).
   
2. **Wireless Communication**:
   - Replace the serial connection with Bluetooth or Wi-Fi for greater flexibility.

3. **Expand Hardware Interactions**:
   - Control more devices like robotic arms or IoT appliances.

4. **Enhanced Visual Feedback**:
   - Overlay detected finger states directly onto the webcam feed.

---

## Troubleshooting

1. **No Serial Data on Arduino**:
   - Ensure the correct COM port is specified in the Python script.
   - Verify the baud rate matches in both the Python and Arduino codes.

2. **Hand Not Detected**:
   - Ensure sufficient lighting and a clear background.
   - Adjust camera position for better visibility of the hand.

3. **Servo Motor Not Moving**:
   - Check connections and ensure the servo is powered.

---

## Acknowledgments
- **Mediapipe**: For providing robust hand tracking capabilities.
- **OpenCV**: For real-time image processing.
- **Arduino Community**: For extensive libraries and support.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

## Author

Adriel Magalona  
- GitHub: [AdrielMagalona](https://github.com/AdrielMagalona)  
- Email: dagsmagalona@gmail.com  

Feel free to reach out for any queries or collaboration opportunities!
