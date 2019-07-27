#include <Qux_CV.h>
int counter;

void setup() {
  counter = 0;
  /*
     QuxCV::setup(bool, (bool), (bool)) sets fast PWM.
     () Arguments are optional.

     First argument is for digital 3 and 13,
     second is 9 and 10
     third is 5 and 6.

     If you set the third argument to true, timer0 based functions,
     such as delay() and mills() will work differently.
  */
  QuxCV::setup4CVs();
}


void loop() {
  analogWrite(3, counter);
  analogWrite(13, 255 - counter);

  analogWrite(9, counter >> 1); // half of counter
  analogWrite(10, counter >> 2);  // quarter of counter

  counter++;
  if (counter == 256) {
    counter = 0;
  }

  delay(25);
}
