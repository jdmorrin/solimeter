# solimeter (english)

Arduino device that measures hours of direct sunlight

## Description of the code

* Device uses a solar cell as a sensor.
* When sunlight strikes the cell, the program is activated. 
* When the solar cell outputs its maximum voltage, a timer is triggered.
* The timer counts the seconds that the cell is in its maximum output state.
* When the cell's output voltage is < maximum, but > 0, the timer pauses, but the program continues.
* The program stops, when the cell outputs 0 V, which signifies that there is no more sunlight (i.e. it is nighttime)

## Materials

* Solar cell (7 V)
* Arduino UNO
* LCD Display
* Breadboard
* Power Source

# solímetro (castellano)

Aparato de Arduino que mide horas de luz solar directa

## Descripción del código
*  Aparato usa una celda solar como sensor.
*  Cuando la luz choca con la celda, se activa el programa.
*  Cuando la celda genera su voltage máximo, un cronómetro se prende.
*  El cronómetro cuenta los segundos en que la celda está en su estado de salida máxima.
*  Cuando el voltage de salida de la celda sea < máximo, pero > 0, el cronómetro se pausa, mas el program sigue.
*  El programa se para cuando la celda genere 0 V, que señala que no hay más luz (i.e. es de noche)

## Materiales

* Celda solar (7 V)
* Arduino UNO
* Monitor LCD
* Protoboard
* Fuente de poder

--Juan David Morrell Rincón
