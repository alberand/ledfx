#ifndef __SNOWSPARKLE_H__
#define __SNOWSPARKLE_H__

#include <ledfx.h>

void snowsparkle(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    static const CRGB base_color = animation_t.params[0];
    static const CRGB sparkle_color = animation_t.params[1];

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
    .num = 2,
};


#endif // __SNOWSPARKLE_H__
