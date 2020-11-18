#ifndef __TWINKLE_H__
#define __TWINKLE_H__

#include <ledfx.h>

void twinkle(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    if(animation_t.iteration == 400) {
        animation_t.iteration = 0;
    }

    if(animation_t.iteration == 100) {
        animation_t.iteration = 0;
        leds[random(num_leds)] = config->params[0];
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
