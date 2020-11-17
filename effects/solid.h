#ifndef __SOLID_H__
#define __SOLID_H__

#include <ledfx.h>

void solid(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const CRGB color = config->params[0];
    uint16_t offset = 0;
    if(config->params[1] != 0){
        offset = config->params[1];
    }

    uint16_t num = num_leds;
    if(config->params[2] != 0){
        num = config->params[2];
    }

    for( int i = 0; i < num; ++i) {
        leds[offset + i] = color;
    }
}

static struct animation_config config = 
{
    .id = 0x41,
    .delay = 10,
    .leds_update = solid,
    .size = 3,
    .params = nullptr,
};

#endif // __SOLID_H__
