#include <Adafruit_NeoPixel.h>

const byte pir_pin= 15; 
const byte data_pin= 13;
const byte led_num= 16;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(led_num, data_pin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);

  pinMode(pir_pin, INPUT);

  pixels.begin();
  pixels.show();
}

void loop() {
  Serial.println(digitalRead(pir_pin));

  if(digitalRead(pir_pin)){
    generate_random_pattern();
  }

  delay(10); // this speeds up the simulation
}

void generate_random_pattern(){

  byte pattern = random(1,3);  //  generates a number : 1 , 2

  byte b = random(0,255);
  byte g = random(0,255);
  byte r = random(0,255);

  Serial.print("Pattern number : ");
  Serial.println(pattern);

  if (pattern == 1){
    for (int i = 0; i < led_num; i++){
      pixels.setPixelColor(i, r, g, b);
      pixels.show();
      delay(50);
    }
    for (int i = led_num - 1; i >= 0; i--){
      pixels.setPixelColor(i, 0, 0, 0);
      pixels.show();
      delay(50);
    }
  }  else if (pattern == 2){

    //  fade up
    for (int i = 0; i <= 255; i++){
      for (int j = 0; j < led_num; j++){
        pixels.setPixelColor(j, 0, i, i);
      }
      pixels.show();
      delay(10);
    }

    //  fade down
    for (int i = 255; i >= 0; i--){
      for (int j = 0; j < led_num; j++){
        pixels.setPixelColor(j, 0, i, i);
      }
      pixels.show();
      delay(10);
    }
  }
}