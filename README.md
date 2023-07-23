Arduino Room Size Estimator
This Arduino project utilizes an ultrasonic sensor, a servo motor and a LiquidCrystal display to estimate the size of a room. The sensor, attached to the servo motor, rotates and scans the surroundings to find the maximum distance it can reach in each direction. The maximum value found is assumed to be the radius of a circular room, and thus, the room dimensions are estimated to be twice this value in each direction (length and width).

Requirements
Arduino board
Ultrasonic sensor (HC-SR04)
Servo motor
16x2 LCD display
Necessary jumper wires and breadboard
Connections
LiquidCrystal lcd(7, 6, 5, 4, 3, 2) : LCD connected on these digital pins
Servo myservo attached on pin 8
Ultrasonic Sensor TRIG_PIN on pin 9, ECHO_PIN on pin 10
Usage
Connect your components to your Arduino board following the above connections.
Upload this script to your Arduino board using the Arduino IDE.
Once the script is uploaded and the Arduino board is powered (either by USB connection to a computer or external power source), the servo motor will start rotating the ultrasonic sensor from 0 to 180 degrees.
The LCD display will display the estimated room dimensions in the format "X x Y cm", where X and Y are the estimated length and width of the room in centimeters.
Note: This is a basic estimator and assumes a perfect circular room. It may not give accurate dimensions for irregularly shaped rooms. The "Room Size" shown is merely an estimate and should not be used for precise measurements.

Credits
This project was made as an interesting way to explore the capabilities of Arduino. It's a fun and educational tool to understand how sensors can interact with the physical world.

Important: Be cautious while handling electrical components and follow safety guidelines.
