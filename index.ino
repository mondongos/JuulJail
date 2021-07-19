#include "lcd.h"


void setup() {
    Serial.begin(115200);
    int x =  initSerialMonitor();
    Serial.println(x);
}

void loop() {
    int bork = whatever();
    Serial.println(bork);
    delay(1000);
}