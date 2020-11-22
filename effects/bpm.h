#ifndef __BPM_H__
#define __BPM_H__

#include <ledfx.h>

const uint32_t PartyColors_p[16] PROGMEM =
{
    0x5500AB, 0x84007C, 0xB5004B, 0xE5001B,
    0xE81700, 0xB84700, 0xAB7700, 0xABAB00,
    0xAB5500, 0xDD2200, 0xF2000E, 0xC2003E,
    0x8F0071, 0x5F00A1, 0x2F00D0, 0x0007F9
};

void bpm(ledfx_RGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    static uint16_t hue = 0;
    uint8_t BeatsPerMinute = 62;

    uint32_t* palette = PartyColors_p;
    uint8_t beat = l8t_beatsin8( BeatsPerMinute, 64, 255);
    for(uint16_t i = 0; i < num_leds; i++) {
        hue++;
        leds[i] = ColorFromPalette(palette, hue +(i*2), beat-hue +(i*10));
    }
}

static struct animation_config bpm_config =
{
    .id = 0x48,
    .leds_update = bpm,
    .num = 0,
};

#endif // __BPM_H__
