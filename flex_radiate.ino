//float flex_low_pass_stereo = 0.20;
//
//void flex_stereo() {
//
//  //changePalette();
//
//  //fadeToBlackBy(leds, NUM_LEDS, 12);
//  nscale8(leds, NUM_LEDS, 170);
//  //flex_low_pass_stereo = 0.20;
//
//  readMSGEQ7_mono();
//
//  uint16_t left_pos    = HALF_POS;
//  uint16_t left_point  = HALF_POS;
//  uint16_t right_pos   = HALF_POS;
//  uint16_t right_point = HALF_POS;
//  hue = 0;
//  for (int band = 0; band < 7; band++) {
//    hue += 30;
//    
//    left_point -= mapped[band];
//    right_point += mapped[band];
//
//    left_current_brightness  = mono[band];
//    right_current_brightness = left_current_brightness;
//
//    if (band == 6) { // prevent from drawing outside of strip dimensions
//      left_point = 0;
//      right_point = NUM_LEDS - 1;
//    }
//
//    for (uint16_t i = left_pos; i > left_point; i--) {
//      leds[i] += CHSV(hue, 255, left_current_brightness);
//    }
//    for (uint16_t i = right_pos; i < right_point; i++) {
//      leds[i] += CHSV(hue, 255, left_current_brightness);
//    }
//
//    left_pos = left_point;
//    right_pos = left_pos;
//  }
//  
//  blur1d(leds, NUM_LEDS, 50);
//  FastLED.show();
//}

