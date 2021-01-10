The im of this project is to design a LoRAWAN distance sensor with Heltec LoRa 32 V2 board
Serial2 UART port is used to control and read from 703A laser unit
Tx and Rx pins has to be changed since Serial2 uses Rx on pin 16 and Tx on pin 17 as default, but also OLED display reset is pin 16
https://resource.heltec.cn/download/WiFi_LoRa_32/WIFI_LoRa_32_V2.pdf
So first we have to do is to redefine Uart2 pins as RX to 17 and TX to 21
Then to read from the laser you have to send "F" and the lasers gives the following answer F:XXXm, where xxx is the distance in meters
The Arduino sketch makes this function.

Second step is to build up the right hardware since the 703 module has a power supply of 2.8 V while Hetec board has 5V power supply

Third Step is to set up LoRAWAN transmission using LMIC library

Fourth Step is to use deep sleep to save battery

Fifth step is to swith down laser power supply on sleep mode

Sixth Step is to provide Solar pannel to charge the battery
