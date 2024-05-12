#ESP32 MicroPython - LEDS PLAY

"""CONSIGNA 3: 
Implementar un sistema que alterne el encendido de un conjunto de LEDs en
intervalos regulares."""

print("Hello, ESP32!")

from machine import Pin  # type: ignore
import utime # type: ignore

# Asignar los pines en una lista y pasarlos por un ciclo for.
leds = [Pin(i, Pin.OUT) for i in (21,18,17,4,15)]

while True:
    for led in leds:
        led.value(1)
        utime.sleep(0.3) # Intervalo de encendido.
        led.value(0)
    for led in reversed(leds):
        led.value(1)
        utime.sleep(0.2) # Intervalo de encendido en reversa.
        led.value(0)