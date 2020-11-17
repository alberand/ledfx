#pragma once

#include <stdint.h>

#define FASTLED_ALLOW_INTERRUPTS 1
#include <FastLED.h>

#define POSITION_IN_MIDDLE(i, p) (i == (uint16_t)int(p/2))
#define POSITION_IN_SECOND_HALF(i, p) (i >= (uint16_t)int(p/2))
#define POSITION_IN_FIRST_HALF(i, p) (i < (uint16_t)int(p/2))
#define POSITION_IN_FIRST_QUARTER(i, p) (i < (uint16_t)int(p/4))
#define POSITION_IN_SECOND_QUARTER(i, p) ((uint16_t)int(p/4) <= i < 2*(uint16_t)int(p/4))
#define POSITION_IN_THIRD_QUARTER(i, p) (2*(uint16_t)int(p/4) <= i < 3*(uint16_t)int(p/4))
#define POSITION_IN_FORTH_QUARTER(i, p) (3*(uint16_t)int(p/4) <= i < p)

struct animation_config
{
    uint8_t id;
    uint16_t delay;
    void (*leds_update)(CRGB*, uint16_t, const struct animation_config*);
    // Size of the received data in bytes
    uint8_t size;
    // Array for animation parameters
    uint32_t* params;
};

struct animation_state
{
    uint16_t iteration;
};

void animation_state_reset();
void animation_state_update(CRGB* leds, uint16_t num_leds,
                            const struct animation_config* config);

void fadeall(CRGB* leds, uint16_t num_leds, const struct animation_config* config);

static struct animation_config configs[] = {};
