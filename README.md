---

**MacroDeck: Arduino-Powered Macro Controller**

**MacroDeck** is an interactive macro controller that integrates an Arduino, buttons, and a potentiometer to perform system actions on your computer. It offers seamless control over fullscreen mode, applications, system volume, and more, making it ideal for productivity and media setups.

---

## **Features**
1. **Button Actions**:
   - **Button 1**: Toggles fullscreen mode (`F11`).
   - **Button 2**: Launches Visual Studio Code.
   - **Button 3**: Increases system volume.
   - **Button 4**: Decreases system volume.
   - **Button 5**: Opens the Brave browser.
2. **Potentiometer**:
   - Adjusts brightness dynamically (simulated feedback in Python).
3. **Real-Time Serial Communication**:
   - Arduino sends button presses and potentiometer values to a Python script for handling actions.

---

## **Hardware Requirements**
1. **Arduino Uno (or compatible board)**
2. **5 Push Buttons**
   - Connected to pins 2–6 with pull-up resistors or configured with `INPUT_PULLUP` in the Arduino code.
3. **1 Potentiometer**
   - Center pin connected to `A0`, side pins connected to `5V` and `GND`.
4. **KY-009 RGB LED** (Optional)
   - For visual feedback (not directly integrated into the Python script).

---

## **Software Requirements**
1. **Python 3.x**:
   - Libraries: `pyautogui`, `os`, `serial`
   - Install them using:
     ```bash
     pip install pyautogui pyserial
     ```
2. **Arduino IDE**:
   - Required to upload the Arduino sketch to your board.

---

## **Setup Instructions**
1. **Hardware Wiring**:
   - Connect the buttons to pins 2–6.
   - Connect the potentiometer to `A0`.
   - (Optional) Connect the RGB LED to pins 9, 10, 11 with 330Ω resistors.
2. **Arduino Setup**:
   - Upload the provided Arduino sketch using the Arduino IDE.
3. **Python Script**:
   - Update the `port` value in the Python script to match your Arduino's COM port.
   - Install necessary Python libraries.
   - Run the script:

---

## **Usage**
1. Adjust the potentiometer to set brightness (feedback is printed in the terminal).
2. Press buttons to trigger system actions:
   - Button 1: Toggle fullscreen.
   - Button 2: Open VSCode.
   - Button 3: Increase volume.
   - Button 4: Decrease volume.
   - Button 5: Open Brave browser.

---

Readme made with the assistance of AI
