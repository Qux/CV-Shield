#include <Qux_CV.h>
int counter;

constexpr char INPUT_PIN = 0;
constexpr char LED_PIN = 13;

void setup() {
  counter = 0;
    /*
    QuxCV::setupAnalogRead() sets the fast ADC.
    */
    QuxCV::setupAnalogRead();
    
    pinMode(13, OUTPUT);
}


void loop() {
    // You can use analogRead() as usual.
    int value = analogRead(INPUT_PIN);
    analogWrite(LED_PIN, value >> 2); // Turn 10 bits into 8 bits.
}
