#include <Arduino.h>
#include <FastLED.h>

#include "ledfx.h"

// How many leds in your strip?
#define NUM_LEDS 10

#define DATA_PIN 7

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() { 
    ledfx_effect(0x48, leds, NUM_LEDS);
    FastLED.show();
    delay(ledfx_get_config(0x48)->delay);
  // Turn the LED on, then pause
  // leds[0] = CRGB::Red;
  // FastLED.show();
  // delay(500);
  // Now turn the LED off, then pause
  // leds[0] = CRGB::Black;
  // FastLED.show();
  // delay(500);
}
