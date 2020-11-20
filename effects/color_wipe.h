#ifndef __COLOR_WIPE_H__
#define __COLOR_WIPE_H__

#include <ledfx.h>

#define POSITION_IN_SECOND_HALF(i, p) (i >= (uint16_t)int(p/2))
#define POSITION_IN_FIRST_HALF(i, p) (i < (uint16_t)int(p/2))

void color_wipe(RGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const CRGB color = animation_t.params[0];

    uint32_t led_idx = 0;
    uint32_t period = num_leds*4;

    if(animation_t.iteration%4 == 0) {
        led_idx = (animation_t.iteration/4)%num_leds;
    } else {
        return;
    }

    if(POSITION_IN_FIRST_HALF((animation_t.iteration/4)%period, period)) {
        leds[led_idx] = color;
    }

    if(POSITION_IN_SECOND_HALF((animation_t.iteration/4)%period, period)) {
        leds[led_idx] = 0;
    }
}

static struct animation_config color_wipe_config =
{
    .id = 0x4e,
    .leds_update = color_wipe,
    .num = 1,
};


#endif // __COLOR_WIPE_H__
