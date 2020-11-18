#ifndef __SNOWSPARKLE_H__
#define __SNOWSPARKLE_H__

#include <ledfx.h>

struct snowsparkle_params {
    uint32_t base_color;
    uint32_t sparkle_color;
};

void snowsparkle(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    snowsparkle_params* params = (snowsparkle_params*)config->params;
    static const CRGB base_color = params->base_color;
    static const CRGB sparkle_color = params->sparkle_color;

    if(animation_t.iteration == 130) {
        animation_t.iteration = 0;
    }

    if(animation_t.iteration == 100) {
        leds[random(num_leds)] = base_color;
    }

    if(animation_t.iteration == 115) {
        for(uint16_t i = 0; i < num_leds; i++) {
            leds[i] = sparkle_color;
        }
    }
}

static struct animation_config snowsparkle_config = 
{
    .id = 0x4c,
    .delay = 10,
    .leds_update = snowsparkle,
    .size = 2,
    .params = nullptr,
};


#endif // __SNOWSPARKLE_H__
