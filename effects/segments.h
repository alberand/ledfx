#ifndef __SEGMENTS_H__
#define __SEGMENTS_H__

#include <ledfx.h>

void blur1d(CRGB* leds, uint16_t num_leds, uint16_t start, uint16_t stop, fract8 blur_amount)
{
    uint8_t keep = 255 - blur_amount;
    uint8_t seep = blur_amount >> 1;
    CRGB carryover = CRGB::Black;

    for( uint16_t i = start; i < stop; ++i) {
        CRGB cur = leds[i];
        CRGB part = cur;
        part.nscale8( seep);
        cur.nscale8( keep);
        cur += carryover;
        if( i) leds[i-1] += part;
        leds[i] = cur;
        carryover = part;
    }
}

void segments(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const uint8_t segmNum = animation_t.num;
    uint16_t segmOffset = 0;
    const uint16_t segmSize = int(num_leds/segmNum);
	const uint8_t width = 16;

    for(uint8_t i = 0; i < segmNum; i++){
        const CRGB color = animation_t.params[i];

        for(uint16_t i = 0; i < segmSize; ++i) {
            leds[segmOffset + i] = color;
        }
        blur1d(leds, num_leds, segmOffset - width/2, segmOffset + width/2, 90);
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
