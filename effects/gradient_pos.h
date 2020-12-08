#ifndef __GRADIENT_POS_H__
#define __GRADIENT_POS_H__

#include <ledfx.h>

void gradient_pos(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const uint16_t offset = animation_t.params[0];
    // -1 because offset pixel also should counts
    const uint16_t len = offset + animation_t.params[1] - 1;

    fill_gradient_RGB(leds, offset, animation_t.params[2], \
                      len, animation_t.params[3]);
}

static struct animation_config gradient_pos_config = 
{
    .id = 0x53,
    .leds_update = gradient_pos,
    .num = 20,
};


#endif // __GRADIENT_POS_H__
