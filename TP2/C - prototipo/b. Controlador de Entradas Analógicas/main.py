#ESP32 MicroPython - TEMPERATURE NTC

"""CONSIGNA 2:
Desarrollar un programa que lea valores de un sensor de temperatura y los
muestre en el Serial Monitor/consola."""

print("Hello, let's take the temperature ")

import machine # type: ignore
import utime # type: ignore
import math
from machine import Pin # type: ignore

# Se le asigna un pin al sensor.
pinTemp = Pin(35) 

# Lectura del valor del sensor de temperatura.
dataTemp = machine.ADC(pinTemp).read_u16() 

BETA = 3950 # Representa el coeficiente Beta del termistor.

# Convierte la lectura en Celcius.
celsius = 1 / (math.log(1 / (65535 / dataTemp - 1)) / BETA + 1.0 / 298.15) - 273.15;

#Se imprime el valor de la temperatura.
print("Temperatura: {:.1f}°C".format(celsius)) 

while True:
    utime.sleep(5) #Intervalo de 5 segundos, para repetir la lectura de la temperatura.
    dataTemp = machine.ADC(pinTemp).read_u16()
    celsius = 1 / (math.log(1 / (65535 / dataTemp - 1)) / BETA + 1.0 / 298.15) - 273.15;
    print("Temperatura: {:.1f}°C".format(celsius))