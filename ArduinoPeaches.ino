#include <CapacitiveSensor.h>
//#include <MIDI.h>
//#include <peaches.ino>
#define NPEACHES 10

boolean debug = false;

//MIDI_CREATE_DEFAULT_INSTANCE();

//Inputs
const int txPin = 2;
const int rxPins[NPEACHES] = {3,4,5,6,7,8,9,10,11,12};
CapacitiveSensor *peaches[NPEACHES];

int samples = 6;
int timeout = 10;
int debugState = 0;
int currentState;
int ledPin = 13;

void setup() {
  if(debug == false) {
//    MIDI.begin();
  } 
  else {
    Serial.begin(9600);
  }
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  pinMode(txPin,OUTPUT);
  pinMode(ledPin, OUTPUT); //debug

  // Set peaches as CapacitiveSensors
  for (int i = 0; i < NPEACHES; i++) {
    peaches[i] = new CapacitiveSensor(txPin, rxPins[i]);
  }  
  //Set timeouts
  for (int i = 0; i < NPEACHES; i++) {
    peaches[i] -> set_CS_Timeout_Millis(timeout);
  }
}

void loop() {
  readThreshold();
  readRetrigger();
  int reading[10];
  //Get peach
  for (int i = 0; i < NPEACHES; i++) {
    reading[i] = peaches[i] -> capacitiveSensor(samples);
  }
//  int r1 =  p1.capacitiveSensor(samples);

  if(debug == false) {
    //peachRead(int number, int reading, int midiNote, int midiChannel)
    for (int i = 0; i < NPEACHES; i++) {
      peachRead(i, reading[i], i, 2); 
    }
//    peachRead(0, r1, 0, 2);
//    peachRead(1, r2, 1, 2);
//    peachRead(2, r3, 2, 2);
//    peachRead(3, r4, 3, 2);
//
//    peachRead(4, r5, 4, 2);
//    peachRead(5, r6, 5, 2);
//    peachRead(6, r7, 6, 2);
//    peachRead(7, r8, 7, 2);
//
//    peachRead(8, r9, 8, 2);
//    peachRead(9, r10, 9, 2);
//    peachRead(10, r11, 0, 3);
//    peachRead(11, r12, 0, 16);
//
//    peachRead(12, r13, 1, 16);
//    peachRead(13, r14, 13, 4);
//    peachRead(14, r15, 17, 4);
//    peachRead(15, r16, 18, 4);
//
//    peachRead(16, r17, 7, 6);
//    peachRead(17, r18, 8, 6);
//    peachRead(18, r19, 10, 6);
//    peachRead(19, r20, 10, 5);
//
//    peachRead(20, r21, 10, 1);
//    peachRead(21, r22, 12, 1);
//    peachRead(22, r23, 14, 1);
//    peachRead(23, r24, 15, 1);
//
//    peachRead(24, r25, 17, 1);
//    peachRead(25, r26, 19, 1);
//    peachRead(26, r27, 0, 7);
  } 
  else {
    delay(500);
  }
}

