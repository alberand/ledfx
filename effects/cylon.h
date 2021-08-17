#ifndef __CYLON_H__
#define __CYLON_H__

#include <ledfx.h>

uint32_t HsvToRgb(uint8_t h, uint8_t s, uint8_t v)
{
	uint8_t r, g, b;
    unsigned char region, remainder, p, q, t;

    if (s == 0)
    {
        r = v;
        g = v;
        b = v;
    	return ((uint32_t)r << 16) | ((uint32_t)g << 8) | ((uint32_t)b);
    }

    region = h / 43;
    remainder = (h - (region * 43)) * 6; 

    p = (v * (255 - s)) >> 8;
    q = (v * (255 - ((s * remainder) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

    switch (region)
    {
        case 0:
            r = v; g = t; b = p;
            break;
        case 1:
            r = q; g = v; b = p;
            break;
        case 2:
            r = p; g = v; b = t;
            break;
        case 3:
            r = p; g = q; b = v;
            break;
        case 4:
            r = t; g = p; b = v;
            break;
        default:
            r = v; g = p; b = q;
            break;
    }

    return ((uint32_t)r << 16) | ((uint32_t)g << 8) | ((uint32_t)b);
}

void scale(ledfx_color* color, const uint8_t scale){
	color->r = ((uint16_t)color->r * (uint16_t)(scale) ) >> 8;
    color->g = ((uint16_t)color->g * (uint16_t)(scale) ) >> 8;
    color->b = ((uint16_t)color->b * (uint16_t)(scale) ) >> 8;
}

void cylon()
{
    static uint8_t hue = 0;
    const uint16_t num_leds = animation_t.num_leds;
    const uint16_t iteration = animation_t.iteration%(2*num_leds);

    for(uint16_t i = 0; i < num_leds; i++) {
		scale(&animation_t.leds[i], 250);
    }

    
    if(iteration < num_leds)
        ledfx_set_pixel(iteration, HsvToRgb(hue++, 255, 255));

    if(num_leds < iteration && iteration < (2*num_leds))
        ledfx_set_pixel(2*num_leds - iteration, HsvToRgb(hue++, 255, 255));
}

#endif // __CYLON_H__
