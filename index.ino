//#include "lcd.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

Servo servo;
rgb_lcd lcd;


int counter = 5; 
String timerState = "LOCKED";
int lockState = 0;

void setup() {
    Serial.begin(115200);
    lcd.begin(16, 2);
    servo.attach(9);
    servo.write(0);
    delay(1000);
}

void loop() {
    counter--;
    Serial.println(lockState);
    if (counter > 0) {
        lcd.setCursor(0, 0);
        lcd.print("JUUL is ");
        lcd.print(timerState);
        lcd.setCursor(0, 1);
        lcd.print(counter);
        lcd.print(" seconds left");
        lockState = 0;
    }
    else if (counter <= 0) {
        timerState = "UNLOCKED";
        counter = 0;
        lcd.setCursor(0, 0);
        lcd.print("JUUL is ");
        lcd.print(timerState);
        lcd.setCursor(0, 1);
        lcd.print(counter);
        lcd.print(" seconds left");
        servo.write(180);
        lockState = 1;

    }
    delay(1000);
}
