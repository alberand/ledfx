#ifndef __CONFETTI_H__
#define __CONFETTI_H__

#include <ledfx.h>

void confetti(ledfx_RGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    static uint16_t hue = 0;
    nscale8x3(leds[i].r, leds[i].g, leds[i].b, 245);
    int pos = l8t_random16(num_leds);
    leds[pos] += CHSV( hue++ + l8t_random8(64), 200, 255);
}

static struct animation_config confetti_config = 
{
    .id = 0x46,
    .leds_update = confetti,
    .num = 0,
};

#endif // __CONFETTI_H__
