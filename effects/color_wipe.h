#ifndef __COLOR_WIPE_H__
#define __COLOR_WIPE_H__

#include <ledfx.h>

void color_wipe(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const CRGB color = config->params[0];

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

static struct animation_config config =
{
    .id = 0x4e,
    .delay = 10,
    .leds_update = color_wipe,
    .size = 1,
    .params = nullptr,
};


#endif // __COLOR_WIPE_H__
