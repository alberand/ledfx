#ifndef __SINELON_H__
#define __SINELON_H__

#include <ledfx.h>

void sinelon(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    static uint16_t hue = 0;
    fadeToBlackBy( leds, num_leds, 20);
    int pos = beatsin16( 13, 0, num_leds-1 );
    leds[pos] += CHSV( hue++, 255, 192);
}

static struct animation_config sinelon_config = 
{
    .id = 0x47,
    .leds_update = sinelon,
    .num = 0,
};

#endif // __SINELON_H__
