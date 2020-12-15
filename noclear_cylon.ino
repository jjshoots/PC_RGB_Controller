void cyclone_up_noclear(int f_R, int f_G, int f_B, int t_R, int t_G, int t_B, int R, int G, int B, float dim, int dura){
  int s_R = (R * dim) + 1;
  int s_G = (G * dim) + 1;
  int s_B = (B * dim) + 1;
  
  for(int i = 0 - (1.2 / dim); i < LED_COUNT + (1.2 / dim); i++){
    for(int j = 0; j < LED_COUNT / 2; j++){
      int temp_R = check_zero(R - (s_R * j));
      int temp_G = check_zero(G - (s_G * j));
      int temp_B = check_zero(B - (s_B * j));
      int temp_loc1 = i + j;
      int temp_loc2 = i - j;

      if(temp_loc1 > 0 && temp_loc1 < LED_COUNT){
        if(temp_R == 0 && temp_G == 0 && temp_B == 0){
          gradient_noclear(f_R, f_G, f_B, t_R, t_G, t_B, temp_loc1);
        }else{
          leds.setPixelColor(temp_loc1, temp_R, temp_G, temp_B);
        };
      };
      if(temp_loc2 > 0 && temp_loc2 < LED_COUNT){
        if(temp_R == 0 && temp_G == 0 && temp_B == 0){
          gradient_noclear(f_R, f_G, f_B, t_R, t_G, t_B, temp_loc2);
        }else{
          leds.setPixelColor(temp_loc2, temp_R, temp_G, temp_B);
        };
      };
    };
    leds.show();
    delay(dura);
  };
};

void cyclone_down_noclear(int f_R, int f_G, int f_B, int t_R, int t_G, int t_B, int R, int G, int B, float dim, int dura){
  int s_R = (R * dim) + 1;
  int s_G = (G * dim) + 1;
  int s_B = (B * dim) + 1;

  for(int i = LED_COUNT + (1.2 / dim); i > 0 - (1.2 / dim); i--){
    for(int j = 0; j < LED_COUNT / 2; j++){
      int temp_R = check_zero(R - (s_R * j));
      int temp_G = check_zero(G - (s_G * j));
      int temp_B = check_zero(B - (s_B * j));
      int temp_loc1 = i + j;
      int temp_loc2 = i - j;

      if(temp_loc1 > 0 && temp_loc1 < LED_COUNT){
        if(temp_R == 0 && temp_G == 0 && temp_B == 0){
          gradient_noclear(f_R, f_G, f_B, t_R, t_G, t_B, temp_loc1);
        }else{
          leds.setPixelColor(temp_loc1, temp_R, temp_G, temp_B);
        };
      };
      if(temp_loc2 > 0 && temp_loc2 < LED_COUNT){
        if(temp_R == 0 && temp_G == 0 && temp_B == 0){
          gradient_noclear(f_R, f_G, f_B, t_R, t_G, t_B, temp_loc2);
        }else{
          leds.setPixelColor(temp_loc2, temp_R, temp_G, temp_B);
        };
      };
    };
    leds.show();
    delay(dura);
  };
};


void gradient_noclear(int f_R, int f_G, int f_B, int t_R, int t_G, int t_B, int ping){
  for(int i = (LED_COUNT / 2); i < LED_COUNT; i++){
    float temp_R = ((((float)f_R - (float)t_R) / ((float)LED_COUNT / 2) * (i - (float)LED_COUNT / 2)) + (float)t_R);
    float temp_G = ((((float)f_G - (float)t_G) / ((float)LED_COUNT / 2) * (i - (float)LED_COUNT / 2)) + (float)t_G);
    float temp_B = ((((float)f_B - (float)t_B) / ((float)LED_COUNT / 2) * (i - (float)LED_COUNT / 2)) + (float)t_B);
    if(ping == i){
      leds.setPixelColor(i, (int)temp_R, (int)temp_G, (int)temp_B);
    }else
    if(ping == LED_COUNT - i){
      leds.setPixelColor(LED_COUNT - i, (int)temp_R, (int)temp_G, (int)temp_B);
    };
  };
};


