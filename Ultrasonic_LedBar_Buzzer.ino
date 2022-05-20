#include <Grove_LED_Bar.h>

//Assigniation

//Ultrason
const int siganlPin = 2; //Broche de l'Ultrason

// LED Bar
const int clockPin = 4;
const int dataPin = 3;
Grove_LED_Bar bar(clockPin, dataPin, 0); // Clock pin, Data pin, Orientation

//Valeurs
long duration; //Variable pour la durée du ping
long cm; //Variable pour la distance du ping
  
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
  pinMode(siganlPin, OUTPUT);
  digitalWrite(siganlPin, LOW); //Initialise le signal
  delayMicroseconds(2); //Délai
  digitalWrite(siganlPin, HIGH); //Activer l'impulsion du signal
  delayMicroseconds(5); //Délai
  digitalWrite(siganlPin, LOW); //Désactive l'impulsion du signal pour créer une courte impulsion (permet d'avoir un meilleur ping)
  
  pinMode(siganlPin, INPUT); //Pour pouvoir lire la durée du signal
  duration = pulseIn(siganlPin, HIGH); //Assigner à la variable

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

    cm = duration / 29 / 2;

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