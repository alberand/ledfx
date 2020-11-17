#ifndef __THEATER_CHASE_H__
#define __THEATER_CHASE_H__

#include <ledfx.h>

void theater_chase(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const uint8_t step = (uint8_t)config->params[0];
    const CRGB color_on = config->params[1];
    const CRGB color_off = config->params[2];

    if(animation_t.iteration == step) {
        animation_t.iteration = 0;
    }

    for (uint32_t i = 0; i < num_leds; i++) {
        if(i%step == animation_t.iteration) {
            leds[i] = color_on;
        } else {
            leds[i] = color_off;
        }
    }
}

static struct animation_config config =
{
    .id = 0x50,
    .delay = 200,
    .leds_update = theater_chase,
    .size = 3,
    .params = nullptr,
};



#endif // __THEATER_CHASE_H__
