#include <Servo.h>

#define SERVO_PIN 9
#define BUTTON_PIN 4
#define POT_PIN A0

Servo servo;

void setup() 
{
  //Initialize the Servo motor connected to this pin.
  servo.attach(SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// Move the servo to 0 degrees, then to 180 degrees.
void sweep()
{
  // start moving the servo to 0 degrees
  servo.write(0);
  // wait for the servo to get to 0 degrees
  delay(500);
  // start moving the servo to 180 degrees
  servo.write(180);
  // wait...
  delay(500);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  bool isPressed = 
    digitalRead(BUTTON_PIN) == LOW;

  if(isPressed)
  {
    int potValue = analogRead(POT_PIN);
    int position = map(potValue, 0, 1023, 0, 180);
    servo.write(position);
  }
  else 
  {
    sweep();
  }

  delay(50);
}
