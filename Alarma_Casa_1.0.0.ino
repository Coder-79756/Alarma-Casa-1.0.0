
#include <Wire.h>			// libreria de comunicacion por I2C
#include <LCD.h>			// libreria para funciones de LCD
#include <LiquidCrystal_I2C.h>		// libreria para LCD por I2C

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7

int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 7; // Input for HC-S501

int pirValue; // Place to store read PIR Value

void setup()
{
    lcd.setBacklightPin(3,POSITIVE);	// puerto P3 de PCF8574 como positivo
    lcd.setBacklight(HIGH);		// habilita iluminacion posterior de LCD
    lcd.begin(16, 2);			// 16 columnas por 2 lineas para LCD 1602A
    lcd.clear();			// limpia pantalla

    pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
 
  digitalWrite(ledPin, LOW);
}

void loop()
{
    lcd.setCursor(0, 0);		// ubica cursor en columna 0 y linea 0
    lcd.print("Alarma activa !");	// escribe texto
    lcd.display();			// muestra el texto
    delay(500);				// demora de medio segundo
    lcd.noDisplay();			// oculta el texto
    delay(500);				// demora de medio segundo

    pirValue = digitalRead(pirPin);
  digitalWrite(ledPin, pirValue);
}
