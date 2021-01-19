#ifndef __SOLID_H__
#define __SOLID_H__

#include <ledfx.h>

void solid()
{
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
        animation_t.leds[offset + i] = color;
    }
}

static struct animation_config solid_config = 
{
    .id = 0x41,
    .leds_update = solid,
    .num = 3,
};

#endif // __SOLID_H__
