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
  
  if (cm <= 20 && cm > 2){
    cm /= 2;
    
    for(int cm2 = cm; cm2 == 0; cm2-=1){
      bar.setLed(cm2, 1);
      Serial.println("CM2 = " + cm2);
    }
  }
  else {
    bar.setLed(cm, 0);
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


  delay(150);
  
}
