#ifndef __SEGMENTS_H__
#define __SEGMENTS_H__

#include <ledfx.h>

void segments(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const uint8_t segmNum = animation_t.num;
    uint16_t segmOffset = 0;
    const uint16_t segmSize = int(num_leds/segmNum);

    for(uint8_t i = 0; i < segmNum; i++){
        const CRGB color = animation_t.params[i];

        for(uint16_t i = 0; i < segmSize; ++i) {
            leds[segmOffset + i] = color;
        }
        segmOffset += segmSize;
    }
}

static struct animation_config segments_config = 
{
    .id = 0x52,
    .leds_update = segments,
    .num = 20,
};

#endif // __SEGMENTS_H__
