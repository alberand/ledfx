#ifndef __RAINBOW_CLASSIC_H__
#define __RAINBOW_CLASSIC_H__

#include <ledfx.h>

void rainbow_classic(ledfx_RGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    uint16_t i;
    static byte c[3];

    if(animation_t.iteration >= (256*5)) {
        animation_t.iteration  = 0;
    }

    for(i=0; i< num_leds; i++) {
        byte pos = ((i * 256 / num_leds) + animation_t.iteration) & 255;

        if(pos < 85) {
            c[0]=pos * 3;
            c[1]=255 - pos * 3;
            c[2]=0;
        } else if(pos < 170) {
            pos -= 85;
            c[0]=255 - pos * 3;
            c[1]=0;
            c[2]=pos * 3;
        } else {
            pos -= 170;
            c[0]=0;
            c[1]=pos * 3;
            c[2]=255 - pos * 3;
        }

        leds[i] = ledfx_color(c[0], c[1], c[2]);
    }
}

static struct animation_config rainbow_classic_config = 
{
    .id = 0x4f,
    .leds_update = rainbow_classic,
    .num = 0,
};


#endif // __RAINBOW_CLASSIC_H__
