#include "SevSeg.h"
SevSeg sevseg;
#define BUTTON_START A0
#define BUTTON_RESET A1
#define BUZZER A2

unsigned long previousMillis = 0;
const long interval = 1000; 
//you can change rest and work time as you want,by changing numbers
const int WORK_TIME = 30; //Time of work
const int REST_TIME = 7; //Time of rest

int minutes = WORK_TIME;
int seconds = 0;
bool isRunning = false;
bool isWorkMode = true; 

bool lastButtonStartState = HIGH;
bool lastButtonResetState = HIGH;

void setup() {
  byte numDigits = 4;   
  byte digitPins[] = {10, 11, 12, 13}; 
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; 
  
  bool resistorsOnSegments = true; 
  byte hardwareConfig = COMMON_CATHODE; 
  bool updateWithDelays = false; 
  bool leadingZeros = true; 
  bool disableDecPoint = false; 

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);

  pinMode(BUTTON_START, INPUT_PULLUP);
  pinMode(BUTTON_RESET, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  
  digitalWrite(BUZZER, LOW);
}

void loop() {
bool currentButtonStartState = digitalRead(BUTTON_START);
  if (lastButtonStartState == HIGH && currentButtonStartState == LOW) {
    isRunning = !isRunning;
  }
  lastButtonStartState = currentButtonStartState;
bool currentButtonResetState = digitalRead(BUTTON_RESET);
  if (lastButtonResetState == HIGH && currentButtonResetState == LOW) {
    resetTimer();
  }
  lastButtonResetState = currentButtonResetState;
  if (isRunning) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      
      if (seconds == 0) {
        if (minutes == 0) {
          alarm(); 
          
          if (isWorkMode) {
            minutes = REST_TIME; 
            isWorkMode = false;
          } else {
            minutes = WORK_TIME; 
            isWorkMode = true;
          }
          seconds = 0;
          isRunning = false; 
        } else {
          minutes--;
          seconds = 59;
        }
      } else {
        seconds--;
      }
    }
  }
  int timeToDisplay = minutes * 100 + seconds;
  sevseg.setNumber(timeToDisplay, 2); 
  sevseg.refreshDisplay(); 
}

void resetTimer() {
  isRunning = false;
  isWorkMode = true;
  minutes = WORK_TIME;
  seconds = 0;
}

void alarm() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(BUZZER, HIGH);
      delay(200);
    digitalWrite(BUZZER, LOW);
      delay(100);
  }
}
