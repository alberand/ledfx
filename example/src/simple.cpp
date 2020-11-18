#include <Arduino.h>
#include <FastLED.h>

#include "ledfx.h"

// How many leds in your strip?
#define NUM_LEDS 10
#define DATA_PIN 7

// Define the array of leds
CRGB leds[NUM_LEDS];

solid_params params;

void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

    params.color = 0xFF00FF;
    params.offset = 0;
    params.num = NUM_LEDS;

    ledfx_set_params(0x41, (void*)&params);
}

void loop() { 
    ledfx_effect(0x41, leds, NUM_LEDS);
    FastLED.show();
    delay(10);
}
