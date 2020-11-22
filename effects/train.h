#ifndef __TRAIN_H__
#define __TRAIN_H__

#include <ledfx.h>

void train(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const CRGB color = animation_t.params[0];

    if(animation_t.iteration >= (num_leds*2)) {
        animation_t.iteration  = 0;
    }

    uint16_t position = animation_t.iteration;

    for(uint16_t i = 0; i < num_leds; i++) {
        const uint8_t R = ((sin(i + position) * 127 + 128)/255)*color.red;
        const uint8_t G = ((sin(i + position) * 127 + 128)/255)*color.green;
        const uint8_t B = ((sin(i + position) * 127 + 128)/255)*color.blue;
        leds[i] = CRGB(R, G, B);
    }
}

static struct animation_config train_config =
{
    .id = 0x4d,
    .leds_update = train,
    .num = 1,
};

#endif // __TRAIN_H__
