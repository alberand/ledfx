#ifndef __FIRE_H__
#define __FIRE_H__

#include <ledfx.h>

void fire(CRGB* leds, uint16_t num_leds, const struct animation_config* config)
{
    const uint32_t cooling = 55;
    const uint32_t sparking = 120;
    static byte heat[10];
    uint32_t cooldown = 0;

    if(num_leds > 10)
        num_leds = 10;

    // Step 1.  Cool down every cell a little
    for( uint32_t i = 0; i < num_leds; i++) {
        cooldown = random(0, ((cooling * 10) / num_leds) + 2);

        if(cooldown > heat[i]) {
            heat[i] = 0;
        } else {
            heat[i] = heat[i] - cooldown;
        }
    }

    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k = num_leds - 1; k >= 2; k--) {
        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }

    // Step 3.  Randomly ignite new 'sparks' near the bottom
    if( (uint32_t)random(255) < sparking ) {
        int y = random(7);
        heat[y] = heat[y] + random(160,255);
        //heat[y] = random(160,255);
    }

    // Step 4.  Convert heat to LED colors
    for( uint32_t j = 0; j < num_leds; j++) {

        byte temperature = heat[j];
        // Scale 'heat' down from 0-255 to 0-191
        byte t192 = round((temperature/255.0)*191);

        // calculate ramp up from
        byte heatramp = t192 & 0x3F; // 0..63
        heatramp <<= 2; // scale up to 0..252

        // figure out which third of the spectrum we're in:
        if( t192 > 0x80) {                     // hottest
            leds[j] = CRGB(255, 255, heatramp);
        } else if( t192 > 0x40 ) {             // middle
            leds[j] = CRGB(255, heatramp, 0);
        } else {                               // coolest
            leds[j] = CRGB(0, heatramp, 0);
        }
    }

}

static struct animation_config config = 
{
    .id = 0x51,
    .delay = 20,
    .leds_update = fire,
    .size = 0,
    .params = nullptr,
};


#endif // __FIRE_H__
