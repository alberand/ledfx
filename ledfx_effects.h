#ifndef __LEDFX_EFFECTS_H__
#define __LEDFX_EFFECTS_H__

#include <effects/fire.h>
#include <effects/color_wipe.h>
#include <effects/fadeinout.h>
#include <effects/rainbow.h>
#include <effects/rainbow_classic.h>
#include <effects/bpm.h>
#include <effects/confetti.h>
#include <effects/stroboscope.h>
#include <effects/twinkle.h>
#include <effects/segments.h>
#include <effects/snowsparkle.h>
#include <effects/train.h>
#include <effects/juggle.h>
#include <effects/solid.h>
#include <effects/sinelon.h>
#include <effects/gradient.h>
#include <effects/cylon.h>
#include <effects/theater_chase.h>

#define CONFIGS_SIZE 18

static struct animation_config* configs[CONFIGS_SIZE] = {
    &fire_config,
    &color_wipe_config,
    &fadeinout_config,
    &rainbow_config,
    &rainbow_classic_config,
    &bpm_config,
    &confetti_config,
    &stroboscope_config,
    &twinkle_config,
    &segments_config,
    &snowsparkle_config,
    &train_config,
    &juggle_config,
    &solid_config,
    &sinelon_config,
    &gradient_config,
    &cylon_config,
    &theater_chase_config,
};

#endif // __LEDFX_EFFECTS_H__
