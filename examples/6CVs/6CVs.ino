#include <QuxCV.h>
int counter;

void setup() {
  counter = 0;
  /*
     QuxCV::setup6CVs() enables to use 6 digital pins as CV (fast PWM).
     If you use more than 4 pins, however, timer0 based functions,
     such as delay() and mills(), will won't work as usual.
  */
  Qux::CV::setup6CVs();
}


void loop() {
  analogWrite(3, counter);
  analogWrite(11, 255 - counter);

  analogWrite(9, counter >> 1); // half of counter
  analogWrite(10, 255  >> 2);  // quarter of counter

  analogWrite(5, counter); 
  analogWrite(6, random(255));  

  counter++;
  if (counter == 256) {
    counter = 0;
  }

  /*
    If you use more than 4 CVs, use QuxCV::delay() instead of 
    delay().
   */

  QuxCV::qdelay(1000);
}
