#include <PacketSerial.h>
#include <QuxCV.h>

PacketSerial ps;

const char Num_CVs = 4;
const uint8_t Pins[Num_CVs] = {3, 9, 10, 11};

void onPacketReceived(const uint8_t* buffer, size_t size) {  
  for(int i = 0; i < Num_CVs; i++) {
    analogWrite(Pins[i], buffer[i]);
  }
}

 
void setup() {
  // put your setup code here, to run once:
  ps.begin(115200);
  ps.setPacketHandler(onPacketReceived);

  Qux::CV::setup(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  ps.update();
  
}
