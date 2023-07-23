#include <LiquidCrystal.h>
#include <Servo.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
Servo myservo;  // create servo object to control a servo

#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  lcd.begin(16, 2);  // Set up the LCD's number of columns and rows
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  myservo.attach(8);  // attaches the servo on pin 8 to the servo object
}

void loop() {
  long maxDistance = 0;

  for (int pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    myservo.write(pos); // tell servo to go to position 'pos'
    delay(15);  // waits 15ms for the servo to reach the position
    
    // Take distance measurement
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
  
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
  
    long duration = pulseIn(ECHO_PIN, HIGH);
  
    long distance = duration / 58.2;

    if (distance > maxDistance) {
      maxDistance = distance;
    }
  }

  // Display room dimensions
  lcd.clear();  // Clear the LCD screen before printing new distance
  lcd.setCursor(0, 0);  // Set the cursor at the beginning of the LCD screen
  lcd.print("Room Size:");
  lcd.setCursor(0, 1);  // Set the cursor at the beginning of the second line on the LCD screen
  lcd.print(maxDistance*2);
  lcd.print(" x ");
  lcd.print(maxDistance*2);
  lcd.print(" cm");

  // You could add a delay here if you want to pause between sweeps
  delay(2000);
}
