#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4;
char valinta;
float distance1, distance2, area;
int digits[4];

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //Numeerisen näppäimistön pinnit
byte colPins[COLS] = {5, 4, 3, 2}; 	//Numeerisen näppäimistön pinnit

Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

const int trigPin = 12; //Määritellään Sensorin pinnit.
const int echoPin = 13;	//Määritellään Sensorin pinnit.

float kesto; 	// Muuttuja ultraäänen matkustusajalle.
float pituus; 	// Muuttuja matkan pituudelle.

int seconds = 0;

Adafruit_LiquidCrystal lcd(0);


void setup()
{
  lcd.begin(16, 2);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
  lcd.print("Valitse toiminto:"); // tulosta ensimmäinen viesti näytölle
  lcd.setCursor(0,1);
  lcd.print("1mm 2cm 3m 4A");
}

void loop()
{
  
  char key = keypad.getKey();
  delay(100);
  
  
  digitalWrite(trigPin, LOW); // Tyhjentää aron asettamalla trigPinnin LOW tilaan 2 mikrosekuntin ajaksi.
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); //Generoi ultraäänen näillä kolmella rivillä.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  kesto = pulseIn(echoPin, HIGH); //PulseIn komennolla luetaan matkustusaika
  pituus = (kesto /2) * 0.0344444 + 0.25; // Laskee pituuden kertomalla PulseIn:in mittaaman keston käyttämällä valon nopeuden kaavaa.
  
   
  if (key == '2') { // jos painallus on numero 1
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pituus cm = ");
    delay(100);
  	lcd.setCursor(0,1);
  	lcd.print(pituus);
    return;
  }
  else if
	(key == '3') {					//metrit
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pituus m: ");
    delay(100);
    lcd.setCursor(0,1);
  	lcd.print(pituus * 0.01 );
  }
  else if(key == '1') {				//Millimetrit
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("millimetrit");
    delay(100);
    lcd.setCursor(0,1);
  	lcd.print(pituus * 10 );
  }
  else if
	(key == '4') {
    lcd.clear();
    lcd.setCursor(0, 0);			//Mittausten tallentaminen
  	lcd.print("Mittaus 1:");  
    	//if(Serial.available() > 0) {
      		//char input = Serial.read();
    while (key != '*'){
    	key = keypad.getKey();
    	
    }
          
           
    
  digitalWrite(trigPin, LOW); // Tyhjentää aron asettamalla trigPinnin LOW tilaan 2 mikrosekuntin ajaksi.
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); //Generoi ultraäänen näillä kolmella rivillä.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  kesto = pulseIn(echoPin, HIGH); //PulseIn komennolla luetaan matkustusaika
  pituus = (kesto /2) * 0.0344444 + 0.25; // Laskee pituuden 
    
     distance1 = pituus;
                
         // }
        
    lcd.setCursor(0, 1);
    lcd.print(pituus);
    delay(5000);
  
    
    
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Mittaus 2:");
    	//if(Serial.available() > 0) {
      		//char input = Serial.read();
    while (key != '#'){
    	key = keypad.getKey();
    	
    }
  digitalWrite(trigPin, LOW); // Tyhjentää aron asettamalla trigPinnin LOW tilaan 2 mikrosekuntin ajaksi.
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); //Generoi ultraäänen näillä kolmella rivillä.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  kesto = pulseIn(echoPin, HIGH); //PulseIn komennolla luetaan matkustusaika
  pituus = (kesto /2) * 0.0344444 + 0.25; // Laskee pituuden 
    
       distance2 = pituus;
     
    lcd.setCursor(0, 1);
    lcd.print(pituus);
    delay(5000); 
    
    area = distance1 * distance2;
    
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Pinta-ala:");
  	lcd.setCursor(0, 1);
  	lcd.print(area, 2);
    delay(5000);
    
  }
   
  
if (pituus >= 400){
  lcd.println("Kantavuusalueen ulkopuolella");
  delay(500);
  lcd.clear();
  delay(500);
}
	
delay(500);
  }
