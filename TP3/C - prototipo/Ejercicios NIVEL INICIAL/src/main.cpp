#include <Arduino.h>

//***********************************************NIVEL INICIAL*******************************************

//------------------------------------------------------------------------------------------------------
/*Ejercicio 1: Encender un LED
• Enciende el led1 conectado al GPIO18 de forma continua.*/

/*#define led1 18

void setup() {

pinMode(led1, OUTPUT);

}

void loop() {
 
 digitalWrite(led1, HIGH);

}*/

//-------------------------------------------------------------------------------------------------------

/*Ejercicio 2: Parpadeo de un LED
• Programa el led1 para que parpadee con un intervalo de 1
segundo.*/

/*#define led1 18

void setup() {

pinMode(led1, OUTPUT);

}

void loop() {
 
 digitalWrite(led1, HIGH);
 delay(500);
 digitalWrite(led1, LOW);
 delay(500);
}*/

//-------------------------------------------------------------------------------------------------------

/*Ejercicio 3: Secuencia de LEDs
• Crea una secuencia que encienda los LEDs del led1 al led3 de
forma sucesiva, cada uno durante 500ms.*/

/*#define led1 18
#define led2 5
#define led3 17

void setup() {
  // Configura todos los pines de LED como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Enciende el LED1
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led1, LOW);

  // Enciende el LED2
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);

  // Enciende el LED3
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
}*/

//-------------------------------------------------------------------------------------------------------
/*Ejercicio 4: Control de LED con botón
• Usa el btn1 para encender el led1 mientras se mantenga
presionado.*/

#define btn1 34
#define led1 18

void setup(){
  pinMode(btn1, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop(){
  if(digitalRead(btn1) == LOW){
    digitalWrite(led1, HIGH);
  }else{
    digitalWrite(led1, LOW);
  }

}
  