#ifndef __LEDFX_EFFECTS_H__
#define __LEDFX_EFFECTS_H__

#include <effects/rainbow.h>
#include <effects/solid.h>
#include <effects/blink.h>
#include <effects/color_wipe.h>
#include <effects/cylon.h>

#define CONFIGS_SIZE 5

static void (*effect_ptr[CONFIGS_SIZE])() = {
    &rainbow,
    &solid,
    &blink,
    &color_wipe,
    &cylon,
};

#endif // __LEDFX_EFFECTS_H__
