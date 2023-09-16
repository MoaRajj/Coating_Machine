#include <ezButton.h>

ezButton limitswitch1(3);
ezButton limitswitch2(26);
ezButton limitswitch3(14);
ezButton limitswitch4(15);
ezButton limitswitch5(5);
ezButton limitswitch6(32);

////****** Message ******////
const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

      // variables to hold the parsed data
char message[numChars] = {0};
int Function_Z_Delay = 700;
long Function_Z_period = 1;

boolean newData = false;
////*********************////
const int Dir_x  = 8;
const int Pul_x  = 9;
const int Dir_y  = 13;
const int Pul_y  = 12;
const int Dir_z  = 10;
const int Pul_z  = 11;
const int Polisaj_pul = 22;
const int Polisaj_dir = 24;
const int Dir_roller  = 6;
const int Pul_roller  = 7;

const int polisaj_tur_number = 3500 ; // polisaj tur sayısını değiştirmek
long x_mesafe = 54000;
int delay_ = 120;
int delay_2 = 25;
//int delay_polisaj = 800;
int polisaj_clock = 0;
int z_distance = 3000;
const int delay_z = 1200;//250
int clock_z = 0;

long decrease_ = 1;
long previousMillis = 0;
long motor_rev=0;
boolean limit_switch = 0;

void setup(){
  pinMode(Pul_x , OUTPUT);
  pinMode(Dir_x , OUTPUT);
  pinMode(Pul_y , OUTPUT);
  pinMode(Dir_y , OUTPUT);
  pinMode(Pul_z , OUTPUT);
  pinMode(Dir_z , OUTPUT);
  pinMode(Polisaj_dir, OUTPUT);
  pinMode(Polisaj_pul, OUTPUT);
  pinMode(Pul_roller , OUTPUT);
  pinMode(Dir_roller , OUTPUT);
  
  limitswitch1.setDebounceTime(50); // set debounce time to 50 milliseconds
  limitswitch2.setDebounceTime(50); // set debounce time to 50 milliseconds
  limitswitch3.setDebounceTime(50); // set debounce time to 50 milliseconds
  limitswitch4.setDebounceTime(50); // set debounce time to 50 milliseconds
  limitswitch5.setDebounceTime(50); // set debounce time to 50 milliseconds
  limitswitch6.setDebounceTime(50); // set debounce time to 50 milliseconds

  delay(100);
  Serial.begin(9600);
  // Serial.println("Press:\n j for X+\n k for X-\n n for Z+\n 0 for Z-\n l for Y+\n m for Y-\n 2 for Polish\n 1 to star a function\n s for Stop\n");
}


void X_positive(){
    digitalWrite(Dir_x, LOW); // x sola gitti
    Serial.println("x is going left");
    // motor_rev = 0;
    delay_ = 120;
    previousMillis = 0;
    limit_switch = 0;
    while (1)
    {
      // motor_rev= motor_rev+1 ;
      unsigned long currentMillis = millis();
      digitalWrite(Pul_x, HIGH);   
      delayMicroseconds(delay_);
      digitalWrite(Pul_x, LOW);      
      delayMicroseconds(delay_);      

      limitswitch2.loop();
      
      if ( currentMillis - previousMillis > delay_2)
      {
        previousMillis = currentMillis ;
        if (delay_ > 19)
        {
          delay_ = delay_ - decrease_;
        }
      }
      if (limitswitch2.isPressed() && limit_switch == 0)
      {
        delay(50);
        digitalWrite(Dir_x, HIGH);
        delay_ = 120;
        previousMillis = 0;
        limit_switch = 1;
        // motor_rev= 90000;
        // break;
      }
      if (limitswitch2.isReleased())
      {
        break;
      }
      /*if ( motor_rev > 94000)
      {
          break;
      }*/
      if (Serial.available() > 0) { message[0] = Serial.read();
      if ( (message[0] == 's') && (limit_switch == 0) )
      {
          Serial.println("Stop");
          break;
      }}
  }
}

