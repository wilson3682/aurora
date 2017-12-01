//void rainbow_noise() {
//  changePalette();
//  for (int i = 0; i < NUM_LEDS; i++) {                                     // Just ONE loop to fill up the LED array as all of the pixels change.
//    uint8_t index = inoise8(i * scale, dist + i * scale, z) % 255;            // Get a value from the noise function. I'm using both x and y axis.
//    leds[i] = ColorFromPalette(gCurrentPalette, index, 255, LINEARBLEND);   // With that value, look up the 8 bit colour palette value and assign it to the current LED.
//  }
//  //dist += beatsin8(10, 1, 4);
//  z++;     
//  FastLED.show();
//}

