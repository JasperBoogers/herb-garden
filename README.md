# herb-garden

## potential tutorials
https://create.arduino.cc/projecthub/londonium2021/automatic-indoor-vegetable-garden-9ea453?ref=similar&ref_id=94739&offset=2
basically uses irrigation system bought in hardware store, no not much fun

https://create.arduino.cc/projecthub/vinikon/autonomous-indoor-greenhouse-mature-real-working-project-946f6e?ref=search&ref_id=plant%20irrigation&offset=18

https://vegetronix.com/TechInfo/

https://www.youtube.com/watch?v=O_Q1WKCtWiA&t=325s
has nice graphs

stepper motor tutorial:
https://www.makerguides.com/drv8825-stepper-motor-driver-arduino-tutorial/

## to think about
* moisture sensors may be volatile --> use kalmann filter?

## what do we want to measure?
* soil moisture (using capacitance)
* pH
* light (no irrigation during daylight?)
* temperature (no irrigation when it is too hot?)

## Shopping list
* [x] [moisture sensors](https://www.tinytronics.nl/shop/nl/sensoren/temperatuur-lucht-vochtigheid/capacitieve-bodemvocht-sensor-module-met-kabel)
* [x] [stepper motor and bracket](https://www.tinytronics.nl/shop/nl/robotica/motoren/motor/stappenmotor-23mm-dik-0.13n.m-1.0a-nema17-jst-ph-connector)
* [x] LDR
* [x] guidance rails
* [ ] water pump
* [ ] water hoses
* [ ] valves for left/right positioning
* [ ] ultrasonic sensor

## Development history/plan
In this section contains an overview of (future) versions. This includes possible fantasies.

### version 0.5
test construction for watering system

### version 1.0
first working version. Based on Arduino uno. Standalone, no wireless connection and/or control.
no individual moisture sensor checking, just water 2-hourly or something like that.

### version 1.5
use moisture sensors to check for each plant

### version 2.0
* setup using ESP8266, could be controlled by raspi
* design custom PCB

### version 3.0
imagination

### version 4.0
rainbows
