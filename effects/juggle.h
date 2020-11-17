#ifndef __JUGGLE_H__
#define __JUGGLE_H__

#include <ledfx_common.h>

void juggle(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    fadeToBlackBy( leds, num_leds, 20);
    byte dothue = 0;
    for( int i = 0; i < 8; i++) {
        leds[beatsin16( i+7, 0, num_leds-1 )] |= CHSV(dothue, 200, 255);
        dothue += 32;
    }
}

static struct animation_config juggle_config = 
{
    .id = 0x49,
    .delay = 10,
    .leds_update = juggle,
    .size = 0,
    .params = nullptr,
};


#endif // __JUGGLE_H__
