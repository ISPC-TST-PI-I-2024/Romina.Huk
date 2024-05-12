#ESP32 MicroPython - LED PUSH BUTTON

"""CONSIGNA 1:
Crear un sketch en Arduino y un script en MicroPython que lea el estado de 
un botón y encienda un LED cuando el botón esté presionado. """

print("HELLO PUSH BUTTON; ")

from machine import Pin  # type: ignore
from time import sleep

led = Pin(2, Pin.OUT) # Se asigna un pin al led
pushButton = Pin(13, Pin.IN) # Se asigna un pin al boton

while True:
  state = pushButton.value() # Controla el estado del boton
  if state == True:
    led.value(1)
  else:
    led.value(0)  