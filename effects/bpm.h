#ifndef __BPM_H__
#define __BPM_H__

#include <ledfx.h>

void bpm(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    static uint16_t hue = 0;
    uint8_t BeatsPerMinute = 62;
    CRGBPalette16 palette = PartyColors_p;
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for(uint16_t i = 0; i < num_leds; i++) {
        hue++;
        leds[i] = ColorFromPalette(palette, hue +(i*2), beat-hue +(i*10));
    }
}

static struct animation_config bpm_config =
{
    .id = 0x48,
    .delay = 10,
    .leds_update = bpm,
    .size = 0,
    .params = NULL,
};

#endif // __BPM_H__
