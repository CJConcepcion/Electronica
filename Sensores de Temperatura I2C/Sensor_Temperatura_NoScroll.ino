#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);  // crea objeto y asigna pines a los cuales se encuentran conectados RS, E, D4, D5, D6, D7
int SENSOR;   // variable almacena valor leido de entrada analogica A0
float TEMPERATURA;  // valor de temperatura en grados centigrados

void setup() {
  lcd.init();// Inicializamos el LCD
  lcd.backlight(); //Activamos la luz de fondo del LCD
  lcd.clear();//Limpiamos pantalla
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  SENSOR = analogRead(A0);      // lectura de entrada analogica A0
  TEMPERATURA = ((SENSOR * 5000.0) / 1023) / 10;// lectura de entrada analogica A0          
  Serial.println(TEMPERATURA,1);
  
  lcd.setCursor(0, 0);        // cursor en primer fila y primer columna
  lcd.print("Temp: ");        // escribe Temp:
  lcd.print(TEMPERATURA/1.0, 1);    // escribe valor promedio de 5 lecturas con
            // un decimal
  lcd.print(" C");        // imprime C
  
  if (TEMPERATURA ==10.0 && TEMPERATURA <=18.9){
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }
  if(TEMPERATURA>19.0 && TEMPERATURA<25.0){
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }
    if(TEMPERATURA >=25.0 && TEMPERATURA<=28.0){
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
  }


if(TEMPERATURA >29.0){
  lcd.setCursor(0, 1);        // cursor en primer fila y primer columna
  lcd.print("Temp.Excesiva");       // escribe PELIGRO
  digitalWrite(8,HIGH);
  }else{
      lcd.setCursor(0, 1);        // cursor en primer fila y primer columna
      lcd.print("Temp.Buena");       // escribe que es Buena
      digitalWrite(8,LOW);  
    }
    delay(1000);
    lcd.clear();
}
