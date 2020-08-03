#include <Arduino.h>

namespace Qux  {
    
    namespace CV {
        inline void setupTimer0() {
            TCCR0B &= B11111000;
            TCCR0B |= B00000001;
            
            DDRD |= _BV(5);
            DDRD |= _BV(6);
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
        void setup(uint8_t numPins);             
        void setup2CVs();
        void setup4CVs();
        void setup6CVs();
        void setupAnalogRead(bool highRes = false);
        void wait(const unsigned long delayTime);
        unsigned long msec();
        unsigned long usec();
    } // namespace CV

    class Metro  {
        public:
        Metro();
        Metro(unsigned long _interval);
        virtual inline void updateCurrentTime() {
            now = Qux::CV::msec();
        };
        bool check();
        void reset();

        protected:
        unsigned long  previous_time, interval, now;
    };

    class MicroMetro: public Metro {
        public:
    
        MicroMetro(const unsigned long _interval) { // Maximum: 256us
            interval = _interval;
        }
        inline void updateCurrentTime() {
            now = Qux::CV::usec();
        }
    };
}


