#ifndef SERIAL_HANDLER_H
#define SERIAL_HANDLER_H

#include <Arduino.h>
#include <Wire.h>

extern TwoWire Wire1;
extern TwoWire Wire2;
extern HardwareSerial debugSerial;
extern HardwareSerial display1Serial;
extern HardwareSerial display2Serial;

void init_serial();

#endif // SERIAL_HANDLER_H
