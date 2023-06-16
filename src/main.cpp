#include <Arduino.h>

#define TRIG 3
#define ECHO 2

void setup() {
    Serial.begin(9600);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
}

unsigned long measureDistance() {

    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG, LOW);

    return pulseIn(ECHO, HIGH) / 58;

}

void loop() {

    unsigned long distance = measureDistance();
    Serial.print("Distance:");
    Serial.print(distance);
    Serial.println();

    delay(100);

}