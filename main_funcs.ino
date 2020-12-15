void clearLEDs(){
  for(int i = 0; i < LED_COUNT; i++){
    leds.setPixelColor(i, 0);
  };
};

int check_zero(int input){
  if(input >= 0){
    return input;
  }else{
    return 0;
  };
};

void move_rainbow(){
  if(glob_R >= MAX){
    glob_state = 1;
  };
  if(glob_G >= MAX){
    glob_state = 2;
  };
  if(glob_B >= MAX){
    glob_state = 3;
  };

  if(glob_state == 1){
   glob_R -= SKIP;
   glob_G += SKIP;
  }else
  if(glob_state == 2){
   glob_G -= SKIP;
   glob_B += SKIP;
  }else
  if(glob_state == 3){
   glob_B -= SKIP;
   glob_R += SKIP;
  };
};

void move_between(float from_R, float from_G, float from_B, float to_R, float to_G, float to_B){
  if(temp_R >= to_R && temp_G >= to_G && temp_B >= to_B){
    temp_state = 1;
  }else
  if(temp_R <= from_R && temp_G <= from_G && temp_B <= from_B){
    temp_state = 2;
  };

  if(temp_state = 1){
    temp_R -= (to_R - from_R) / 50;
    temp_G -= (to_G - from_G) / 50;
    temp_B -= (to_B - from_B) / 50;
  }else
  if(temp_state = 2){
    temp_R += (to_R - from_R) / 50;
    temp_G += (to_G - from_G) / 50;
    temp_B += (to_B - from_B) / 50;
  };
};

