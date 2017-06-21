/*add 
 * whats is the correct stepsperrev?
 * what is the /100 about?
 * 
 * 
 */

#include <Stepper.h>

const int stepsPerRevolution = 100;

Stepper stirstep(stepsPerRevolution, 8, 9, 10, 11);

int potPin = A0;
int potValue = 0;
int stirRpm = 10;

void setup() {
  Serial.begin(57600);
  Serial.println("stir plate v0.1");  

  stirstep.setSpeed(30);

}

void loop() {

  potValue = analogRead(potPin);
  stirRpm = map(potValue, 0, 1024, 0, 180);
  Serial.print(potValue);
  Serial.print(", ");
  Serial.println(stirRpm);

  
  if (stirRpm > 50){
    stirstep.setSpeed(stirRpm);
    stirstep.step(stepsPerRevolution / 100);   
  }
}
