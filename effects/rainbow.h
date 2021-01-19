#ifndef __RAINBOW_H__
#define __RAINBOW_H__

#include <ledfx.h>

uint32_t color_wheel(uint8_t pos) {
  	pos = 255 - pos;
  	if(pos < 85) {
    	return ((uint32_t)(255 - pos * 3) << 16) | ((uint32_t)(0) << 8) | (pos * 3);
  	} else if(pos < 170) {
    	pos -= 85;
    	return ((uint32_t)(0) << 16) | ((uint32_t)(pos * 3) << 8) | (255 - pos * 3);
  	} else {
    	pos -= 170;
    	return ((uint32_t)(pos * 3) << 16) | ((uint32_t)(255 - pos * 3) << 8) | (0);
  	}
}

void rainbow() {
	uint8_t offset = animation_t.iteration % 255;

	uint8_t step = ledfx_get_param(1);

	for(int i = 0; i < animation_t.num_leds; i++){
		const uint8_t pos = offset + i + step;
		ledfx_set_pixel(i, ledfx_int_to_color(color_wheel(pos)));
	}
}

#endif // __RAINBOW_H__
