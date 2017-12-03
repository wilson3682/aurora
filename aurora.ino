#include "FastLED.h"

#define NUM_LEDS     734
#define DATA_PIN     7
#define STRIP_TYPE   WS2812B
CRGB leds[NUM_LEDS];
#define BRIGHTNESS  255
int HALF_POS = 367;
int WINCH_HALF = 64;

#define left_in     0
#define right_in    1
int   strobe        = 4;
int   reset         = 5;
int   curr_value    = 0;
int   prev_value    = 0;
int   filter_min    = 50; // 93 as a base
int   filter_max    = 1000;
int   value_floor   = 0; // anything other than 0 hurts certain math
int   value_ceiling = 255;
float lowPass_audio = 0.30; // higher = more responsive but brightness is less smooth
int   left_volume   = 0;
int   right_volume  = 0;
int   mono_volume   = 0;
int   mono_val      = 0;
int   left_value;
int   right_value;
int   left[7];
int   right[7];
int   mono[7];
int   mapped[7];
int   MAPPED_AMPLITUDE;
int   half_MAPPED_AMPLITUDE;
int   ledindex = 0;

//uint16_t segment_length = NUM_LEDS / 7;
uint8_t segment_length = 60;
uint16_t segment_length_half = floor(NUM_LEDS / 14);

float curr_brightness;
float prev_brightness_left;
float prev_brightness_right;
float nxt_brightness;
float prev_brightness_k_left;
float prev_brightness_k_right;


uint8_t next_hue;
//uint8_t next_brightness;

uint16_t left_pos;
uint16_t left_point;
uint16_t right_pos;
uint16_t right_point;

uint8_t left_current_brightness;
uint8_t right_current_brightness;
uint8_t left_next_brightness;
uint8_t right_next_brightness;

int pos;
int point;

float mapped_volume = 0.00f;
float factor = 0.00f;

int hue = 0;
int saturation = 255;
int brightness;

const uint8_t BUTTON = 2;

int num_modes = 4;

int effect = 0;

uint16_t buttonReading;
uint8_t buttonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 10;
uint8_t lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  delay(200);
  InitMSGEQ7();
  InitWS2812B();

  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH);
}

void InitMSGEQ7() {
  analogReference(DEFAULT);
  pinMode(reset, OUTPUT);
  pinMode(strobe, OUTPUT);
  pinMode(left_in, INPUT);
  pinMode(right_in, INPUT);
  digitalWrite(reset, LOW);
  digitalWrite(strobe, LOW);
  delay(1);
  //RESET MSGEQ7
  digitalWrite(reset,  HIGH);
  delay(1);
  digitalWrite(reset,  LOW);
  digitalWrite(strobe, HIGH);
  delay(1);
}

void InitWS2812B() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  for (int i = 0; i < NUM_LEDS; i++) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
  FastLED.show();
  FastLED.delay(100);
}

void loop() {

  readMSGEQ7_simple();
  // print_fft_stereo();
  mode();

  FastLED.show();

}

