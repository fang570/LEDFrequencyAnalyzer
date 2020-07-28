/*
  MSGEQ7 frequency analyzer. 
  

  60 HZ = 1st;
  then goes in order.
  

  Author: George Fang
*/

void getFrequency()
  {
    for (int i = 0; i < 7; i++)                            
      {
        // HIGH to LOW transition 
        digitalWrite(Strobe, HIGH); 
        digitalWrite(Strobe, LOW);
        //added delay
        delayMicroseconds(33);                               

        //read in analog values to spectrum[i]
        Spectrum[i] = constrain(analogRead(AnalogIn), filter, 1023);  
        //delay
        delayMicroseconds(600);  
        //if spectrum is filter then set to 0
        if(Spectrum[i] == filter){
          Spectrum[i] = 0;
        }
     }
      //print out values of the inputs (did it as test).
      for(int j = 0; j < 7; j++){
            Serial.print("\t");
            Serial.print(Spectrum[j]);
      }  
      //calls the setSpectrumLED function to output to matrix
      setSpectrumLED();
      backgroundLayer.swapBuffers();

      //matrix stuff to reset the screen 
      delay(20);
      backgroundLayer.fillScreen(defaultBackgroundColor);
      backgroundLayer.swapBuffers();
      Serial.println();                               
  }
