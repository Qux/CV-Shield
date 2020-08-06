#include <PacketSerial.h>
#include <QuxCV.h>

PacketSerial ps;

const char Num_CVs = 6;
const uint8_t Pins[Num_CVs] = {3, 9, 10, 11, 5, 6}; //Timer2, Timer1, Timer0

void onPacketReceived(const uint8_t* buffer, size_t size) {  
  analogWrite(buffer[0], buffer[1]);
}

 
void setup() {
  // put your setup code here, to run once:
  ps.begin(115200);
  ps.setPacketHandler(onPacketReceived);

  Qux::CV::setup(Num_CVs);
}

void loop() {
  // put your main code here, to run repeatedly:
  ps.update();
}
