#include <VL53L1X.h>
#include <Colour_Sensor.h>

#define SENSOR_COUNT 3

const uint8_t xshutPins[SENSOR_COUNT] = {16, 14, 15};
uint16_t data[4] = {0};

Colour_Sensor Nano;
VL53L1X sensors[SENSOR_COUNT];

void setup()
{
    Nano.setSensorRGB_I(data);
    Wire.begin();
    Wire.setClock(400000);

    for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
        pinMode(xshutPins[i], OUTPUT);
        digitalWrite(xshutPins[i], LOW);
    }

    for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
        pinMode(xshutPins[i], INPUT);
        delay(10);
        sensors[i].setTimeout(500);

        if(!sensors[i].init()) {
            while (1);
        }

        sensors[i].setAddress(0x2A + i);
        sensors[i].startContinuous(33); // 30Hz
    }
}

void loop()
{
    for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
        data[i] = sensors[i].read();
    }
    Nano.process();
}
