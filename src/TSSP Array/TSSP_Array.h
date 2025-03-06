#ifndef TSSP_ARRAY_H
#define TSSP_ARRAY_H

#include <Arduino.h>

// Config
#define TSSP_NUM 12
#define READ_NUM 100

// Pin connections for TSSP -> Atmega
#define PIN1 17
#define PIN2 14
#define PIN3 20
#define PIN4 2
#define PIN5 10
#define PIN6 9
#define PIN7 8
#define PIN8 3
#define PIN9 6
#define PIN10 21
#define PIN11 15
#define PIN12 18

// MACRO
#define ARRAYSHIFTDOWN(a, lower, upper){          \
    if (upper == (sizeof(a)/sizeof(a[0])) - 1){   \
        for(int q = upper - 1; q >= lower; q--) { \
			*(a + q + 1) = *(a + q); }            \
	    } else {                                  \
		    for(int q = upper; q >= lower; q--) { \
			    *(a + q + 1) = *(a + q); }}}



class TSSP_Array {
public:
    TSSP_Array() {}
    void init();
    void update();
    uint16_t get_direction_advanced();
    uint8_t get_direction_simple();
    uint8_t get_strength();
private:
    uint16_t direction_advanced;
    uint8_t direction_simple;
    uint8_t strength;
    uint8_t pins[TSSP_NUM] = {PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, PIN8, PIN9, PIN10, PIN11, PIN12};
    uint8_t values[TSSP_NUM] = {0};
    uint8_t sorted_values[TSSP_NUM] = {0};
    uint8_t indexes[TSSP_NUM] = {0};
    float x_values[TSSP_NUM] = {0};
    float y_values[TSSP_NUM] = {0};
};

#endif // TSSP_ARRAY_H