void twink(int R, int G, int B, int intensity, int dura){
  for(int i = 0; i < LED_COUNT; i++){
    if(twink_R[i] > 0){
      twink_R[i] -= SKIP;
    };
    if(twink_G[i] > 0){
      twink_G[i] -= SKIP;
    };
    if(twink_B[i] > 0){
      twink_B[i] -= SKIP;
    };
    leds.setPixelColor(i, twink_R[i], twink_G[i], twink_B[i]);
  };

  for(int i = 0; i <= intensity; i++){
    if(rand() % MAX/20 <= 1){
      int temp = rand() % LED_COUNT;
      twink_R[temp] = R;
      twink_G[temp] = G;
      twink_B[temp] = B;
    };
  };
  leds.show();
  delay(dura);
};

void rainbow_twink(unsigned long cycles, int dura, int intensity){
  for(unsigned long q = 0; q <= cycles; q++){
    move_rainbow();
    for(int g = 0; g <= MAX / 10; g++){
      twink(glob_R, glob_G, glob_B, intensity, dura);
    };
  };
};

