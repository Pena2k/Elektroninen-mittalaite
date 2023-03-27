#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int trigPin = 9; //Määritellään Sensorin pinnit.
const int echoPin = 10;

float kesto; // Muuttuja ultraäänen matkustusajalle.
float pituus; // Muuttuja matkan pituudelle.

void setup() {
  lcd.begin(16, 2);
  //lcd.print(pituus);
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

if (pituus >= 400){
  //lcd.print("Pituus = ");
  lcd.println("Kantavuusalueen ulkopuolella");
  delay(500);
  lcd.clear();
  delay(500);
}
else{
  lcd.setCursor(0,0);
  lcd.print("Pituus (cm) = ");
  	delay(100);
  	lcd.setCursor(0,1);
  	lcd.print(pituus);
}
delay(500);
}



