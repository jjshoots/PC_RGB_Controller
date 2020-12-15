#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

const int PIN = 3, LED_COUNT = 60;
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_RGB + NEO_KHZ800);
const int MAX = 25;
const float SKIP = 0.3;

float glob_R = MAX, glob_G = 0, glob_B = 0;
int glob_state = 0;

int twink_R[60];
int twink_G[60];
int twink_B[60];

float temp_R = 0, temp_G = 0, temp_B = 0;
int temp_state;

void setup(){
  leds.begin();
  cyclone_down(50, 40, 50, 0.05, 25);
  delay(500);

  for(int i = 0; i <= MAX; i++){
    gradient(i, i, i, i/3, 0, i);
    delay(40);
  }
};


void loop(){
//  unsigned long long time_set;

  
  /*
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 1200000 >= millis()){
      cyclone_up_noclear(glob_R, glob_G, glob_B, 35, 35, 35, glob_R, glob_G, glob_B, 0.1, 50);
      move_rainbow();
      cyclone_down_noclear(glob_R, glob_G, glob_B, 35, 35, 35, glob_R, glob_G, glob_B, 0.1, 50);
      move_rainbow();
    };
  };
  
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up(0, 100, 50, 0.1, 50);
      cyclone_down(0, 100, 50, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up(50, 100, 25, 0.1, 50);
      cyclone_down(50, 100, 25, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      rainbow_twink(100, 50, 1);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up(80, 25, 50, 0.1, 50);
      cyclone_down(80, 25, 50, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up_noclear(0, 0, 30, 0, 30, 30, 0, 35, 10, 0.1, 50);
      cyclone_down_noclear(0, 0, 30, 0, 30, 30, 0, 35, 10, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up_noclear(0, 35, 15, 30, 30, 15, 10, 25, 15, 0.1, 50);
      cyclone_down_noclear(0, 35, 15, 30, 30, 15, 10, 25, 15, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up_noclear(35, 0, 30, 0, 25, 0, 25, 25, 25, 0.1, 50);
      cyclone_down_noclear(35, 0, 30, 0, 25, 0, 25, 25, 25, 0.1, 50);
    };
  };if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up(0, 100, 50, 0.1, 50);
      cyclone_down(0, 100, 50, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up(50, 100, 25, 0.1, 50);
      cyclone_down(50, 100, 25, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up(80, 25, 50, 0.1, 50);
      cyclone_down(80, 25, 50, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up_noclear(0, 50, 20, 0, 0, 25, 0, 50, 0, 0.1, 50);
      cyclone_down_noclear(0, 50, 20, 0, 0, 25, 0, 50, 0, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up_noclear(0, 50, 25, 15, 15, 15, glob_R, glob_G, glob_B, 0.1, 50);
      move_rainbow();
      cyclone_down_noclear(0, 50, 25, 15, 15, 15, glob_R, glob_G, glob_B, 0.1, 50);
      move_rainbow();
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up(0, 100, 50, 0.1, 50);
      cyclone_down(0, 100, 50, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up(50, 100, 25, 0.1, 50);
      cyclone_down(50, 100, 25, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      cyclone_up(80, 25, 50, 0.1, 50);
      cyclone_down(80, 25, 50, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 600000 >= millis()){
      breathe_up(20, 40, 10, 0.1, 50);
      breathe_down(20, 40, 10, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 300000 >= millis()){
      breathe_up(80, 80, 80, 0.1, 50);
      breathe_down(80, 80, 80, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 300000 >= millis()){
      cyclone_up(50, 100, 25, 0.1, 50);
      cyclone_down(50, 100, 25, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 300000 >= millis()){
      cyclone_up(80, 80, 80, 0.1, 50);
      cyclone_down(80, 80, 80, 0.1, 50);
    };
  };
  */
  /*
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 300000 >= millis()){
      breathe_up(20, 40, 10, 0.1, 50);
      breathe_down(20, 40, 10, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 300000 >= millis()){
      cyclone_up(50, 100, 25, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 300000 >= millis()){
      cyclone_up(60, 40, 40, 0.1, 50);
      cyclone_down(60, 40, 40, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 300000 >= millis()){
      cyclone_up(50, 100, 25, 0.1, 50);
      cyclone_down(50, 100, 25, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 300000 >= millis()){
      cyclone_up(60, 40, 40, 0.1, 50);
    };
  };
  if(rand() % 6 >= 3){
    time_set = millis();
    while(time_set + 300000 >= millis()){
      breathe_up(80, 80, 80, 0.1, 50);
      breathe_down(80, 80, 80, 0.1, 50);
      cyclone_up(60, 40, 40, 0.1, 50);
      breathe_up(80, 80, 80, 0.1, 50);
      breathe_down(80, 80, 80, 0.1, 50);
      cyclone_down(60, 40, 40, 0.1, 50);
    };
  };
  */
};


