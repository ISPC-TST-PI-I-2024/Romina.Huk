#include <Arduino.h>

//***********************************************NIVEL AVANZADO*******************************************

//------------------------------------------------------------------------------------------------------
/*Ejercicio 9: Secuencia de LEDs con botón
• Crea una secuencia de luces que avance cada vez que se
presione btn1.*/

/*const int ledPins[] = {18,5,17,16,4,0,2,15}; 
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]); // Calcula el número de LEDs
const int btn1 = 34;

int currentLed = 0; // Variable para almacenar el índice del LED actual en la secuencia

void setup() {

  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  pinMode(btn1, INPUT_PULLUP); 
}

// Función para avanzar la secuencia de luces
void avanzarSecuencia() {
  digitalWrite(ledPins[currentLed], LOW); // Apaga el LED actual
  currentLed = (currentLed + 1) % numLeds; // Avanza al siguiente LED
  digitalWrite(ledPins[currentLed], HIGH); // Enciende el siguiente LED
}

void loop() {
  int btnState = digitalRead(btn1);
  
  if (btnState == LOW) {
    avanzarSecuencia();
    delay(250); 
  }
}*/

//-------------------------------------------------------------------------------------------------------
/*Ejercicio 10: Control de velocidad de parpadeo con dip switch
• Utiliza los dip switches sw1.1 a sw1.3 para controlar la velocidad
de parpadeo de led1, asignando distintas velocidades.*/

/*const int led1 = 18;
const int switchPins[] = {13, 12, 14}; 

void setup() {
 
  pinMode(led1, OUTPUT);
  
  for (int i = 0; i < 3; i++) {
    pinMode(switchPins[i], INPUT_PULLUP);
  }
}

void loop() {
  
  int switchStates = 0;
  for (int i = 0; i < 3; i++) {
    switchStates |= digitalRead(switchPins[i]) << i;
  }
  
  // Calcula el intervalo de parpadeo basado en el estado de los dip switches
  int blinkInterval = 500;
  if (switchStates == 1) {
    blinkInterval = 1000;
  } else if (switchStates == 2) {
    blinkInterval = 250;
  } else if (switchStates == 3) {
    blinkInterval = 100;
  }

  // Enciende y apaga el LED1 con la velocidad de parpadeo actual
  digitalWrite(led1, HIGH);
  delay(blinkInterval / 2);
  digitalWrite(led1, LOW);
  delay(blinkInterval / 2);
}*/

//-------------------------------------------------------------------------------------------------------
/*Ejercicio 11: Patrón de parpadeo de LEDs con dip switches
• Establece un patrón de parpadeo para los led1 a led8 basado en la combinación de estados 
de sw1.1 a sw1.4. Por ejemplo, cada posición activa del switch puede representar un patrón diferente
(como parpadeo rápido, lento, secuencial, etc.).*/

/*const int ledPins[] = {18,5,17,16,4,0,2,15}; 
const int switchPins[] = {13,12,14,27}; 

void setup() {
  
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  for (int i = 0; i < 4; i++) {
    pinMode(switchPins[i], INPUT_PULLUP);
  }
}

// Funciones de patrones de parpadeo
void apagarLeds() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void parpadeoRapido() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
    delay(100);
  }
}

void parpadeoLento() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(500);
    digitalWrite(ledPins[i], LOW);
    delay(500);
  }
}

void secuencial() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(250);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  // Lee el estado de los dip switches y ajusta el patrón de parpadeo
  int switchStates = 0;
  for (int i = 0; i < 4; i++) {
    switchStates |= digitalRead(switchPins[i]) << i;
  }
  
  // Aplica el patrón de parpadeo basado en la combinación de estados de los dip switches
  switch (switchStates) {
    case 0:  // Ningún switch está activo
      apagarLeds();
      break;
    case 1:  // Solo sw1.1 está activo
      parpadeoRapido();
      break;
    case 2:  // Solo sw1.2 está activo
      parpadeoLento();
      break;
    case 3:  // sw1.1 y sw1.2 están activos
      secuencial();
      break;
    // Define otros casos según el patrón de parpadeo que desees para otras combinaciones de switches
  }
}*/

//-------------------------------------------------------------------------------------------------------
/*Ejercicio 12: Medidor de pulsaciones
• Programa un contador de pulsaciones utilizando btn1. El número de pulsaciones debe mostrarse 
en una secuencia de LEDs (por ejemplo, led5 a led8 donde cada LED representa una cantidad
de pulsaciones).*/

/*const int ledPins[] = {17, 16, 4, 0}; 
const int btn1 = 34; 

int pulsaciones = 0; // Contador de pulsaciones

void setup() {
  
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(btn1, INPUT_PULLUP);
}

void loop() {
  
  if (digitalRead(btn1) == LOW) {
    delay(50); 
    if (digitalRead(btn1) == LOW) {
      pulsaciones++;
    
      for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], i < pulsaciones ? HIGH : LOW);
      }
    }
  }
}*/

//-------------------------------------------------------------------------------------------------------
/*Ejercicio 13: Contraseña con botones
• Implementa un sistema de contraseña usando btn1, btn2, y btn3 donde una secuencia específica 
de pulsaciones activa led1. Si la secuencia es incorrecta, led2 debería encenderse.*/


//--------------------------------------------------------------------------------------------------------
/*Ejercicio 14: Aplicación de timers para control de LEDs
• Utiliza el temporizador del ESP32 para controlar el parpadeo de led1 a led4 sin usar la 
función delay(), permitiendo que el programa ejecute otras tareas mientras los LEDs parpadean.*/

//--------------------------------------------------------------------------------------------------------
/*Ejercicio 15: Control de LEDs mediante comunicación serial
• Escribe un programa que reciba comandos a través del puerto serie para controlar los LEDs. 
Por ejemplo, enviar '1' podría encender led1, '2' apagar led2, etc.*/

//-------------------------------------------------------------------------------------------------------
/*Ejercicio 16: Secuencia de luces de emergencia
• Simula luces de emergencia con los LEDs, donde led1 y led2 parpadean alternativamente en un 
patrón rápido, mientras que led3 y led4 lo hacen en un patrón más lento.*/

const int led1 = 18;
const int led2 = 5;
const int led3 = 17;
const int led4 = 16;

void setup() {
  // Configura los pines de LED como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // Patrón rápido para led1 y led2 (parpadeo alternativo)
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(100); // Tiempo de encendido para led1
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(100); // Tiempo de encendido para led2
  
  // Patrón lento para led3 y led4
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(500); // Tiempo de encendido para led3
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(500); // Tiempo de encendido para led4
}