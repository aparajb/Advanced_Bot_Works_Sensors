#include <Arduino.h>
#include <Colour Sensor\Colour_Sensor.h>
#include <TSSP Array\TSSP_Array.h>

Colour_Sensor Nano;
TSSP_Array IR_Sensors;

uint16_t data[4];

void setup() {
    IR_Sensors.init();
    Nano.setSensorRGB_I(data);
}

void loop() {
    IR_Sensors.update();
    data[0] = IR_Sensors.get_direction_simple();
    data[1] = IR_Sensors.get_strength();
    data[2] = IR_Sensors.get_direction_advanced();
    Nano.process();
}