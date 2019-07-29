#include <Qux_CV.h>
int counter;

void setup() {
    counter = 0;
    /*
    By using QuxCV::setup2CVs(), you can use digital 3 and 11 pins
    as CV signal (fast PWM).
    */
    QuxCV::setup2CVs();
}


void loop() {
    analogWrite(3, counter);
    analogWrite(11, 255 - counter);

    counter++;
    if (counter == 256) {
        counter = 0;
    }

    delay(25);
}
