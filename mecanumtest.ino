#include "mecmotor.h"
mecmotor motor;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  motor.forward(180);
  delay (2000);
  motor.backward(180);
  delay(2000);
  motor.strafel(255);
  delay(2000);
  motor.strafer(250);
  delay(2000);
}
