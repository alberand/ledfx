#ifndef __FADEINOUT_H__
#define __FADEINOUT_H__

#include <ledfx.h>

void fadeinout(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const CRGB color = animation_t.params[0];

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
    .leds_update = fadeinout,
    .num = 1,
};


#endif // __FADEINOUT_H__
