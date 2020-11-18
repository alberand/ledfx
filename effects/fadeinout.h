#ifndef __FADEINOUT_H__
#define __FADEINOUT_H__

#include <ledfx_common.h>

struct fadeinout_params {
    uint32_t color;
};

void fadeinout(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    fadeinout_params* params = (fadeinout_params*)config->params;
    const CRGB color = params->color;

    animation_t.iteration++;
    if(animation_t.iteration < 128) {
        for(uint16_t i = 0; i < num_leds; i++) {
            leds[i].nscale8(250);
        }
    } else if(animation_t.iteration < 256) {
        for(uint16_t i = 0; i < num_leds; i++) {
            leds[i].red = color.red * (animation_t.iteration - 127)/127;
            leds[i].green = color.green * (animation_t.iteration - 127)/127;
            leds[i].blue = color.blue * (animation_t.iteration - 127)/127;
        }
    } else {
        animation_t.iteration = 0;
    }
}

static struct animation_config fadeinout_config = 
{
    .id = 0x4a,
    .delay = 10,
    .leds_update = fadeinout,
    .size = 1,
    .params = nullptr,
};


#endif // __FADEINOUT_H__
