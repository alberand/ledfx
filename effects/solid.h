#ifndef __SOLID_H__
#define __SOLID_H__

#include <ledfx_common.h>

struct solid_params {
    uint32_t color;
    uint16_t offset;
    uint16_t num;
};

void solid(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    solid_params* params = (solid_params*)config->params;
    const CRGB color = params->color;
    
    uint16_t offset = 0;
    if(params->offset != 0){
        offset = params->offset;
    }

    uint16_t num = num_leds;
    if(params->num != 0){
        num = params->num;
    }

    for( int i = 0; i < num; ++i) {
        leds[offset + i] = color;
    }
}

static struct animation_config solid_config = 
{
    .id = 0x41,
    .delay = 10,
    .leds_update = solid,
    .size = 3,
    .params = nullptr,
};

#endif // __SOLID_H__
