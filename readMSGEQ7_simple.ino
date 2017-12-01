
void readMSGEQ7_simple() {
  
  digitalWrite(reset, HIGH);
  digitalWrite(reset, LOW);
  delayMicroseconds(1);

  for (int band = 0; band < 7; band++)
  {
    digitalWrite(strobe, LOW);
    delayMicroseconds(35);

    prev_value  = left[band];
    left_value  = analogRead(left_in);
    left_value  = constrain(left_value, filter_min, filter_max);
    left_value  = map(left_value, filter_min, filter_max, value_floor, value_ceiling);
    left[band]  = prev_value + (left_value - prev_value) * lowPass_audio;
    left_volume += left[band];

    prev_value  = right[band];
    right_value = analogRead(right_in);
    right_value = constrain(right_value, filter_min, filter_max);
    right_value = map(right_value, filter_min, filter_max, value_floor, value_ceiling);
    right[band] = prev_value + (right_value - prev_value) * lowPass_audio;
    right_volume += right[band];

    mono[band]  = (left[band] + right[band]) * 0.5;

    digitalWrite(strobe, HIGH);
    delayMicroseconds(1);

  }

}

