

//int led = 9;           // the PWM pin the LED is attached to
int brightnessA = 0;    // how bright the LED is
int brightnessB = 0;
int fadeAmount = 5;    // how many points to fade the LED by
int greenA = 9;
int redA = 10;
int greenB = 5;
int redB = 6;
int crossA = 2;
int crossB = 4;
int counter = 0;
int crossA_state = 0;
int crossB_state = 0;
int crossing_LED = 13;

boolean crossA_requested = false;
boolean crossB_requested = false;

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
  
  pinMode(greenA, OUTPUT);
  pinMode(redA, OUTPUT);
  pinMode(greenB, OUTPUT);
  pinMode(redB, OUTPUT);
  pinMode(crossA, INPUT);
  pinMode(crossB, INPUT);
  pinMode(crossing_LED, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  crossA_state = digitalRead(crossA);
  crossB_state = digitalRead(crossB);

  if(crossA_state && !crossA_requested && !crossB_requested)//button pressed, go to off mode
  {
    //State = 0;
    //counter = 0;
    crossA_requested = true;
    
  }
  else if(crossB_state && !crossA_requested && !crossB_requested)
  {
    crossB_requested = true;
  }

  
  //else//button not pressed, go through state machine
  //{
    switch(State){
      case 0:
        digitalWrite(crossing_LED, LOW);
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
        digitalWrite(crossing_LED, LOW);
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
        digitalWrite(crossing_LED, LOW);
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
        digitalWrite(crossing_LED, LOW);
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
        digitalWrite(crossing_LED, LOW);
        analogWrite(redA, 50);
        analogWrite(redB, 150);
        analogWrite(greenA, 0);
        analogWrite(greenB, 0);
        if(counter == 22)
        {
          if(!crossA_requested && !crossB_requested )
          {  
            State = 0;
            counter = 0;
          }
          if(crossA_requested)
          {
            State = 5;
            counter = 0;
          }
          else
          {
            State = 6;
            counter = 0;
          }
        }
        break; 
       case 5://crossing on A
         digitalWrite(crossing_LED, HIGH);
         analogWrite(greenA, 0);
         analogWrite(redA, 150);
         if(counter <= 8)
         {
            analogWrite(redB, 150);
            analogWrite(greenB, 0);
         }
         else if(counter <= 10)
         {
            analogWrite(redB, 50);
            analogWrite(greenB, 0);
         }
         else if(counter <= 18)
         {
            analogWrite(greenB, 150);
            analogWrite(redB, 0);
         }
         else if(counter <= 20)
         {
            analogWrite(greenB, 50);
            analogWrite(redB, 0);
         }
         else if(counter <= 22)
         {
            analogWrite(greenB, 0);
            analogWrite(redB, 150);
         }
         else
         {
            crossA_requested = false;
            crossB_requested = false;
            State = 0;
            counter = 0;
         }
        break;

       case 6://crossing on B
         digitalWrite(crossing_LED, HIGH);
         analogWrite(greenB, 0);
         analogWrite(redB, 150);
         if(counter <= 8)
         {
            analogWrite(greenA, 150);
            analogWrite(redA, 0);
         }
         else if(counter <= 10)
         {
            analogWrite(redA, 0);
            analogWrite(greenA, 50);
         }
         else if(counter <= 18)
         {
            analogWrite(greenA, 0);
            analogWrite(redA, 150);
         }
         else if(counter <= 20)
         {
            analogWrite(greenA, 0);
            analogWrite(redA, 150);
         }
         else if(counter <= 22)
         {
            analogWrite(greenA, 0);
            analogWrite(redA, 50);
         }
         else
         {
            crossA_requested = false;
            crossB_requested = false;
            State = 0;
            counter = 0;
         }


        break;
    }
    
  //}
  


  counter = counter + 1;
  delay(1000);
  
}