void X_nagative(){
    digitalWrite(Dir_x, HIGH); // x sağa gitti
    Serial.println("x is going Right");
    // motor_rev = 0;
    delay_ = 120;
    previousMillis = 0;
    limit_switch = 0;
    //Serial.print(switche1);
    while (1)
    {
      // motor_rev= motor_rev+1 ;
      unsigned long currentMillis = millis();
      digitalWrite(Pul_x, HIGH);   
      delayMicroseconds(delay_);
      digitalWrite(Pul_x, LOW);      
      delayMicroseconds(delay_);
      
      limitswitch1.loop();

      if ( currentMillis - previousMillis > delay_2)
      {
        previousMillis = currentMillis ;
        if (delay_ > 19)
        {
          delay_ = delay_ - decrease_;
        }
      }
      if (limitswitch1.isPressed() && limit_switch == 0)
      {
        delay(50);
        digitalWrite(Dir_x, LOW);
        delay_ = 120;
        previousMillis = 0;
        limit_switch = 1;
        //Serial.print(switche1);
        // motor_rev= 90000;
        // break;
      }
      if (limitswitch1.isReleased())
      {
        break;
      }
      /*if ( motor_rev > 94000)
      {
          break;
      }*/
      if (Serial.available() > 0) { message[0] = Serial.read();
      if ( (message[0] == 's') && (limit_switch == 0) )
      {
          Serial.println("Stop");
          break;
      }}
    } 
}

void Z_nagative(){
    digitalWrite(Dir_z, LOW); // z Aşağı
    Serial.println("z is going Down");
    // motor_rev = 0;
    delay_ = 120;
    previousMillis = 0;
    limit_switch = 0;
    while (1)
    {
      // motor_rev= motor_rev+1 ;
      unsigned long currentMillis = millis();
      digitalWrite(Pul_z, HIGH);   
      delayMicroseconds(delay_);
      digitalWrite(Pul_z, LOW);      
      delayMicroseconds(delay_);

      limitswitch4.loop();
   
      if ( currentMillis - previousMillis > delay_2)
      {
        previousMillis = currentMillis ;
        if (delay_ > 19)
        {
          delay_ = delay_ - decrease_;
        }
      }
      if (limitswitch4.isPressed() && limit_switch == 0)
      {
        delay(50);
        digitalWrite(Dir_z, HIGH);
        delay_ = 120;
        previousMillis = 0;
        limit_switch = 1;
        //Serial.print(switche1);
        // motor_rev= 90000;
        // break;
      }
      if (limitswitch4.isReleased())
      {
        break;
      }
      /*if ( motor_rev > 20000)
      {
          break;
      }*/
      if (Serial.available() > 0) { message[0] = Serial.read();
      if ( (message[0] == 's') && (limit_switch == 0) )
      {
          Serial.println("Stop");
          break;
      }
      if (message[0] == 'x')
      {
        break;
      }}
    } 
}

void Z_positive(){
    digitalWrite(Dir_z, HIGH); // z Yukarı
    Serial.println("z is going Up");
    // motor_rev = 0;
    delay_ = 120;
    previousMillis = 0;
    limit_switch = 0;
    while (1)
    {
      // motor_rev= motor_rev+1 ;
      unsigned long currentMillis = millis();
      digitalWrite(Pul_z, HIGH);   
      delayMicroseconds(delay_);
      digitalWrite(Pul_z, LOW);      
      delayMicroseconds(delay_);

      limitswitch3.loop();

      if ( currentMillis - previousMillis > delay_2)
      {
        previousMillis = currentMillis ;
        if (delay_ > 19)
        {
          delay_ = delay_ - decrease_;
        }
      }
      if (limitswitch3.isPressed() && limit_switch == 0)
      {
        delay(50);
        digitalWrite(Dir_z, LOW);
        delay_ = 120;
        previousMillis = 0;
        limit_switch = 1;
        //Serial.print(switche1);
        // motor_rev= 90000;
        // break;
      }
      if (limitswitch3.isReleased())
      {
        break;
      }
      /*if ( motor_rev > 20000)
      {
          break;
      }*/
      if (Serial.available() > 0) { message[0] = Serial.read();
      if ( (message[0] == 's') && (limit_switch == 0) )
      {
          Serial.println("Stop");
          break;
      }}
    } 
}

