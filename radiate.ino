//void radiate()
//{
//  EVERY_N_MILLISECONDS(20) {
//    readMSGEQ7_mono();
//  }
//
//  hue += (mono[0] * 0.01);
//  leds[HALF_POS] = CRGB(mono[0], mono[3], mono[6]);
//  //leds[HALF_POS] = CHSV(hue, 255, mono[0]);
//
//  leds[HALF_POS].fadeToBlackBy(30);
//  //move to the left
//
//  for (int i = NUM_LEDS - 1; i > HALF_POS; i--) {
//    leds[i] = leds[i - 1];
//  }
//  // move to the right
//  for (int i = 0; i < HALF_POS; i++) {
//    leds[i] = leds[i + 1];
//  }
//  //blur1d(leds, NUM_LEDS, 1);
//  FastLED.show();
//}
int prev_bass_l = 0;
int prev_mids_l = 0;
int prev_high_l = 0;
int prev_bass_r = 0;
int prev_mids_r = 0;
int prev_high_r = 0;

int bass_l;
int mids_l;
int high_l;
int bass_r;
int mids_r;
int high_r;

int WINCH_TEMP_HALF = HALF_POS;

void radiate() {

//EVERY_N_MILLISECONDS(10) {
//    readMSGEQ7_simple();
//
//}

//  leds[WINCH_TEMP_HALF].nscale8(120);
//  leds[HALF_POS + 1].nscale8(120);


  //  prev_bass_l = bass_l;
  //  prev_mids_l = mids_l;
  //  prev_high_l = high_l;
  //  prev_bass_r = bass_r;
  //  prev_mids_r = mids_r;
  //  prev_high_r = high_r;

//  bass_l = left[0];
//  mids_l = left[3];
//  high_l = left[6];

  bass_r = mono[0];
  mids_r = mono[3];
  high_r = (mono[6] + mono[5]) * 0.5;

  //  bass_l  = prev_bass_l + (bass_l - prev_bass_l)  * low_pass;
  //  mids_l  = prev_mids_l + (mids_l - prev_mids_l)  * low_pass;
  //  high_l  = prev_high_l + (high_l - prev_high_l)  * low_pass;
  //
  //  bass_r  = prev_bass_r + (bass_r - prev_bass_r)  * low_pass;
  //  mids_r  = prev_mids_r + (mids_r - prev_mids_r)  * low_pass;
  //  high_r  = prev_high_r + (high_r - prev_high_r)  * low_pass;

  //    if (bass_l < 25) {
  //      bass_l = 0;
  //    }
  //    if (mids_l < 25) {
  //      mids_l = 0;
  //    }
  //    if (high_l < 25) {
  //      high_l = 0;
  //    }
  //
  //    if (bass_r < 25) {
  //      bass_r = 0;
  //    }
  //    if (mids_r < 25) {
  //      mids_r = 0;
  //    }
  //    if (high_r < 25) {
  //      high_r = 0;
  //    }

  //    uint16_t left_fft_average  = (bass_l + mids_l + high_l) / 3;
  //    uint16_t right_fft_average = (bass_r + mids_r + high_r) / 3;

//  leds[HALF_POS + 1] = CRGB(bass_l, mids_l, high_l);
  leds[WINCH_TEMP_HALF] = CRGB(bass_r, mids_r, high_r);

      leds[WINCH_TEMP_HALF].maximizeBrightness();
  //    leds[half_pos + 1].maximizeBrightness();



  //  EVERY_N_MILLISECONDS(1) {
  for (int i = NUM_LEDS - 1; i > WINCH_TEMP_HALF; i--) {
    leds[i].blue = leds[i - 1].blue;
  }
  for (int i = 0; i < WINCH_TEMP_HALF + 1; i++) {
    leds[i].blue = leds[i + 1].blue;
  }
  //  }

  EVERY_N_MILLISECONDS(18) {
    for (int i = NUM_LEDS - 1; i > WINCH_TEMP_HALF; i--) {
      leds[i].green = leds[i - 1].green;
    }
    for (int i = 0; i < WINCH_TEMP_HALF + 1; i++) {
      leds[i].green = leds[i + 1].green;
    }
  }

  EVERY_N_MILLISECONDS(30) {
    for (int i = NUM_LEDS - 1; i > WINCH_TEMP_HALF; i--) {
      leds[i].red = leds[i - 1].red;
    }
    for (int i = 0; i < WINCH_TEMP_HALF + 1; i++) {
      leds[i].red = leds[i + 1].red;
    }
  }

  blur1d(leds, NUM_LEDS, 100);

//  FastLED.show();
}

