#include "leds.hpp"
#include "common.hpp"

static struct animation_state animation_t;

void animation_state_reset()
{
    animation_t.iteration = 0;
}

void animation_state_update(CRGB* leds, uint16_t num_leds,
                            const struct animation_config* config)
{
    if(config != NULL) {
        config->leds_update(leds, num_leds, config);
    }

    animation_t.iteration++;
}

void fadeall(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    for(uint16_t i = 0; i < num_leds; i++) {
        leds[i].nscale8(250);
    }
}
