#ifndef __BLINK_H__
#define __BLINK_H__

#include <ledfx.h>
#include <math.h>

void blink(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const CRGB color = CRGB(animation_t.params[0]);
    const float smoothness = animation_t.params[1];
    const uint16_t pause = animation_t.params[2];

    // reset the loop
    if(animation_t.iteration == (uint16_t)smoothness + pause){
        animation_t.iteration = 0;
    }

    // pause between blinks
    if(animation_t.iteration > (uint16_t)smoothness){
        return;
    }

#define GAUSS

#ifdef CIRCLE
    const float c = 255.0*sqrt(1.0 -  pow(abs((2.0*(animation_t.iteration/smoothness))-1.0),2.0));
#endif

#ifdef TRIAN
    const float c = 255.0*(1.0 -  abs((2.0*(animation_t.iteration/smoothness))-1.0));;
#endif

#ifdef GAUSS
    float gamma = 0.14;
    float beta = 0.5; 
    const float c = 255.0*(exp(-(pow(((animation_t.iteration/smoothness)-beta)/gamma,2.0))/2.0));
#endif

    FastLED.setBrightness((int)c);

    for( uint16_t i = 0; i < num_leds; ++i) {
        leds[i] = color;
    }
}

static struct animation_config blink_config = 
{
    .id = 0x54,
    .leds_update = blink,
    .num = 3,
};

#endif // __BLINK_H__
