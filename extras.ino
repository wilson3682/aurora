/*

     //radiate();
  //  audio_middle_fast();
  //flex_stereo();
  //vu();
  //mode();


void audio_spectrum_stereo() {
  int winch_segment_length_default = 52;

  nscale8(leds, NUM_LEDS, 125);

  uint16_t left_pos = HALF_POS;
  uint16_t left_point = HALF_POS;
  uint16_t right_pos = HALF_POS;
  uint16_t right_point = HALF_POS;

  for (uint8_t band = 0; band < 7; band++) {

    left_point -= winch_segment_length_default;
    right_point += winch_segment_length_default;

    int current_left_brightness = left[band];
    int current_right_brightness = right[band];


    for (uint16_t i = left_pos; i > left_point; i--) {
      leds[i] += CHSV(band * 36, 255, current_left_brightness);
    }
    for (uint16_t i = right_pos; i < right_point; i++) {
      leds[i] += CHSV(band * 36, 255, current_right_brightness);
    }

    left_pos = left_point;
    right_pos = right_point;
  }
}

*/
