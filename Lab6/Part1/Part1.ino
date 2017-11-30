

//int led = 9;           // the PWM pin the LED is attached to
int brightnessA = 0;    // how bright the LED is
int brightnessB = 0;
int fadeAmount = 5;    // how many points to fade the LED by
int greenA = 9;
int redA = 10;
int greenB = 5;
int redB = 6;
int on_off_pin = 2;
int counter = 0;
int buttonState = 0;
int State = 0;  /*  State 0:  A bright green, B bright red active for 8 time units
                    State 1:  A pale green, B delay red, lasts 2 time units
                    State 2:  A bright red, B bright green, lasts 8 time units
                    State 3:  A bright red, B pale green, lasts 2 time units
                    State 4:  A delay red, B bright red, lasts 2 time units
                    State 5:  A bright green, B bright red, lasts 8 time units
                    State 6:  A pale green, B delay red, lasts 2 time units
                    State 7:  A bright red, B bright green, lasts 8 time units
                    State 8:  A bright red, B pale green, lasts 2 time units
                    State 9:  A delay red, B bright red, lasts 2 time units
              
                */


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(greenA, OUTPUT);
  pinMode(redA, OUTPUT);
  pinMode(greenB, OUTPUT);
  pinMode(redB, OUTPUT);
  pinMode(on_off_pin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(on_off_pin);

  if(buttonState)//button pressed, go to off mode
  {
    State = 0;
    counter = 0;
    analogWrite(greenA, 0);
    analogWrite(redA, 0);
    analogWrite(redB, 0);
    analogWrite(greenB, 0);
    
  }
  else//button not pressed, go through state machine
  {
    switch(State){
      case 0:
        analogWrite(greenA, 150);
        analogWrite(redB, 150);
        analogWrite(redA, 0);
        analogWrite(greenB, 0);
        if(counter == 8)
        {
          State = 1;
        }

        break;
      case 1:
        analogWrite(greenA, 50);
        analogWrite(redB, 50);
        analogWrite(redA, 0);
        analogWrite(greenB, 0);
        if(counter == 10)
        {
          State = 2;
        }
        break;
      case 2:
        analogWrite(redA, 150);
        analogWrite(greenB, 150);
        analogWrite(greenA, 0);
        analogWrite(redB, 0);
        if(counter == 18)
        {
          State = 3;
        }
        break;
      case 3:
        analogWrite(redA, 150);
        analogWrite(greenB, 50);
        analogWrite(greenA, 0);
        analogWrite(redB, 0);
        if(counter == 20)
        {
          State = 4;
        }
        break;
      case 4:
        analogWrite(redA, 50);
        analogWrite(redB, 150);
        analogWrite(greenA, 0);
        analogWrite(greenB, 0);
        if(counter == 22)
        {
          State = 0;
          counter = 0;
        }
        break;  
    }
    
  }
  


  counter = counter + 1;
  delay(1000);
  
}
