#include <QuxCV.h>
int counter;

void setup() {
    counter = 0;
    /*
        By using QuxCV::setup4CVs(), you can use digital 3, 9, 10, and 11 pins
        as CV signal (fast PWM).
    */
    Qux::CV::setup4CVs();
}


void loop() {
    analogWrite(3, counter);
    analogWrite(11, 255 - counter);

    analogWrite(9, counter >> 1); // half of counter
    analogWrite(10, counter >> 2);  // quarter of counter

    counter++;
    if (counter == 256) {
        counter = 0;
    }

    delay(25);
}
