//
//void readMSGEQ7_mono() {
//
//  mapped_volume = 0.00;
////  factor = 0.00;
//  left_volume  = 0.00;
//  right_volume = 0.00;
//  mono_volume  = 0.00;
//
//  digitalWrite(reset, HIGH);
//  digitalWrite(reset, LOW);
//  delayMicroseconds(1);
//
//  for (int band = 0; band < 7; band++)
//  {
//    digitalWrite(strobe, LOW);
//    delayMicroseconds(35);
//
//    prev_value  = left[band];
//    left_value  = analogRead(left_in);
//    left_value  = constrain(left_value, filter_min, filter_max);
//    left_value  = map(left_value, filter_min, filter_max, 0, 255);
//    left[band]  = prev_value + (left_value - prev_value) * lowPass_audio;
//    left_volume += left[band];
//
//    //filter_min += (filter_min * EQadjust[band])
//
//    prev_value  = right[band];
//    right_value = analogRead(right_in);
//    right_value = constrain(right_value, filter_min, filter_max);
//    right_value = map(right_value, filter_min, filter_max, 0, 255);
//    right[band] = prev_value + (right_value - prev_value) * lowPass_audio;
//    right_volume += right[band];
//
//    mono[band]  = (left[band] + right[band]) * 0.5;
//    //mono[band] = mono[band] + (mono_val * EQadjust[band]);
//
////    mapped_volume += mono[band];
//
////    mapped[band] = mono[band] * factor;
//    //mapped[band] = MAPPED_AMPLITUDE;
//
//    digitalWrite(strobe, HIGH);
//    delayMicroseconds(1);
//
//  }
//
//  //  left_volume  /= 7;
//  //  right_volume /= 7;
//  mono_volume = (left_volume + right_volume) * 0.5;
////  factor = float(HALF_POS) / mapped_volume;
//
////  for (int band = 0; band < 7; band++)
////  {
////    half_MAPPED_AMPLITUDE = /*float(*/ mono[band] * factor;
////    mapped[band] = half_MAPPED_AMPLITUDE;
////
////    Serial.print(mapped[band]);
////    Serial.print("\t");
////  }
////  Serial.println();
//
//}

