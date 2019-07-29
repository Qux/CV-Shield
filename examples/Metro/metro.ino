#include <Qux_CV.h>


/*
If you want to use Metro with more than 4 CVs, use Qux::Metro instead of
normal Metro.
*/
QuxCV::Metro metro = new QuxCV::Metro(1000);

int counter;

void setup() {
  counter = 0;
  QuxCV::setup6CVs();
}


void loop() {
    analogWrite(3, counter);
    analogWrite(13, 255 - counter);

    analogWrite(9, counter >> 1); // half of counter
    analogWrite(10, 255  >> 2);  // quarter of counter

    analogWrite(5, counter >> 3); // 1/8 of counter
    analogWrite(6, random(255));


    if (metro.check())  {
        counter++;
        if (counter == 256) {
            counter = 0;
        }
    }
}
