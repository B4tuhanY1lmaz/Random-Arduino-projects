#include <LCD5110_Basic.h>

int pushButton = 2;
LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t SmallFont[];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pushButton, INPUT);

  
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(pushButton);
  if (buttonState == HIGH) {
    myGLCD.print("button pressed!", CENTER, 24);
    delay(2000);
    myGLCD.clrScr();
  }
 digitalWrite(LED_BUILTIN, HIGH);
 Serial.write("Blink!");
 myGLCD.print("Blink!", CENTER, 20);
 delay(900);
 digitalWrite(LED_BUILTIN, LOW);
 myGLCD.clrScr();
 delay(900);

if (digitalRead(LED_BUILTIN) == HIGH){
  Serial.write("It Works");
  //myGLCD.print("Blink!", CENTER, 20);
  delay(1000);
  //myGLCD.clrScr();
}

}
