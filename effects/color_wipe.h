#ifndef __COLOR_WIPE_H__
#define __COLOR_WIPE_H__

#include <ledfx.h>

#define POSITION_IN_SECOND_HALF(i, p) (i >= (uint16_t)(p/2))
#define POSITION_IN_FIRST_HALF(i, p) (i < (uint16_t)(p/2))

void color_wipe()
{
    const ledfx_color color = ledfx_color_init(ledfx_get_param(0));

    uint32_t led_idx = 0;
    const uint32_t period = animation_t.num_leds*4;

    if(animation_t.iteration%4 == 0) {
        led_idx = (animation_t.iteration/4)%animation_t.num_leds;
    } else {
        return;
    }

    if(POSITION_IN_FIRST_HALF((animation_t.iteration/4)%period, period)) {
        ledfx_set_pixel(led_idx, color);
    }

    if(POSITION_IN_SECOND_HALF((animation_t.iteration/4)%period, period)) {
        ledfx_set_pixel(led_idx, 0);
    }
}

#endif // __COLOR_WIPE_H__
