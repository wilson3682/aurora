
//void audio_middle() {
//  //  EVERY_N_MILLISECONDS(100) {
//  //    hue++;
//  //  }
//  //Serial.println("here");
//
//  nscale8(leds, NUM_LEDS, 200); // stereo_peak
//  readMSGEQ7_mono();
//
//  pos = HALF_POS;
//  point = HALF_POS;
//  hue = 0;
//
//  for (uint8_t band = 0; band < 7; band++) {
//    hue += 30;
//    point += segment_length * 0.5;
//    curr_brightness = mono[band];
//
//    for (int i = pos; i < point; i++) {
//      leds[i] += CHSV(hue, 255, curr_brightness);
//    }
//    pos = point;
//  }
//
//  for (int i = HALF_POS; i > 0; i--) {
//    leds[i] = leds[HALF_POS - (i - HALF_POS)];
//  }
//  blur1d(leds, NUM_LEDS, 130);
//  FastLED.show();
//}
//uint8_t next_hue;
//uint8_t next_brightness;

//uint16_t left_pos;
//uint16_t left_point;
//uint16_t right_pos;
//uint16_t right_point;
//
//uint8_t left_current_brightness;
//uint8_t right_current_brightness;
//uint8_t left_next_brightness;
//uint8_t right_next_brightness;

//void audio_middle_fast() {
//
//  nscale8(leds, NUM_LEDS, 200); // stereo_peak
//  readMSGEQ7_simple();
//
//  left_pos = HALF_POS;
//  left_point = HALF_POS;
//  right_pos = HALF_POS;
//  right_point = HALF_POS;
//
//  hue = 0;
//  next_hue = 0;
//
//  for (uint8_t band = 0; band < 7; band++) {
//    next_hue = hue + 30;
//
//    left_point += segment_length_half;
//    right_point -= segment_length_half;
//
//    left_current_brightness = left[band];
//    left_next_brightness = left[band + 1];
//    right_current_brightness = right[band];
//    right_next_brightness = right[band + 1];
//
//    if (band == 6) {
//      left_next_brightness = left[band];
//      right_next_brightness = right[band];
//    }
//
//    fill_gradient(leds, left_pos,  CHSV(hue, 255, left_current_brightness),  left_point,  CHSV(next_hue, 255, left_next_brightness),  SHORTEST_HUES);
//    fill_gradient(leds, right_pos,  CHSV(hue, 255, right_current_brightness),  right_point,  CHSV(next_hue, 255, right_next_brightness),  SHORTEST_HUES);
//
//    left_pos = left_point;
//    right_pos = right_point;
//
//    hue = next_hue;
//  }
//
//  //  for (int i = HALF_POS; i > 0; i--) {
//  //    leds[i] = leds[HALF_POS - (i - HALF_POS)];
//  //  }
//  blur1d(leds, NUM_LEDS, 130);
//  FastLED.show();
//}

