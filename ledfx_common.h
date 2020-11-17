#ifndef __LEDFX_COMMON_H__
#define __LEDFX_COMMON_H__

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

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

static struct animation_state animation_t;

#endif // __LEDFX_COMMON_H__
