#ifndef __GRADIENT_H__
#define __GRADIENT_H__

#include <ledfx.h>

void gradient(ledfx_RGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    uint16_t start = 0;
    uint16_t len = int(num_leds/(animation_t.params[0] - 1));

    for(int i = 1; i < animation_t.params[0]; i++) {
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
