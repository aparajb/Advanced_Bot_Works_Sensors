#include "TSSP_Array.h"

void TSSP_Array::init() {
    for(uint8_t i = 0; i < TSSP_NUM; i++) {
        pinMode(pins[i], INPUT);
        x_values[i] = cosf(RAD_TO_DEG * (450.0f - i * 30.0f));
        y_values[i] = sinf(RAD_TO_DEG * (450.0f - i * 30.0f));
	  }
}

void TSSP_Array::update() {
	for(uint8_t i = 0; i < READ_NUM; i++) {
		for(uint8_t j = 0; j < TSSP_NUM; j++) {
		    values[j] += 1 - digitalRead(pins[j]);
	    }
	}
	for(uint8_t i = 0; i < TSSP_NUM; i++) {
		sorted_values[i] = 0;
	}
    for(uint8_t i = 0; i < TSSP_NUM; i++) {
        for(uint8_t j = 0; j < TSSP_NUM; j++) {
            if(values[i] > sorted_values[j]) {
                if(j <= i) {
                    ARRAYSHIFTDOWN(sorted_values, j, i);
                    ARRAYSHIFTDOWN(indexes, j, i);
                }
                sorted_values[j] = values[i];
                indexes[j] = i;
                break;
            }
		}
	}
    strength = sorted_values[0];
    direction_simple = (strength == 0) ? 0 : indexes[0] + 1;
    int index_lower = indexes[0] - 1;
    index_lower = (index_lower < 0) ? index_lower + 12 : index_lower;
    int index_upper = indexes[0] + 1;
    index_upper = (index_upper >= 12) ? index_upper - 12 : index_upper;
    int index_lower_1 = indexes[0] - 2;
    index_lower_1 = (index_lower_1 < 0) ? index_lower_1 + 12 : index_lower_1;
    int index_upper_1 = indexes[0] + 2;
    index_upper_1 = (index_upper_1 >= 12) ? index_upper_1 - 12 : index_upper_1;
    float frac = (float)indexes[0] + ( ( (float)(values[index_upper] - values[index_lower]) + ((float)(values[index_upper_1] - values[index_lower_1]) / 2.0) )  /  (2.0 * (float)sorted_values[0]));
    frac = frac < 0 ? frac + 12.0 : frac;
    direction_advanced = (strength == 0) ? 0 : round(frac * 30.0);
	for(uint8_t i = 0; i < TSSP_NUM; i++) {
		values[i] = 0;
		sorted_values[i] = 0;
		indexes[i] = 0;
	}
}


uint16_t TSSP_Array::get_direction_advanced() {
    return direction_advanced;
}

uint8_t TSSP_Array::get_direction_simple() {
    return direction_simple;
}

uint8_t TSSP_Array::get_strength() {
    return strength;
}