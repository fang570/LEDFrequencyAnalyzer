#include <SmartLEDShieldV4.h>  
#include <SmartMatrix3.h>

#define COLOR_DEPTH 24   
int AnalogIn = 19;    // read from multiplexer using analog input 19
int Strobe = 11;    // strobe (next band) is attached to digital pin 11
int ResetPin = 12;    // reset is attached to digital pin 12
int Spectrum[7];     // array to store analog values
int filter = 180;  // *** added min level above noise
const uint8_t kMatrixWidth = 64;        
const uint8_t kMatrixHeight = 64;       
const uint8_t kRefreshDepth = 36;       
const uint8_t kDmaBufferRows = 4;       
const uint8_t kPanelType = SMARTMATRIX_HUB75_64ROW_MOD32SCAN; 
const uint8_t kMatrixOptions = (SMARTMATRIX_OPTIONS_NONE);    
const uint8_t kBackgroundLayerOptions = (SM_BACKGROUND_OPTIONS_NONE);
const uint8_t kScrollingLayerOptions = (SM_SCROLLING_OPTIONS_NONE);
const uint8_t kIndexedLayerOptions = (SM_INDEXED_OPTIONS_NONE);


SMARTMATRIX_ALLOCATE_BUFFERS(matrix, kMatrixWidth, kMatrixHeight, kRefreshDepth, kDmaBufferRows, kPanelType, kMatrixOptions);
SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(backgroundLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kBackgroundLayerOptions);
SMARTMATRIX_ALLOCATE_SCROLLING_LAYER(scrollingLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kScrollingLayerOptions);
SMARTMATRIX_ALLOCATE_INDEXED_LAYER(indexedLayer, kMatrixWidth, kMatrixHeight, COLOR_DEPTH, kIndexedLayerOptions);

const int defaultBrightness = (100*255)/100;    // full (100%) brightness
const int defaultScrollOffset = 6;

const rgb24 defaultBackgroundColor = {0x00, 0, 0};
const rgb24 band0 = {0xff,0,0};
const rgb24 band1 = {0,255,255};
const rgb24 band2 = {255,102,255};
const rgb24 band3 = {128,255,0};
const rgb24 band4 = {153,0,76};
const rgb24 band5 = {255,178,102};
const rgb24 band6 = {178,102,255};

// Teensy 3.0 has the LED on pin 13
const int ledPin = 13;


void setup()
  {
    //init pins
    pinMode(Strobe, OUTPUT);
    pinMode(ResetPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(AnalogIn, INPUT);  
    //set reset to high then low
    digitalWrite(ResetPin, HIGH);
    digitalWrite(ResetPin, LOW);  
    Serial.begin(9600); 

    //start led matrix
    matrix.addLayer(&backgroundLayer); 
    matrix.begin();

    matrix.setBrightness(defaultBrightness);
    backgroundLayer.enableColorCorrection(true);
    backgroundLayer.fillScreen(defaultBackgroundColor);
    backgroundLayer.swapBuffers();
   
    // wait
    delay(500);
  }

void loop()
  {
    //call getFrequency()
    getFrequency();
  }
