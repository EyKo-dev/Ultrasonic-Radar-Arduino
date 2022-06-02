#include <Grove_LED_Bar.h>

//Assigniation

//Ultrason
const int signalPin = 2;

// LED Bar
const int clockPin = 4;
const int dataPin = 3;
Grove_LED_Bar bar(clockPin, dataPin, 0);

//Valeurs
long duration;
long cm;
  
//Initialisation
void setup()
{
 Serial.begin(9600);

 //Led Bar
 bar.begin();
 pinMode(dataPin, OUTPUT);
 
}

//Boucle
void loop()
{
  //Signal
  pinMode(signalPin, OUTPUT);
  digitalWrite(signalPin, LOW);
  delayMicroseconds(2); //Délai
  digitalWrite(signalPin, HIGH);
  delayMicroseconds(5); //Délai
  digitalWrite(signalPin, LOW);
  
  pinMode(signalPin, INPUT);
  duration = pulseIn(signalPin, HIGH);
  cm = duration / 29 / 2;
  
  if(cm > 20){
    bar.setLevel(0);
  }
  
  if (cm <= 20){
    bar.setLed(10, 1);
  }
  else {
    bar.setLed(10, 0);
  }

  if (cm <= 18){
    bar.setLed(9, 1);
  }
  else {
    bar.setLed(9, 0);
  }
  
  if (cm <= 16){
    bar.setLed(8, 1);
  }
  else {
    bar.setLed(8, 0);
  }

  if (cm <= 14){
    bar.setLed(7, 1);
  }
  else {
    bar.setLed(7, 0);
  }

  if (cm <= 12){
    bar.setLed(6, 1);
  }
  else {
    bar.setLed(6, 0);
  }

  if (cm <= 10){
    bar.setLed(5, 1);
  }
  else {
    bar.setLed(5, 0);
  }

  if (cm <= 8){
    bar.setLed(4, 1);
  }
  else {
    bar.setLed(4, 0);
  }

  if (cm <= 6){
    bar.setLed(3, 1);
  }
  else {
    bar.setLed(3, 0);
  }

  if (cm <= 4){
    bar.setLed(2, 1);
  }
  else {
    bar.setLed(2, 0);
  }

  if (cm <= 2){
    bar.setLed(1, 1);
    bar.setLevel(10);
    tone(5, 200, 100);
    delay(100);
    bar.setLevel(0); 
    delay(100);
  }
  else {
    bar.setLed(1, 0);
  }

  if(cm <= 20 && cm > 2){
    //Fais un bip 
    duration = cm * 85;
    tone(5, 200, 100);
    delay(duration);
    //Eteint le bip
  }

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  Serial.print("----");
  Serial.println();
  delay(150);
}
