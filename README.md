                                             LINE FOLLOWER BOT (ESP32)
Our project uses an ESP32 with an 8-array IR reflective sensor to detect and follow a black line on a white surface (or vice versa).
The code supports:

    -Calibration mode for determining sensor thresholds.
    -Line-following mode with PID control.
    -Adjustable KP, KI, KD parameters for smooth movement.
    -The ESP32 hosts a web server that allows you to tune PID values (Kp, Ki, Kd) in real-time from your phone or laptop — no need to re-upload code through USB after each change(advantage of esp32 than arduino)

⚙️ Features

     ✅ Automatic sensor calibration
     ✅ Adjustable PID values from any phone/laptop on the same network
     ✅ Smooth and accurate line following
     ✅ Web interface with sliders for PID tuning
     ✅ No need for USB cable after initial upload

🛠 Hardware Requirements

     -ESP32 Dev module
     -8-Array IR Reflective Sensor Module (Analog output)
     -Motor Driver (TB6612FNG)
     -2 DC Motors with wheels and 1 castor wheel
     -Power supply (LiPo battery)
     -Buck converter (ESP32 operates at 3.3V, max 5V — more than that can damage it)
     -Chassis for mounting sensors and motors

📱Using the Web Interface

    Upload the code to your ESP32.
    Open the Serial Monitor to find the IP address assigned to the ESP32 (youll get this if u open the serial monitor and press the en button).
    Connect your phone/laptop to the same WiFi network.
    Enter the IP in your browser (e.g., http://192.168.x.x).
    Adjust Kp, Ki, Kd sliders/fields.
    Click Update — changes take effect instantly.   
  
     
    
