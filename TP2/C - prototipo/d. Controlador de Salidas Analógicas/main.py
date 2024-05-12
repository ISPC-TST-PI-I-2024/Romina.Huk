#ESP32 MicroPython - LED INTESITY PWM

"""CONSIGNA 4:
Escribir un código que controle la intensidad de un LED usando PWM basado
en la lectura de un potenciómetro."""

print("Hello, ESP32!")

from machine import PWM # type: ignore
from machine import Pin  # type: ignore
from machine import ADC # type: ignore
import utime # type: ignore
import math


ledPin = PWM(Pin(13)) # Se le asigna un pin al Led

adcPin = ADC(Pin(33)) # Se le asigna un pin al potenciometro.

adcPin.atten(ADC.ATTN_11DB) # Atenuacion para el voltaje recibido.

while True:
    a = adcPin.read() # Lee el valor analogico del pin
    b = math.trunc(a/4)
    ledPin.duty(b)
    utime.sleep_ms(200)