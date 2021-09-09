#include <QuxCV.h>


/*
If you want to use Metro with more than 4 CVs, use Qux::Metro instead of
normal Metro.
*/
Qux::Metro metro = Qux::Metro();

int counter;
bool LED;

void setup() {
    Qux::CV::setup6CVs();

    counter = 0;
    LED = false;
    pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
    analogWrite(3, counter);
    analogWrite(11, 255 - counter);

    analogWrite(9, counter >> 1); // half of counter
    analogWrite(10, 255  >> 2);  // quarter of counter

    analogWrite(5, counter); 
    analogWrite(6, random(255));


    if (metro.check())  {
        counter++;
        if (counter >= 256) {
            counter = 0;
        }

        LED = !LED;
        digitalWrite(LED_BUILTIN, LED);
    }
}
