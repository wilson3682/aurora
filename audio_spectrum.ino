////uint16_t segment_length = NUM_LEDS / 7;
//uint8_t segment_length = 60;
//
//float curr_brightness;
//float prev_brightness_left;
//float prev_brightness_right;
//float nxt_brightness;
//float prev_brightness_k_left;
//float prev_brightness_k_right;

void audio_spectrum() {
  EVERY_N_MILLISECONDS(100) {
    hue++;
  }
  //Serial.println("here");

  nscale8(leds, NUM_LEDS, 175); // stereo_peak
  readMSGEQ7_simple();

  uint16_t pos = 0;
  uint16_t point = 0;
 //hue = 0;

  for (uint8_t band = 0; band < 7; band++) {
    point += segment_length;

    //    prev_brightness_left = mono[band];
    //    prev_brightness_k_left = mono[band + 1];
    curr_brightness = mono[band];
    //curr_brightness  = prev_brightness_left + (curr_brightness - prev_brightness_left)  * 0.14;
    //mono[band] = curr_brightness;

    for (uint16_t i = pos; i < point; i++) {
      //colorIndex_twelve = i * palette_index_increment_twelve;
      //leds[i] += ColorFromPalette12( gCurrentPalette, colorIndex_twelve, curr_brightness, LINEARBLEND);
      //leds[i] += CHSV(i * 0.5, 255, curr_brightness);
      leds[i] += CHSV(i * 0.5, 255, curr_brightness);


    }

    //hue += 60;
    pos = point;
  }

  blur1d(leds, NUM_LEDS, 130);
  FastLED.show();
}

