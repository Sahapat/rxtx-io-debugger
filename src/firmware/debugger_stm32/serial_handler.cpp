#include <firmware/debugger_stm32/serial_handler.h>

TwoWire Wire1 = TwoWire(PB9, PB8);
TwoWire Wire2 = TwoWire(PB11, PB10);
SoftwareSerial debuggerSerial = SoftwareSerial(PB12, PB13);
HardwareSerial display1Serial = HardwareSerial(PA3, PA2);
HardwareSerial display2Serial = HardwareSerial(PB7, PB6);

void init_serial()
{
    debuggerSerial.begin(9600);
    display1Serial.begin(9600);
    display2Serial.begin(9600);
}
