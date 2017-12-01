void print_fft_stereo() {
  for (int band = 6; band > -1; band--) {
    Serial.print(left[band]);
    Serial.print("\t");
  }
  Serial.print("|\t");
  for (int band = 0; band < 7; band++) {
    Serial.print(right[band]);
    Serial.print("\t");
  }
  Serial.println();
}

