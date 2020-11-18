#ifndef __THEATER_CHASE_H__
#define __THEATER_CHASE_H__

#include <ledfx_common.h>

struct theater_chase_params {
    uint8_t step;
    uint32_t color_on;
    uint32_t color_off;
};

void theater_chase(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    theater_chase_params* params = (theater_chase_params*)config->params;
    const uint8_t step = params->step;
    const CRGB color_on = params->color_on;
    const CRGB color_off = params->color_off;

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
    .delay = 200,
    .leds_update = theater_chase,
    .size = 3,
    .params = nullptr,
};



#endif // __THEATER_CHASE_H__
