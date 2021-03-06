#ifndef __GRADIENT_H__
#define __GRADIENT_H__

#include <ledfx.h>

void gradient(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    uint16_t start = 0;
    uint16_t len = (num_leds/(animation_t.num - 1));

    for(uint8_t i = 0; i < animation_t.num - 1; i++) {
        fill_gradient_RGB(leds, start, animation_t.params[i], \
                          start + len, animation_t.params[i + 1]);
        start = start + len;
    }

}

static struct animation_config gradient_config = 
{
    .id = 0x42,
    .leds_update = gradient,
    .num = 20,
};


#endif // __GRADIENT_H__
