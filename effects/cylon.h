#ifndef __CYLON_H__
#define __CYLON_H__

#include <ledfx.h>

void cylon(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    static uint8_t hue = 0;

    for(uint16_t i = 0; i < num_leds; i++) {
        leds[i].nscale8(250);
    }

    if (animation_t.iteration == (num_leds*2))
        animation_t.iteration = 0;
    if(animation_t.iteration < num_leds)
        leds[animation_t.iteration] = CHSV(hue++, 255, 255);
    if(num_leds < animation_t.iteration && animation_t.iteration < (2*num_leds))
        leds[2*num_leds - animation_t.iteration] = CHSV(hue++, 255, 255);
}

static struct animation_config cylon_config = 
{
    .id = 0x43,
    .delay = 20,
    .leds_update = cylon,
    .size = 0,
    .params = nullptr,
};


#endif // __CYLON_H__
