#ifndef __GRADIENT_H__
#define __GRADIENT_H__

#include <ledfx_common.h>

struct gradient_params {
    uint32_t len;
    uint32_t colors[20];
};

void gradient(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    gradient_params* params = (gradient_params*)config->params;
    uint16_t start = 0;
    uint16_t len = int(num_leds/(params->len - 1));

    for(int i = 1; i < params->len; i++) {
        fill_gradient_RGB(leds, start, params->colors[i], \
                          start + len, params->colors[i + 1]);
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
