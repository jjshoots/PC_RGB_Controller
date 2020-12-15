void cyclone_up(int R, int G, int B, float dim, int dura){
  int s_R = (R * dim) + 1;
  int s_G = (G * dim) + 1;
  int s_B = (B * dim) + 1;
  for(int i = 0 - (1.2 / dim); i < LED_COUNT + (1.2 / dim); i++){
    clearLEDs();
    for(int j = 0; j < LED_COUNT / 2; j++){
      int temp_R = check_zero(R - (s_R * j));
      int temp_G = check_zero(G - (s_G * j));
      int temp_B = check_zero(B - (s_B * j));
      int temp_loc1 = i + j;
      int temp_loc2 = i - j;

      if(temp_loc1 > 0 && temp_loc1 < LED_COUNT){
        leds.setPixelColor(temp_loc1, temp_R, temp_G, temp_B);
      };
      if(temp_loc2 > 0 && temp_loc2 < LED_COUNT){
        leds.setPixelColor(temp_loc2, temp_R, temp_G, temp_B);
      };
    };
    leds.show();
    delay(dura);
  };
};

void cyclone_down(int R, int G, int B, float dim, int dura){
  int s_R = (R * dim) + 1;
  int s_G = (G * dim) + 1;
  int s_B = (B * dim) + 1;
  for(int i = LED_COUNT + (1.2 / dim); i > 0 - (1.2 / dim); i--){
    clearLEDs();
    for(int j = 0; j < LED_COUNT / 2; j++){
      int temp_R = check_zero(R - (s_R * j));
      int temp_G = check_zero(G - (s_G * j));
      int temp_B = check_zero(B - (s_B * j));
      int temp_loc1 = i + j;
      int temp_loc2 = i - j;

      if(temp_loc1 > 0 && temp_loc1 < LED_COUNT){
        leds.setPixelColor(temp_loc1, temp_R, temp_G, temp_B);
      };
      if(temp_loc2 > 0 && temp_loc2 < LED_COUNT){
        leds.setPixelColor(temp_loc2, temp_R, temp_G, temp_B);
      };
    };
    leds.show();
    delay(dura);
  };
};

void rainbow_cyclone(unsigned long cycles, int dura, float dim){
  for(unsigned long q = 0; q <= cycles; q++){
    move_rainbow();
    cyclone_up(glob_R, glob_G, glob_B, dim, dura);
    cyclone_down(glob_R, glob_G, glob_B, dim, dura);
  };
};

