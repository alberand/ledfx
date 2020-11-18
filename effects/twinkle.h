#ifndef __TWINKLE_H__
#define __TWINKLE_H__

#include <ledfx_common.h>

struct twinkle_params {
    uint32_t color;
};

void twinkle(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    twinkle_params* params = (twinkle_params*)config->params;
    const CRGB color = params->color;

    if(animation_t.iteration == 400) {
        animation_t.iteration = 0;
    }

    if(animation_t.iteration == 100) {
        animation_t.iteration = 0;
        leds[random(num_leds)] = color;
    } else {
        for(uint16_t i = 0; i < num_leds; i++) {
            leds[i].nscale8(250);
        }
    }
}

static struct animation_config twinkle_config =
{
    .id = 0x4b,
    .delay = 10,
    .leds_update = twinkle,
    .size = 1,
    .params = nullptr,
};


#endif // __TWINKLE_H__
