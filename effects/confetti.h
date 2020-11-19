#ifndef __CONFETTI_H__
#define __CONFETTI_H__

#include <ledfx.h>

void confetti(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    static uint16_t hue = 0;
    fadeToBlackBy( leds, num_leds, 10);
    int pos = random16(num_leds);
    leds[pos] += CHSV( hue++ + random8(64), 200, 255);
}

static struct animation_config confetti_config = 
{
    .id = 0x46,
    .delay = 10,
    .leds_update = confetti,
    .num = 0,
};

#endif // __CONFETTI_H__
