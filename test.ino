void test() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
    Serial.println(i);
    FastLED.show();
    delay(500);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}

