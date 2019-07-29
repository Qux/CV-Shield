#include <Arduino.h>

namespace QuxCV {
    static bool disturb_timer = false;

    inline void setupTimer0() {
        TCCR0B &= B11111000;
        TCCR0B |= B00000010;
        
        DDRD |= _BV(5);
        DDRD |= _BV(6);

        disturb_timer = true;
}

    inline void settupTimer1()  {
        TCCR1B &= B11111000;
        TCCR1B |= B00000001;

        DDRD |= _BV(9);
        DDRD |= _BV(10);
    }

    inline void setupTimer2() {
        TCCR2B &= B11111000;
        TCCR2B |= B00000001;
        DDRD |= _BV(3);
        DDRD |= _BV(13);
    }

    void setup2CVs();
    void setup4CVs();
    void setup6CVs();
    void setupAnalogRead(bool highRes = false);
    void delay(const unsigned long delayTime);
    unsigned long millis();

    class Metro  {
        public:
        Metro();
        Metro(unsigned long _interval);
        bool check();
        void reset();

        private:
        unsigned long  previous_millis, interval_millis;
    };
} // namespace QuxCV