void Y_nagative(){
    digitalWrite(Dir_y, LOW); // y Öne
    Serial.println("y is going Backward");
    // motor_rev = 0;
    delay_ = 120;
    previousMillis = 0;
    limit_switch = 0;
    while (1)
    {
      // motor_rev= motor_rev+1 ;
      unsigned long currentMillis = millis();
      digitalWrite(Pul_y, HIGH);   
      delayMicroseconds(delay_);
      digitalWrite(Pul_y, LOW);      
      delayMicroseconds(delay_);

      limitswitch6.loop();
   
      if ( currentMillis - previousMillis > delay_2)
      {
        previousMillis = currentMillis ;
        if (delay_ > 19)
        {
          delay_ = delay_ - decrease_;
        }
      }
      if (limitswitch6.isPressed() && limit_switch == 0)
      {
        delay(50);
        digitalWrite(Dir_y, HIGH);
        delay_ = 120;
        previousMillis = 0;
        limit_switch = 1;
        //Serial.print(switche1);
        // motor_rev= 90000;
        // break;
      }
      if (limitswitch6.isReleased())
      {
        break;
      }
      /*if ( motor_rev > 20000)
      {
          break;
      }*/
      if (Serial.available() > 0) { message[0] = Serial.read();
      if ( (message[0] == 's') && (limit_switch == 0) )
      {
          Serial.println("Stop");
          break;
      }}
    } 
}

void Y_positive(){
    digitalWrite(Dir_y, HIGH); // y Arkaya
    Serial.println("y is going Forward");
    // motor_rev = 0;
    delay_ = 120;
    previousMillis = 0;
    limit_switch = 0;
    while (1)
    {
      // motor_rev= motor_rev+1 ;
      unsigned long currentMillis = millis();
      digitalWrite(Pul_y, HIGH);   
      delayMicroseconds(delay_);
      digitalWrite(Pul_y, LOW);      
      delayMicroseconds(delay_);

      limitswitch5.loop();

      if ( currentMillis - previousMillis > delay_2)
      {
        previousMillis = currentMillis ;
        if (delay_ > 19)
        {
          delay_ = delay_ - decrease_;
        }
      }
      if (limitswitch5.isPressed() && limit_switch == 0)
      {
        delay(50);
        digitalWrite(Dir_y, LOW);
        delay_ = 120;
        previousMillis = 0;
        limit_switch = 1;
        //Serial.print(switche1);
        // motor_rev= 90000;
        // break;
      }
      if (limitswitch5.isReleased())
      {
        break;
      }
      /*if ( motor_rev > 20000)
      {
          break;
      }*/
      if (Serial.available() > 0) { message[0] = Serial.read();
      if ( (message[0] == 's') && (limit_switch == 0) )
      {
          Serial.println("Stop");
          break;
      }}
    } 
}

void roller_positive(){
    digitalWrite(Dir_roller, HIGH); // roller saga gitti
    Serial.println("roller is going right");
    motor_rev = 0;
    delay_ = 120;
    previousMillis = 0;
    while (1)
    {
      motor_rev= motor_rev+1 ;
      unsigned long currentMillis = millis();
      digitalWrite(Pul_roller, HIGH);   
      delayMicroseconds(delay_);
      digitalWrite(Pul_roller, LOW);
      delayMicroseconds(delay_);      
      /*if ( currentMillis - previousMillis > 95)
      {
        previousMillis = currentMillis ;
        if (delay_ > 19)
        {
          delay_ = delay_ - decrease_;
        }
      }
      if ( motor_rev > 7000)
      {
          Serial.println("Finish");
          return;
      }*/
      if (Serial.available() > 0) { message[0] = Serial.read();
      if (message[0] == 's')
      {
          Serial.println("Stop");
          return;
      }}
  }
}

void roller_nagative(){
    digitalWrite(Dir_roller, LOW); // roller sola gitti
    Serial.println("roller is going left");
    motor_rev = 0;
    delay_ = 120;
    previousMillis = 0;
    while (1)
    {
      motor_rev= motor_rev+1 ;
      unsigned long currentMillis = millis();
      digitalWrite(Pul_roller, HIGH);   
      delayMicroseconds(delay_);
      digitalWrite(Pul_roller, LOW);      
      delayMicroseconds(delay_); 
      /*if ( currentMillis - previousMillis > 95)
      {
        previousMillis = currentMillis ;
        if (delay_ > 19)
        {
          delay_ = delay_ - decrease_;
        }
      }
      if ( motor_rev > 7000)
      {
          Serial.println("Finish");
          return;
      }*/
      if (Serial.available() > 0) { message[0] = Serial.read();
      if (message[0] == 's')
      {
          Serial.println("Stop");
          return;
      }}
    } 
}

