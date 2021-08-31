
//Alarm Clock
const int sound_pin = 8;
const int button_pin = 3;

unsigned int frequency = 3000;//this:https://physikunterricht-online.de/jahrgang-7/schallwahrnehmung-und-schallmessung/#:~:text=Beobachtung%3A,2000%20Hz%20und%204000%20Hz.
unsigned duration = 60000;//1min = 60000mil

unsigned int th = 7;
unsigned int resttime = 24 - th;
unsigned int sleeptime = th*3600000;
unsigned int milrest = resttime*3600000;

void setup() {
  pinMode(button_pin, INPUT);
}


void sleep_night(){
  //sleeps until you are awake
  for(int i=sleeptime/60000; i>0; i--) {
    delay(60000);
  }
}

void loop() {
    int ye = 1;
    while(ye == 1){
      int buttonState_;
      buttonState_ = digitalRead(button_pin);
      if (buttonState_ == LOW) {
        tone(sound_pin, frequency, 50000);
        ye = 0;
      }
    }
    sleep_night();
    tone(sound_pin, frequency, duration);
    delay(duration);
    int yee = 1;
    tone(sound_pin, frequency);
    while(yee == 1){
      int buttonState;
      buttonState = digitalRead(button_pin);
      if (buttonState == LOW) {
        noTone(sound_pin);
        yee = 0;
      }
    }
}
