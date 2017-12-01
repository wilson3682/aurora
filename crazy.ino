float fhue;
void crazy() {
  int volume = map(mono[0], 0, 255, 100, 255);
  fhue += (mono[0] * 0.02);
  fill_solid(leds, NUM_LEDS, CHSV(fhue, 255, mono[0]));
}

