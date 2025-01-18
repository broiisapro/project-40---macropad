import serial
import time
import pyautogui
import os

arduino = serial.Serial(port='COM5', baudrate=9600, timeout=1)  # Replace 'COM5' with your Arduino port
time.sleep(2) # Patience is a virtue

def handle_button(button):
    """Perform actions based on button presses."""
    if button == 1:
        pyautogui.press('f11')  # Toggle fullscreen
        print("Toggled fullscreen")
    elif button == 2:
        os.system("code")  # Open VSCode
        print("Opened VSCode")
    elif button == 3:
        pyautogui.press('volumeup')  # Increase volume
        print("Increased volume")
    elif button == 4:
        pyautogui.press('volumedown')  # Decrease volume
        print("Decreased volume")
    elif button == 5:
        os.system("start brave")  # Open browser
        print("Opened Brave browser")

def handle_pot(brightness):
    """Handle potentiometer brightness."""
    print(f"Brightness set to {brightness}")

while True:
    if arduino.in_waiting > 0:
        data = arduino.readline().decode('utf-8').strip()
        if data.startswith("BUTTON_"):
            button = int(data.split("_")[1])
            handle_button(button)
        elif data.startswith("POT_"):
            brightness = int(data.split("_")[1])
            handle_pot(brightness)
    time.sleep(0.1)
