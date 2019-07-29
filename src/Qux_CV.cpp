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

unsigned long QuxCV::msec() {
    return millis() >> 6;
}

unsigned long QuxCV::usec() {
    return micros() >> 6;
}

void QuxCV::wait(const unsigned long delayTime) {
    unsigned long end = QuxCV::msec() + delayTime;
    while (QuxCV::msec() < end);
}


QuxCV::Metro::Metro() {
    interval = 1000;
}

QuxCV::Metro::Metro(unsigned long _interval) {
    interval = _interval;
}

bool QuxCV::Metro::check() {
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

void QuxCV::Metro::reset () {
    previous_time = QuxCV::msec();
}