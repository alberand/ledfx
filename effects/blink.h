#ifndef __BLINK_H__
#define __BLINK_H__

#include <ledfx.h>
#include <math.h>

void blink()
{
    const ledfx_color color = ledfx_color_init(ledfx_get_param(0));
    const float smoothness = (float)ledfx_get_param(1);
    const uint16_t pause = (uint16_t)ledfx_get_param(2);

    // reset the loop
    if(animation_t.iteration == (uint16_t)smoothness + pause){
        animation_t.iteration = 0;
    }

    // pause between blinks
    if(animation_t.iteration > (uint16_t)smoothness){
        return;
    }

#define GAUSS

#ifdef CIRCLE
    const float bness = 255.0*sqrt(1.0 -  pow(abs((2.0*(animation_t.iteration/smoothness))-1.0),2.0));
#endif

#ifdef TRIAN
    const float bness = 255.0*(1.0 -  abs((2.0*(animation_t.iteration/smoothness))-1.0));;
#endif

#ifdef GAUSS
    const float gamma = 0.14;
    const float beta = 0.5; 
    const float bness = 255.0*(exp(-(pow(((animation_t.iteration/smoothness)-beta)/gamma,2.0))/2.0));
#endif

    ledfx_set_brightness(bness);
    ledfx_set_all(color);
}

#endif // __BLINK_H__
