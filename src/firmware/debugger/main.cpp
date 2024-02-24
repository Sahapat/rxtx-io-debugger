#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <firmware/debugger/serial_handler.h>

Adafruit_SSD1306 oled_display1(128, 32, &Wire1, -1);
Adafruit_SSD1306 oled_display2(128, 64, &Wire2, -1);

char d1_receive_ch[128];
char d1_receive_index = 0;

char d2_receive_ch[128];
char d2_receive_index = 0;

void setup()
{
    init_serial();
    oled_display1.begin(SSD1306_SWITCHCAPVCC, 0x3c);
    oled_display1.setTextSize(1);
    oled_display1.setTextColor(WHITE);
    oled_display1.setTextWrap(true);
    oled_display1.display();

    oled_display2.begin(SSD1306_SWITCHCAPVCC, 0x3c);
    oled_display2.setTextSize(1);
    oled_display2.setTextColor(WHITE);
    oled_display2.setTextWrap(true);
    oled_display2.display();
}

void loop()
{
    while (display1Serial.available() > 0)
    {
        char ch = display1Serial.read();
        if (ch == '\n')
        {
            oled_display1.clearDisplay();
            oled_display1.setCursor(0,0);
            oled_display1.print(d1_receive_ch);
            oled_display1.display();
            debugSerial.print("d1 receive:");
            debugSerial.println(d1_receive_ch);
            for(int i =0; i<128;i++)
            {
                d1_receive_ch[i] = 0;
            }
            d1_receive_index = 0;
        }
        d1_receive_ch[d1_receive_index] = ch;
        d1_receive_index++;
    }

    while(display2Serial.available() > 0)
    {
        char ch = display2Serial.read();
        if (ch == '\n')
        {
            oled_display2.clearDisplay();
            oled_display2.setCursor(0,0);
            oled_display2.print(d2_receive_ch);
            oled_display2.display();
            debugSerial.print("d2 receive:");
            debugSerial.println(d2_receive_ch);
            for(int i =0; i<128;i++)
            {
                d2_receive_ch[i] = 0;
            }
            d2_receive_index = 0;
        }
        d2_receive_ch[d2_receive_index] = ch;
        d2_receive_index++;
    }
}
