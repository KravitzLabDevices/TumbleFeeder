
  int right_b_pulse = 5;
  int left_b_pulse = 6;




void check_inputs(int middlepos) {

  //Check touch sensors
  touch0 = qt_0.measure();
  touch1 = qt_1.measure();

  //right poke
  if ((touch0 - touch0base) > 50) {
    Serial.write("right poke"); // yy
    int Start  = millis();
    inputtriggered = 2;
    rightPokeCount++;
    while ((qt_0.measure() - touch0base) > 50) {
      delay (1);
    }
    //rightPokeDur = millis() - Start;
    move_right(middlepos);
    update_display();
    rightstart = millis();

    // YY added 
    while(millis()-rightstart<=500){
      digitalWrite(right_b_pulse, HIGH);
    }
    digitalWrite(right_b_pulse, LOW); // bridget added 061622

    
    while ((millis() - rightstart) < opentime) { // open time 20,000
      //right feeder
  
      touch3 = qt_3.measure();
      if ((touch3 - touch3base) > 50) {
        int Start = millis();
        inputtriggered = 4;
        rightFeederCount++;
        // YY added 
        while(millis()-Start<=10){
         digitalWrite(right_b_pulse,HIGH); 
        }
         digitalWrite(right_b_pulse,LOW);


        
        while ((qt_3.measure() - touch3base) > 50) {
          delay (1);
        }
        rightFeederDur = rightFeederDur + (millis() - Start);
        //update_display();
      }
      update_display(); // move update_display() 
    }

    logData();
    rightPokeDur = 0;
    rightFeederCount = 0;
    rightFeederDur = 0;
    move_center(middlepos);
  }

  //left poke
  if ((touch1 - touch1base) > 50) {
    int Start = millis();
    inputtriggered = 1;
    leftPokeCount++;
    while ((qt_1.measure() - touch1base) > 50) {
      delay (1);
    }
    leftPokeDur = millis() - Start;
    move_left(middlepos);
    update_display();
    leftstart = millis();

    while(millis()-leftstart<=500){
       digitalWrite(left_b_pulse, HIGH); 
      }
    digitalWrite(left_b_pulse, LOW); 
    
    while ((millis() - leftstart) < opentime) {
      //left feeder
      touch2 = qt_2.measure();
      if ((touch2 - touch2base) > 50) {
        int Start = millis();
        inputtriggered = 3;
        leftFeederCount++;
        //YY added 
        while(millis()-Start<=10){
         digitalWrite(left_b_pulse,HIGH); 
        }
         digitalWrite(left_b_pulse,LOW);



        
        while ((qt_2.measure() - touch2base) > 50) {
          delay (1);
        }
        leftFeederDur = leftFeederDur + (millis() - Start);
       // update_display();
      }
       update_display();
    }

    logData();
    leftPokeDur = 0;
    leftFeederCount = 0;
    leftFeederDur = 0;
    move_center(middlepos);
  }
}

void baseline_touch() {
  touch0base = qt_0.measure();
  touch1base = qt_1.measure();
  touch2base = qt_2.measure();
  touch3base = qt_3.measure();
}
