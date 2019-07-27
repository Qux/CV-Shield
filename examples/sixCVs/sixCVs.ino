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
     such as delay() and mills() will won't work as usual.
  */
  QuxCV::setup6CVs();
}


void loop() {
  analogWrite(3, counter);
  analogWrite(13, 255 - counter);

  analogWrite(9, counter >> 1); // half of counter
  analogWrite(10, 255 - >> 2);  // quarter of counter

  analogWrite(5, counter >> 3); // 1/8 of counter
  analogWrite(6, random(255));  

  counter++;
  if (counter == 256) {
    counter = 0;
  }
}
