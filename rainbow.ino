void cyclic(int START_R, int START_G, int START_B, int g_state){
  int R = START_R, G = START_G, B = START_B;
  int state = g_state;
  for(int i = 0; i < LED_COUNT; i++){
    leds.setPixelColor(i, R, G, B);
    if(R >= MAX){
      state = 1;
    };
    if(G >= MAX){
      state = 2;
    };
    if(B >= MAX){
      state = 3;
    };

    if(state == 1){
     R -= SKIP;
     G += SKIP;
    }else
    if(state == 2){
     G -= SKIP;
     B += SKIP;
    }else
    if(state == 3){
     B -= SKIP;
     R += SKIP;
    };
  };
};

void rainbow(unsigned long cycles, int dura){
  for(unsigned long q = 0; q <= cycles; q++){
    move_rainbow();
    for(int g = 0; g <= MAX / 10; g++){
      cyclic(glob_R, glob_G, glob_B, glob_state);
    };
    leds.show();
    delay(dura);
  };
};










