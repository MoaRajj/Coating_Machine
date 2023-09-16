#include "HX711.h"
#define LOADCELL_DOUT_PIN 2
#define LOADCELL_SCK_PIN 3
#include "max6675.h"
#include <stdlib.h>
#include <stdio.h>
#define relay 4 // Relay pin is 4
// MAX6675 Pins
#define thermoDO  8
#define thermoCS  9
#define thermoCLK  10
HX711 scale;

float scale_value;
float calibration_factor = 7050 ;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO); //
float temperature_;
float reference_ = 30.0; //The needed temperature value

String message;
String On_pre = "o\n";
String On_temp_and_pre = "b\n";
String Off = "s\n";
String clr = "c\n";

void setup(){
  pinMode(relay , OUTPUT);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN) ;
  scale.set_scale();
  scale.tare();
  
  delay(100);
  Serial.begin(9600); 
}

void get_pre(){
  while(1){
    scale.set_scale(calibration_factor);
    scale_value = scale.get_units();
    Serial.println(scale_value);
    
    if (Serial.available() > 0){ message = Serial.readString();
      if (message == Off){
        //Serial.println("OUT");
        return;
      }
      else if (message == clr){
        //Serial.println("Zero");
        scale.tare();
      }
    }
    delay(100);
  }
}

void get_temp_and_pre(){
  while(1){
    // Read the Temperature using the readCelsius methode from MAX6675 Library.
    temperature_  = thermocouple.readCelsius() + 3.00;
    for (int i = 0; i <= 9; i++) {
      scale.set_scale(calibration_factor);
      scale_value = scale.get_units();
      Serial.print(temperature_ ); // 
      Serial.print(",");
      Serial.println(scale_value);
      //Serial.print("\n");
      if(temperature_ > reference_){
        digitalWrite(relay, LOW);
      }
      if(temperature_ < reference_){
        digitalWrite(relay, HIGH);
      }
      if (Serial.available() > 0) { message = Serial.readString();
        if (message == Off){
            return;
        }
        else if (message == clr){
          scale.tare();
        }
      }
      delay(100);
    }
  }
}

void loop(){
  digitalWrite(relay, LOW);
  if (Serial.available() > 0) { message = Serial.readString();
    if (message == On_pre){
      get_pre();
    }
    else if (message == On_temp_and_pre){
        digitalWrite(relay, HIGH);
        get_temp_and_pre();
      }
    else{
      reference_ = message.toFloat();
      //Serial.println(reference_);
    }
  }
}
