#include "Qux_CV.h"


void QuxCV::setup2CVs() {
    setupTimer2();
    settupTimer1();
    setupTimer0();
}

void QuxCV::setup4CVs() {
    setupTimer2();
    settupTimer1();
}

void QuxCV::setup6CVs() {
    setupTimer2();
    settupTimer1();
    setupTimer0();
}

void QuxCV::setupAnalogRead(bool highRes) {
    if (highRes)  {
        ADCSRA |= 0b00000100; // 8 times faster 
    } else {
        ADCSRA |= 0b00000101; // 4 times faster 
    } 
}

void QuxCV::delay(const unsigned long delayTime) {
    delay(delayTime << 6);
}


unsigned long QuxCV::millis() {
    return millis() >> 6;
}

QuxCV::Metro::Metro() {
    this->interval_millis = 1000;
}

QuxCV::Metro::Metro(unsigned long _interval) {
    this->interval_millis = _interval;
}

bool QuxCV::Metro::check() {
    unsigned long now = QuxCV::millis();
  
    if ( interval_millis == 0 ) {
        this->previous_millis = now;
        return 1;
    }

    if ( (now - this->previous_millis) >= this->interval_millis) {
        #ifdef NOCATCH_UP
        previous_millis = now ; 
        #else
        this->previous_millis += this->interval_millis ; 
        #endif
        return 1;
    }
  
    return 0;
}

void QuxCV::Metro::reset () {
    this->previous_millis = millis();
}