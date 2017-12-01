void audio_spectrum_stereo() {
  int winch_segment_length_default = 47;

  uint16_t left_pos = 733;
  uint16_t left_point = 733;
  uint16_t right_pos = 170;
  uint16_t right_point = 170;

  for (int i = 0; i < 170 ; i++) {
    leds[i] = CHSV(0, 255, mono[0]);
  }

  int current_hue = 0;
  int next_hue = 47;

  for (uint8_t band = 1; band < 7; band++) {

    left_point -= winch_segment_length_default;
    right_point += winch_segment_length_default;

    int current_left_brightness = left[band];
    int current_right_brightness = right[band];
    int next_left_brightness = left[band + 1];
    int next_right_brightness = right[band + 1];

    if(band == 6) {
      next_left_brightness = left[band];
      next_right_brightness = right[band];
      next_hue = current_hue;
    }

    fill_gradient(leds, left_pos, CHSV(current_hue, 255, current_left_brightness), left_point, CHSV(next_hue, 255, next_left_brightness), SHORTEST_HUES);
    fill_gradient(leds, right_pos, CHSV(current_hue, 255, current_right_brightness), right_point, CHSV(next_hue, 255, next_right_brightness), SHORTEST_HUES);

    current_hue += 45;
    next_hue += 45;
    left_pos = left_point;
    right_pos = right_point;
  }
  blur1d(leds, NUM_LEDS, 14);
}