void polisaj(){
      Serial.println("Polishing head is activated");
      while (1)
      {
        digitalWrite(Polisaj_pul, HIGH);
        delayMicroseconds(Function_Z_Delay);
        digitalWrite(Polisaj_pul, LOW);
        delayMicroseconds(Function_Z_Delay);
        //polisaj_clock += 1 ;
        /*if ( polisaj_clock > polisaj_tur_number)
        {
          polisaj_clock = 0 ; 
          break ;
        }*/
        if (Serial.available() > 0) { message[0] = Serial.read();
        if (message[0] == 's')
        {
          Serial.println("Stop");
          break;
        }}
      }
}

void FirstFunction(){ 
      Serial.println("The first function is On");
      Go_Home();
      digitalWrite(Dir_x, LOW); // x sola gidiyor
      motor_rev = 0;
      delay_ = 120; 
      previousMillis = 0;
      limit_switch = 0;
      while(1)
      {
        motor_rev = motor_rev + 1;
        unsigned long currentMillis = millis();
        digitalWrite(Pul_x, HIGH);
        delayMicroseconds(delay_);
        digitalWrite(Pul_x, LOW);
        delayMicroseconds(delay_);
        limitswitch2.loop();
        
        if ( currentMillis  - previousMillis > delay_2 )
        {
          previousMillis = currentMillis ;
          if ( delay_ > 19)
          {
            delay_ = delay_ - decrease_ ;
          }
        }
        if (limitswitch2.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_x, HIGH);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch2.isReleased())
        {
          return;
        }
        if( (motor_rev > x_mesafe) && (limit_switch == 0) )
        {
          delay_  = 120;
          break;
        }
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
            Serial.println("Stop");
            return;
          }
        }
      }

      digitalWrite(Dir_z, LOW); // z Aşağı
      motor_rev = 0;
      delay_ = 120;
      previousMillis = 0;
      while (1)
      {
        motor_rev= motor_rev+1 ;
        unsigned long currentMillis = millis();
        digitalWrite(Pul_z, HIGH);   
        delayMicroseconds(delay_);
        digitalWrite(Pul_z, LOW);      
        delayMicroseconds(delay_);
        limitswitch4.loop();
     
        if ( currentMillis - previousMillis > delay_2)
        {
          previousMillis = currentMillis ;
          if (delay_ > 19)
          {
            delay_ = delay_ - decrease_;
          }
        }
        if (limitswitch4.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_z, HIGH);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch4.isReleased())
        {
          break;
        }
        if ( ( motor_rev > 7000) && (limit_switch == 0) )
        {
            break;
        }
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
              Serial.println("Stop");
              return;
          }
          if (message[0] == 'x')
          {
            break;
          }
        }
      }
      
      clock_z = 0  ;
      digitalWrite(Dir_z , LOW); // z aşağı
      while (1)
      {
        digitalWrite(Pul_z, HIGH);
        delayMicroseconds(delay_z);
        digitalWrite(Pul_z, LOW);
        delayMicroseconds(delay_z);
        limitswitch4.loop();
        //clock_z += 1 ;

        if (limitswitch4.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_z, HIGH);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch4.isReleased())
        {
          return;
        }
        /*if ( (clock_z > z_distance) && (limit_switch == 0) )
        {
          clock_z = 0 ; 
          break ; 
        } */
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
            Serial.println("Stop");
            return;
          }
          if (message[0] == 'x')
          {
            //int x = 0 ;
            break;
          }
        }
      }

      // polisaj aktif
       long Previous_Seconds = millis()/1000;
       while (1)
      {
        long Current_Seconds = millis()/1000;
        digitalWrite(Polisaj_pul, HIGH);
        delayMicroseconds(Function_Z_Delay);
        digitalWrite(Polisaj_pul, LOW);
        delayMicroseconds(Function_Z_Delay);
        //polisaj_clock += 1 ;
        if ( Current_Seconds >= Previous_Seconds + Function_Z_period)
        {
          Serial.println(Current_Seconds);
          Serial.println("\n");
          Serial.println(Previous_Seconds);
          break ;
        }
        /*if ( polisaj_clock > polisaj_tur_number)
        {
          polisaj_clock = 0 ; 
          break ;
        }*/
        if (Serial.available() > 0) { message[0] = Serial.read();
          if (message[0] == 's')
          {
            Serial.println("Stop");
            return;
          }
        }
      }
      
      Go_Home();
      
      /*// Z-yukarı
      delay_  = 120 ; 
      clock_z = 0  ;
      digitalWrite(Dir_z , HIGH);
      while (1)
      {
        clock_z += 1 ;
        digitalWrite(Pul_z, HIGH);
        delayMicroseconds(delay_z);
        digitalWrite(Pul_z, LOW);
        delayMicroseconds(delay_z);
        limitswitch3.loop();

        if (limitswitch3.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_z, LOW);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch3.isReleased())
        {
          return;
        }
        if ( (clock_z > z_distance) && (limit_switch == 0) )
        {
          clock_z = 0 ; 
          break; 
        }
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
            Serial.println("Stop");
            return;
          }
        } 
      }

      digitalWrite(Dir_x, HIGH); // x sağa gidiyor
      motor_rev = 0 ;
      delay_ = 120 ; 
      previousMillis = 0;
      while(1)
      {
        motor_rev = motor_rev + 1;
        unsigned long currentMillis = millis();
        digitalWrite(Pul_x, HIGH);
        delayMicroseconds(delay_);
        digitalWrite(Pul_x, LOW);
        delayMicroseconds(delay_);
        limitswitch1.loop();
        
        if ( currentMillis  - previousMillis > delay_2 )
        {
          previousMillis = currentMillis ;
          if ( delay_ > 19)
          {
            delay_ = delay_ - decrease_ ;
          }
        }
        if (limitswitch1.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_x, LOW);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch1.isReleased())
        {
          return;
        }
        if ( ( motor_rev > x_mesafe) && (limit_switch == 0) )
        {
          break;
        }
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
            Serial.println("Stop");
            return;
          }
        }
      }
      delay(1000);*/   
}

