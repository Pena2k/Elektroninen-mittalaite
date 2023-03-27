#include <LiquidCrystal.h> // LCD Kirjasto
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 9; //Määritellään Sensorin pinnit.
const int echoPin = 10;

float kesto; // Muuttuja ultraäänen matkustusajalle.
float pituus; // Muuttuja matkan pituudelle.

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW); // Tyhjentää aron asettamalla trigPinnin LOW tilaan 2 mikrosekuntin ajaksi.
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); //Generoi ultraäänen näillä kolmella rivillä.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  kesto = pulseIn(echoPin, HIGH); //PulseIn komennolla luetaan matkustusaika
  pituus = (kesto /2) * 0.0344444 + 0.25; // Laskee pituuden kertomalla PulseIn:in mittaaman keston käyttämällä valon nopeuden kaavaa.

if (pituus >= 400 || pituus <= 2){
  Serial.print("Pituus = ");
  Serial.println("Kantavuusalueen ulkopuolella");
}
else{
  Serial.print("Pituus = ");
    Serial.print(pituus);
    Serial.println(" cm");
    delay(500);
}
delay(500);
}



