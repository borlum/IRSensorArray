#include "IRSensorArray.h"

SensorIR testIRSensor(200);

int foo;

void setup() {
  Serial.begin(9600);
}

void loop() {
    foo = testIRSensor.getMean();
    Serial.println(foo);
}