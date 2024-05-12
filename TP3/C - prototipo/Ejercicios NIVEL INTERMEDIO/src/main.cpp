#include <Arduino.h>

//***********************************************NIVEL INTERMEDIO*******************************************

//------------------------------------------------------------------------------------------------------
/*Ejercicio 5: Uso de botón con estado
• Cambia el estado del led1 cada vez que se presione y suelte el
btn1.*/

/*#define led1 18
#define btn1 34

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(btn1, INPUT_PULLUP); 
}

void loop() {

  int estadoBoton = digitalRead(btn1);
  
  if (estadoBoton == LOW) {
    digitalWrite(led1, !digitalRead(led1)); // Invierte el estado actual del LED1
    delay(250); 
  }
}*/

//------------------------------------------------------------------------------------------------------
/*Ejercicio 6: Debounce de botón
• Implementa una lógica de debounce en el btn1 para evitar
lecturas erróneas.*/

/*#define led1 18
#define btn1 34

// Variables para debounce
unsigned long ultimoTiempo = 0;  // Almacena el último momento en que se leyó el botón
const unsigned long intervaloDebounce = 50; // Intervalo de tiempo de debounce en milisegundos

void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(btn1, INPUT_PULLUP); 
}

void loop() {
  int estadoBoton = digitalRead(btn1);
  
  // Realiza debounce del botón
  if ((millis() - ultimoTiempo) > intervaloDebounce) {
    // Si el botón está presionado (LOW), cambia el estado del LED1
    if (estadoBoton == LOW) {
      digitalWrite(led1, !digitalRead(led1)); // Invierte el estado actual del LED1
    }
    ultimoTiempo = millis(); // Actualiza el último tiempo de lectura del botón
  }
}*/

//-------------------------------------------------------------------------------------------------------
/*Ejercicio 7: Control de múltiples LEDs con botones
• Usa btn1 y btn2 para controlar el estado de led1 y led2
respectivamente.*/

/*#define led1 18
#define led2 5
#define btn1 34
#define btn2 39

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void loop() {
  // Control del LED1 con el botón 1 (btn1)
  if (digitalRead(btn1) == LOW) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }

  // Control del LED2 con el botón 2 (btn2)
  if (digitalRead(btn2) == LOW) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}*/

//-------------------------------------------------------------------------------------------------------
/*Ejercicio 8: Uso de dip switches para control de LEDs
• Lee el estado de los dip switches sw1.1 a sw1.8 y refleja el
estado en los led1 a led8.*/

const int ledPins[] = {18,5,17,16,4,0,2,15};
const int switchPins[] = {13,12,14,27,26,25,33,32};

void setup() {
  // Configura los pines de LED como salidas
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Configura los pines de dip switch como entradas
  for (int i = 0; i < 8; i++) {
    pinMode(switchPins[i], INPUT_PULLUP);
  }
}

void loop() {
  // Lee el estado de cada dip switch y asigna el estado al LED correspondiente
  for (int i = 0; i < 8; i++) {
    int switchState = digitalRead(switchPins[i]);
    digitalWrite(ledPins[i], switchState);
  }
}

