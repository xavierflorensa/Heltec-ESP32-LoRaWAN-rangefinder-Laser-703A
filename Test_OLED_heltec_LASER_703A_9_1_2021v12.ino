
#define RXD2 17
#define TXD2 23
int received ;
String packet ;


// OLED Library https://github.com/ThingPulse/esp8266-oled-ssd1306
#include <SSD1306.h>


//OLED pins to ESP32 GPIOs on Heltec LoRa32:
//OLED_SDA -- GPIO4
//OLED_SCL -- GPIO15
//OLED_RST -- GPIO16

SSD1306  display(0x3c, 4, 15);
const int pResetOLED = 16;

void setup() {
  // put your setup code here, to run once:
    pinMode(pResetOLED, OUTPUT);
    digitalWrite(pResetOLED, LOW);         // set GPIO16 low to reset OLED
    delay(50); 
    digitalWrite(pResetOLED, HIGH);        // while OLED is running, must set GPIO16 in high
    display.init(); // Initialising the UI will init the display too.
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_24);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    Serial.begin(19200);
    // Serial connected to LIDAR sensor
    Serial2.begin(19200, SERIAL_8N1, RXD2, TXD2);
    
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial2.println( "F" );
 //delay(1000);
 display.clear();

 packet ="";

while (Serial2.available()>0 && received !=44)
  {
    received = Serial2.read();
    packet += (char) received;
    
  }
  //this clears the rest of the buffer after ','
  while (Serial2.available()>0)
  {
    received = Serial2.read();
  }
  display.drawString(0 , 0 , "Distance");
  display.drawString(0 , 30 , packet);
  display.display();
  Serial.println(packet);
  received=0;
  delay(3000);
}
