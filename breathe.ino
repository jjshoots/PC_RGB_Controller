void breathe_down(int R, int G, int B, float dim, int dura){
  float breathe_R, breathe_G, breathe_B;
  for(int i = 0; i <= 1 / dim; i++){
    breathe_R = check_zero(R - R * (i * dim));
    breathe_G = check_zero(G - G * (i * dim));
    breathe_B = check_zero(B - B * (i * dim));
    
    for(int j = 0; j < LED_COUNT; j++){
      leds.setPixelColor(j, (int)breathe_R, (int)breathe_G, (int)breathe_B);
    };
    leds.show();
    delay(dura);
  };
};

void breathe_up(int R, int G, int B, float dim, int dura){
  int breathe_R, breathe_G, breathe_B;
  for(int i = 1 / dim; i >= 0; i--){
    breathe_R = check_zero(R - R * (i * dim));
    breathe_G = check_zero(G - G * (i * dim));
    breathe_B = check_zero(B - B * (i * dim));
    
    for(int j = 0; j < LED_COUNT; j++){
      leds.setPixelColor(j, breathe_R, breathe_G, breathe_B);
    };
    leds.show();
    delay(dura);
  };
};


void rainbow_breathe(unsigned long cycles, int dura, float dim){
  for(unsigned long q = 0; q <= cycles; q++){
    breathe_up(glob_R, glob_G, glob_B, dim, dura);
    move_rainbow();
    breathe_down(glob_R, glob_G, glob_B, dim, dura);
    move_rainbow();
  };
};


