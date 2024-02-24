#include <firmware/debugger/serial_handler.h>

TwoWire Wire1 = TwoWire(PB9, PB8);
TwoWire Wire2 = TwoWire(PB11, PB10);
HardwareSerial debugSerial = HardwareSerial(PB7, PB6);
HardwareSerial display1Serial = HardwareSerial(PA3, PA2);
HardwareSerial display2Serial = HardwareSerial(PA10, PA9);

void init_serial()
{
    display1Serial.begin(9600);
    display2Serial.begin(9600);
    debugSerial.begin(9600);
}
