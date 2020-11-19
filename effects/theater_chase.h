#ifndef __THEATER_CHASE_H__
#define __THEATER_CHASE_H__

#include <ledfx.h>

void theater_chase(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const uint8_t step = (uint8_t)animation_t.params[0];
    const CRGB color_on = animation_t.params[1];
    const CRGB color_off = animation_t.params[2];

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

static struct animation_config theater_chase_config =
{
    .id = 0x50,
    .leds_update = theater_chase,
    .num = 3,
};



#endif // __THEATER_CHASE_H__
