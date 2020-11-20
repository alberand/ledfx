#ifndef __SOLID_H__
#define __SOLID_H__

#include <ledfx.h>

void solid(ledfx_RGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const ledfx_RGB color = ledfx_int_to_color(animation_t.params[0]);
    
    uint16_t offset = 0;
    if(animation_t.params[1] != 0){
        offset = animation_t.params[1];
    }

    uint16_t num = num_leds;
    if(animation_t.params[2] != 0){
        num = animation_t.params[2];
    }

    for( int i = 0; i < num; ++i) {
        leds[offset + i] = color;
    }
}

static struct animation_config solid_config = 
{
    .id = 0x41,
    .leds_update = solid,
    .num = 3,
};

#endif // __SOLID_H__