void SecondFunction() { 
      Serial.println("The second function is On");
      clock_z = 0  ;
      digitalWrite(Dir_z , LOW); // z aşağı
      while (1)
      {
        digitalWrite(Pul_z, HIGH);
        delayMicroseconds(delay_z);
        digitalWrite(Pul_z, LOW);
        delayMicroseconds(delay_z);
        limitswitch4.loop();
        //clock_z += 1 ;

        if (limitswitch4.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_z, HIGH);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch4.isReleased())
        {
          return;
        }
        if ( (clock_z > z_distance) && (limit_switch == 0) )
        {
          clock_z = 0 ; 
          break ; 
        } 
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
            Serial.println("Stop");
            return;
          }
          if (message[0] == 'x')
          {
            //int x = 0 ;
            break;
          }
        }
      }

      // polisaj aktif
      long Previous_Seconds = millis()/1000;
      while (1)
      {
        long Current_Seconds = millis()/1000;
        digitalWrite(Polisaj_pul, HIGH);
        delayMicroseconds(Function_Z_Delay);
        digitalWrite(Polisaj_pul, LOW);
        delayMicroseconds(Function_Z_Delay);
        //polisaj_clock += 1 ;
        if ( Current_Seconds >= Previous_Seconds + Function_Z_period)
        {
          Serial.println(Current_Seconds);
          Serial.println("\n");
          Serial.println(Previous_Seconds);
          break ;
        }
        /*if ( polisaj_clock > polisaj_tur_number)
        {
          polisaj_clock = 0 ; 
          break ;
        }*/
        if (Serial.available() > 0) { message[0] = Serial.read();
          if (message[0] == 's')
          {
            Serial.println("Stop");
            return;
          }
        }
      }

      // Z-yukarı
      delay_  = 120 ; 
      clock_z = 0  ;
      digitalWrite(Dir_z , HIGH);
      while (1)
      {
        clock_z += 1 ;
        digitalWrite(Pul_z, HIGH);
        delayMicroseconds(delay_z);
        digitalWrite(Pul_z, LOW);
        delayMicroseconds(delay_z);
        limitswitch3.loop();

        if (limitswitch3.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_z, LOW);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch3.isReleased())
        {
          return;
        }
        if ( (clock_z > z_distance) && (limit_switch == 0) )
        {
          clock_z = 0 ; 
          break; 
        }
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
            Serial.println("Stop");
            return;
          }
        } 
      }
      delay(1000);   
}

