void gradient(int f_R, int f_G, int f_B, int t_R, int t_G, int t_B){
  for(int i = (LED_COUNT / 2); i < LED_COUNT; i++){
    float temp_R = (((float)f_R - (float)t_R) / pow(((float)LED_COUNT / 2), 2) * pow(((i - (float)LED_COUNT / 2)), 2) + (float)t_R);
    float temp_G = (((float)f_G - (float)t_G) / pow(((float)LED_COUNT / 2), 2) * pow(((i - (float)LED_COUNT / 2)), 2) + (float)t_G);
    float temp_B = (((float)f_B - (float)t_B) / pow(((float)LED_COUNT / 2), 2) * pow(((i - (float)LED_COUNT / 2)), 2) + (float)t_B);
    leds.setPixelColor(i, (int)temp_R, (int)temp_G, (int)temp_B);
    leds.setPixelColor(LED_COUNT - i, (int)temp_R, (int)temp_G, (int)temp_B);
  };
  leds.show();
//  delay(50);
};

