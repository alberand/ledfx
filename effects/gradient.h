#ifndef __GRADIENT_H__
#define __GRADIENT_H__

#include <ledfx.h>

void gradient(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    uint16_t start = 0;
    uint16_t len = int(num_leds/(config->params[0] - 1));

    for(int i = 1; i < config->params[0]; i++) {
        fill_gradient_RGB(leds, start, config->params[i], \
                          start + len, config->params[i + 1]);
        start = start + len;
    }
}

static struct animation_config gradient_config = 
{
    .id = 0x42,
    .delay = 10,
    .leds_update = gradient,
    .size = 20,
    .params = nullptr,
};


#endif // __GRADIENT_H__