void ThirdFunction() { 
      Serial.println("The third function is On");
      clock_z = 0  ;
      digitalWrite(Dir_z , LOW); // z aşağı
      while (1)
      {
        digitalWrite(Pul_z, HIGH);
        delayMicroseconds(delay_z);
        digitalWrite(Pul_z, LOW);
        delayMicroseconds(delay_z);
        limitswitch4.loop();
        //clock_z += 1 ;

        if (limitswitch4.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_z, HIGH);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch4.isReleased())
        {
          return;
        }
        if ( (clock_z > z_distance) && (limit_switch == 0) )
        {
          clock_z = 0 ; 
          break ; 
        } 
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
            Serial.println("Stop");
            return;
          }
          if (message[0] == 'x')
          {
            //int x = 0 ;
            break;
          }
        }
      }
      delay(1000); 

      // Z-yukarı
      delay_  = 120 ; 
      clock_z = 0  ;
      digitalWrite(Dir_z , HIGH);
      while (1)
      {
        clock_z += 1 ;
        digitalWrite(Pul_z, HIGH);
        delayMicroseconds(delay_z);
        digitalWrite(Pul_z, LOW);
        delayMicroseconds(delay_z);
        limitswitch3.loop();

        if (limitswitch3.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_z, LOW);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch3.isReleased())
        {
          return;
        }
        if ( (clock_z > z_distance) && (limit_switch == 0) )
        {
          clock_z = 0 ; 
          break; 
        }
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
            Serial.println("Stop");
            return;
          }
        } 
      }
      delay(1000);   
}

void FourthFunction() { 
      Serial.println("The fourth function is On");
      clock_z = 0  ;
      digitalWrite(Dir_z , LOW); // z aşağı
      while (1)
      {
        digitalWrite(Pul_z, HIGH);
        delayMicroseconds(delay_z);
        digitalWrite(Pul_z, LOW);
        delayMicroseconds(delay_z);
        limitswitch4.loop();
        //clock_z += 1 ;

        if (limitswitch4.isPressed() && limit_switch == 0)
        {
          delay(50);
          digitalWrite(Dir_z, HIGH);
          delay_ = 120;
          previousMillis = 0;
          limit_switch = 1;
        }
        if (limitswitch4.isReleased())
        {
          return;
        }
        if ( (clock_z > z_distance) && (limit_switch == 0) )
        {
          clock_z = 0 ; 
          break ; 
        } 
        if (Serial.available() > 0) { message[0] = Serial.read();
          if ( (message[0] == 's') && (limit_switch == 0) )
          {
            Serial.println("Stop");
            return;
          }
          if (message[0] == 'x')
          {
            //int x = 0 ;
            break;
          }
        }
      }
      delay(1000); 
}

void Go_Home(){ 
  Serial.println("Go Home");
  digitalWrite(Dir_z, HIGH); // z Yukarı
  delay_ = 120;
  previousMillis = 0;
  limit_switch = 0;
  while (1)
  {
    unsigned long currentMillis = millis();
    digitalWrite(Pul_z, HIGH);   
    delayMicroseconds(delay_);
    digitalWrite(Pul_z, LOW);      
    delayMicroseconds(delay_);
    limitswitch3.loop();

    if ( currentMillis - previousMillis > delay_2)
    {
      previousMillis = currentMillis ;
      if (delay_ > 19)
      {
        delay_ = delay_ - decrease_;
      }
    }
    if (limitswitch3.isPressed() && limit_switch == 0)
    {
      delay(50);
      digitalWrite(Dir_z, LOW);
      delay_ = 120;
      previousMillis = 0;
      limit_switch = 1;
    }
    if (limitswitch3.isReleased())
    {
      break;
    }
    if (Serial.available() > 0) { message[0] = Serial.read();
      if ( (message[0] == 's') && (limit_switch == 0) )
      {
        Serial.println("Stop");
        return;
      }
    }
  }
  digitalWrite(Dir_x, HIGH); // x sağa gitti
  delay_ = 120;
  previousMillis = 0;
  limit_switch = 0;
  while (1)
  {
    unsigned long currentMillis = millis();
    digitalWrite(Pul_x, HIGH);   
    delayMicroseconds(delay_);
    digitalWrite(Pul_x, LOW);      
    delayMicroseconds(delay_);
    limitswitch1.loop();

    if ( currentMillis - previousMillis > delay_2)
    {
      previousMillis = currentMillis ;
      if (delay_ > 19)
      {
        delay_ = delay_ - decrease_;
      }
    }
    if (limitswitch1.isPressed() && limit_switch == 0)
    {
      delay(50);
      digitalWrite(Dir_x, LOW);
      delay_ = 120;
      previousMillis = 0;
      limit_switch = 1;
    }
    if (limitswitch1.isReleased())
    {
      break;
    }
    if (Serial.available() > 0) { message[0] = Serial.read();
      if ( (message[0] == 's') && (limit_switch == 0) )
      {
          Serial.println("Stop");
          return;
      }
    }
  }
  digitalWrite(Dir_y, HIGH); // y Arkaya
  delay_ = 120;
  previousMillis = 0;
  limit_switch = 0;
  while (1)
  {
    unsigned long currentMillis = millis();
    digitalWrite(Pul_y, HIGH);   
    delayMicroseconds(delay_);
    digitalWrite(Pul_y, LOW);      
    delayMicroseconds(delay_);
    limitswitch5.loop();

    if ( currentMillis - previousMillis > delay_2)
    {
      previousMillis = currentMillis ;
      if (delay_ > 19)
      {
        delay_ = delay_ - decrease_;
      }
    }
    if (limitswitch5.isPressed() && limit_switch == 0)
    {
      delay(50);
      digitalWrite(Dir_y, LOW);
      delay_ = 120;
      previousMillis = 0;
      limit_switch = 1;
    }
    if (limitswitch5.isReleased())
    {
      break;
    }
    if (Serial.available() > 0) { message[0] = Serial.read();
    if ( (message[0] == 's') && (limit_switch == 0) )
      {
        Serial.println("Stop");
        return;
      }
    }
  }
}

