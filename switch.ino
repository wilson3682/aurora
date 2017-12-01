void mode() {

  check_regular_button();

  switch (effect) {
    case 0:
      audio_spectrum_stereo();
      FastLED.setBrightness(255);
      break;
    case 1:
      radiate();
      FastLED.setBrightness(255);
      break;
    case 2:
      rainbow();
      FastLED.setBrightness(150);
      break;
    case 3:
      crazy();
      break;
    default:
      effect = 0;
      break;
  }
}

void check_regular_button() {

  buttonReading = digitalRead(BUTTON);
  if (buttonReading != lastButtonState) {
    lastDebounceTime = millis(); // reset debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (buttonReading != buttonState) {
      buttonState = buttonReading;

      if (buttonState == LOW) {
        effect++;
        if (effect > num_modes - 1) {
          effect = 0;
        }
      }
    }
  }
  lastButtonState = buttonReading;
}

