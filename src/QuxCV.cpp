#include "QuxCV.h"


void Qux::CV::setup(uint8_t numPins) {
    switch (numPins)    {
        case 2:
            setup2CVs();
            break;
        case 4:
            setup4CVs();
            break;
        case 6:
            setup6CVs();
            break;
        default:
            break;
    }
}

void Qux::CV::setup2CVs() {
    setupTimer2();
}

void Qux::CV::setup4CVs() {
    setup2CVs();
    settupTimer1();
}

void Qux::CV::setup6CVs() {
    setup4CVs();    
    setupTimer0();
}

void Qux::CV::setupAnalogRead(bool highRes) {
    if (highRes)  {
        ADCSRA |= 0b00000100; // 8 times faster 
    } else {
        ADCSRA |= 0b00000101; // 4 times faster 
    } 
}

unsigned long Qux::CV::msec() {
    return millis() >> 6;
}

unsigned long Qux::CV::usec() {
    return micros() >> 6;
}

void Qux::CV::wait(const unsigned long delayTime) {
    unsigned long end = Qux::CV::msec() + delayTime;
    while (Qux::CV::msec() < end);
}


Qux::Metro::Metro() {
    interval = 1000;
}

Qux::Metro::Metro(unsigned long _interval) {
    interval = _interval;
}

bool Qux::Metro::check() {
    updateCurrentTime();
    
    if ( interval == 0 ) {
        previous_time = now;
        return true;
    }

    if ( (now - previous_time) >= interval) {
        #ifdef NOCATCH_UP
        previous_time = now ; 
        #else
        previous_time += interval ; 
        #endif
        return true;
    }
  
    return false;
}

void Qux::Metro::reset () {
    previous_time = Qux::CV::msec();
}