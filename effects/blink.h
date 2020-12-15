#ifndef __BLINK_H__
#define __BLINK_H__

#include <ledfx.h>

void blink(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const CRGB color = CRGB(animation_t.params[0]);
    
    uint16_t multiplier = 1;
    if(animation_t.params[1] != 0){
        multiplier = animation_t.params[1];
    }
    uint16_t period = num_leds*multiplier;

    if (animation_t.iteration == period){
        animation_t.iteration = 0;
    }

    if(animation_t.iteration == 0){
        for( uint16_t i = 0; i < num_leds; ++i) {
            leds[i] = 0;
        }
    }

    if(animation_t.iteration == (int)period/2){
        for( uint16_t i = 0; i < num_leds; ++i) {
            leds[i] = color;
        }
    }
}

static struct animation_config blink_config = 
{
    .id = 0x54,
    .leds_update = blink,
    .num = 3,
};

#endif // __BLINK_H__
