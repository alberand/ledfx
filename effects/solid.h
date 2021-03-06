#ifndef __SOLID_H__
#define __SOLID_H__

#include <ledfx.h>

void solid() {
    const ledfx_color color = ledfx_color_init(ledfx_get_param(0));
    
    uint16_t offset = 0;
    if(ledfx_get_param(1) != 0){
        offset = ledfx_get_param(1);
    }

    uint16_t num = animation_t.num_leds;
    if(ledfx_get_param(2) != 0){
        num = ledfx_get_param(2);
    }

    for( uint16_t i = 0; i < num; ++i) {
		ledfx_set_pixel(offset + i, color);
    }
}

#endif // __SOLID_H__
