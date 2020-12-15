void stat(int R, int G, int B, int dura){
  for(int i = 0; i < LED_COUNT; i++){
    leds.setPixelColor(i, R, G, B);
  };
  leds.show();
  delay(dura);
};

void rainbow_stat(unsigned long cycles, int dura){
  for(unsigned long q = 0; q <= cycles; q++){
    for(int g = 0; g <= MAX / 10; g++){
      stat(glob_R, glob_G, glob_B, dura);
    };
    move_rainbow();  
  };
};

