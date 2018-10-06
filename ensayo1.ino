#include <LiquidCrystal.h>
float Temperatura = 0;   // Temperatura del LM35
int elegir = 0;     // Variable con la que elijo que temperatura cambiar


// Pines que uso de la libreria
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int TempMax = 30;   // Temperatura maxima iniciada en 30
int TempMin = 10;   // Temperatura minima iniciada en 10                         
int TempInc = 0;   // Estado actual del boton de incremento de temperatura
int TempDec = 0; // Estado actual del boton de decremento de temperatura

void setup() {
 Serial.begin(9600);
  pinMode(13,OUTPUT);   // Configuro pin 13 como salida
  pinMode(6, INPUT);  // Configuro pin 6  como entrada Incrementa
  pinMode(7, INPUT);  // Configuro pin 7 como entrada Decrementa
  pinMode(A0, INPUT); //Configuro pin A0 como entrada
    
  lcd.begin(16, 2);     // Identifico el LCD
  lcd.setCursor(3, 0);  // Ubico texto en la columna 3 y fila 0
  lcd.print("Termostato"); // Muestra en LCD
  lcd.setCursor(4, 1);     // Ubico texto en la columna 4 y fila 1
  lcd.print("Con LM35"); // Muestra en LCD
  delay(5000); // Espera 5 segundos
  lcd.clear(); // Borra lo que hay en el LCD
}

void loop() {
  Temperatura = (5.0 * analogRead(A0)* 100.0)/1024.0; // Pasar datos a °C
  // Pregunto si la Temperatura es menor o igual a TempMin, apago led
    if (Temperatura <= TempMin ) {
    digitalWrite(13, LOW);
  } else if (Temperatura >= TempMax) {
    digitalWrite(13, HIGH);
  } // O sino, si es mayor o igual a TempMax, prendo led
  lcd.setCursor(0, 0); // Ubico texto en columna 0 y fila 0
  lcd.print("TempAct:"); // Muestro en LCD
  lcd.print(Temperatura); // Muestra en LCD
  lcd.print("C");
  lcd.setCursor(0, 1); // Ubicar texto en columna 0 y fila 1
  lcd.print("Tmin:"); // Muestro en LCD
  lcd.print(TempMin); // Muestro en LCD
  lcd.print("C");
  lcd.setCursor(8, 1); // Ubico texto en columna 8 y fila 1
  lcd.print("Tmax:"); // Muestra en LCD
  lcd.print(TempMax); // Muestro en LCD
  lcd.print("C");
  // Pregunto si los dos botones estan presionados
 if ( digitalRead(6)==1 && digitalRead(7)==1){
  lcd.clear(); // Borra lo que hay en LCD
  lcd.setCursor(6, 0); // Ubico texto en columna 6 y fila 0 
  lcd.print("Menu"); // Muestra en LCD
  delay(3000); // Espera 1 segundo
  lcd.clear(); // Borra lo que hay en el LCD
  lcd.setCursor(5,0); // Ubico Texto en columna 5 y fila 0
  lcd.print("Elegir"); //Muestra en LCD
  lcd.setCursor(0, 1); // Ubico texto en columna 0 y fila 1
  lcd.print("Tmin:"); // Muestro en LCD
  lcd.print(TempMin); // Muestro en LCD
  lcd.print("C");
  // Mientras que el boton 6 no esta presionado
  while (digitalRead(6) == LOW){
    // Pregunta si el boton 7 esta pulsado
  if ( digitalRead(7) == 1) {
    elegir != elegir; // Si esta pulsado, la variable elegir va a cambiar de estado
    // Si la variable elegir esta en 0 
  if ( elegir == 0){
         lcd.setCursor(0,1); // Ubico texto en la columna 0 y fila 1
         // Muestra en LCD
  lcd.print("Tmax:");
  //Muestra en LCD
  lcd.print(TempMax);
  lcd.print("C");}
  // Sino...
  else{
   lcd.setCursor(0,1); // Ubico texto en la columna 0 y fila 1
  lcd.print("Tmin:"); // Muestra en LCD
  lcd.print(TempMin); // Muestra en LCD
  lcd.print("C");
  }
  }
 }//Salio del while
  while (digitalRead(6) == HIGH){
    lcd.clear(); // Borro porque se sobre ecribe cuando sale del menu
  }
 // Vuelve a preguntar si los dos pulsadores estan presionados para salir del menu
  if ( digitalRead(6)==1 && digitalRead(7)==1){ // no lo uso
    }
 }
}
