#ifndef __SNOWSPARKLE_H__
#define __SNOWSPARKLE_H__

#include <ledfx.h>

void snowsparkle(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    static const CRGB base_color = config->params[0];
    static const CRGB sparkle_color = config->params[1];

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
