

void setSpectrumLED(){

  //for loop used to get each spectrum value in the array
  for(int i = 0; i < 7; i++){
    //used switch statements so for each spectrum input it outputs to a certain part of the matrix
    switch(i){
      case 6:
        backgroundLayer.fillRectangle(0,0,3,floor((Spectrum[i]/1024.0) * 64), band6);
        backgroundLayer.fillRectangle(59,0,63,floor(Spectrum[i]/1024.0*64), band6);
        break;
      case 5:
        backgroundLayer.fillRectangle(5,0,8,floor((Spectrum[i]/1024.0) * 64), band5);
        backgroundLayer.fillRectangle(57,0,54,floor((Spectrum[i]/1024.0) * 64), band5);
        break;
      case 4:
        backgroundLayer.fillRectangle(10,0,13,floor((Spectrum[i]/1024.0) * 64), band4);
        backgroundLayer.fillRectangle(52,0,49,floor((Spectrum[i]/1024.0) * 64), band4);
        break;
       case 3:
        backgroundLayer.fillRectangle(15,0,18,floor((Spectrum[i]/1024.0) * 64), band3);
        backgroundLayer.fillRectangle(47,0,44,floor((Spectrum[i]/1024.0) * 64), band3);
        break;
       case 2:
        backgroundLayer.fillRectangle(20,0,23,floor((Spectrum[i]/1024.0) * 64), band2);
        backgroundLayer.fillRectangle(42,0,39,floor((Spectrum[i]/1024.0) * 64), band2);
        break;
       case 1:
        backgroundLayer.fillRectangle(25,0,28,floor((Spectrum[i]/1024.0) * 64), band1);
        backgroundLayer.fillRectangle(37,0,34,floor((Spectrum[i]/1024.0) * 64), band1);
        break;
       case 0:
        backgroundLayer.fillRectangle(30,0,32,floor((Spectrum[i]/1024.0) * 64), band0);
        break;
    }
   }
  Serial.println();

}