void loop() {

  recvWithStartEndMarkers();
    if (newData == true) {
        strcpy(tempChars, receivedChars);
            // this temporary copy is necessary to protect the original data
            //   because strtok() used in parseData() replaces the commas with \0
        parseData();
        showParsedData();
        Call_Function();
        newData = false;
    }
  
/*if (Serial.available() > 0) { message = Serial.read();
    if (message == 'j'){
      X_positive();}
    if (message == 'k'){
      X_nagative();}
    if (message == 'n'){ 
      Z_positive();}
    if (message == '0'){
      Z_nagative();}
    if (message == 'l'){ 
      Y_positive();}
    if (message == 'm'){
      Y_nagative();} 
    if (message == '1'){
      FirstFunction();}
    if (message == '2'){
      SecondFunction();}
    if (message == '3'){
      ThirdFunction();}
    if (message == '4'){
      FourthFunction();}
    if (message == 'a'){
      polisaj();}
    if (message == 'c'){
      roller_positive();}
    if (message == 'b'){
      roller_nagative();}
    if (message == '7'){
      Go_Home();}
    motor_rev = 0;}*/
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

//============

void parseData() {      // split the data into its parts

    char * strtokIndx; // this is used by strtok() as an index

    strtokIndx = strtok(tempChars,",");      // get the first part - the string
    strcpy(message, strtokIndx); // copy it to messageFromPC 
 
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    Function_Z_Delay = atoi(strtokIndx);     // convert this part to an integer

    strtokIndx = strtok(NULL, ",");
    Function_Z_period = atol(strtokIndx);     // convert this part to a float
    // <j, 700, 3>

}

//============

void showParsedData() {
    Serial.print("Message ");
    Serial.println(message);
    Serial.print("Function Z Delay ");
    Serial.println(Function_Z_Delay);
    Serial.print("Function Z period ");
    Serial.println(Function_Z_period);
}

void Call_Function(){
  if (message[0] == 'j'){
    X_positive();}
  if (message[0] == 'k'){
    X_nagative();}
  if (message[0] == 'n'){ 
    Z_positive();}
  if (message[0] == '0'){
    Z_nagative();}
  if (message[0] == 'l'){ 
    Y_positive();}
  if (message[0] == 'm'){
    Y_nagative();} 
  if (message[0] == '1'){
    FirstFunction();}
  if (message[0] == '2'){
    SecondFunction();}
  if (message[0] == '3'){
    ThirdFunction();}
  if (message[0] == '4'){
    FourthFunction();}
  if (message[0] == 'a'){
    polisaj();}
  if (message[0] == 'c'){
    roller_positive();}
  if (message[0] == 'b'){
    roller_nagative();}
  if (message[0] == '7'){
    Go_Home();}
}
