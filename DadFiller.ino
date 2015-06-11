#include "Cylinder.h"
#include "Valve.h"
#include "PhotoEye.h"
#include "ConveyerBelt.h"


Valve valves[12] = {
  Valve(1),
  Valve(2),
  Valve(3),
  Valve(4),
  Valve(5),
  Valve(6),
  Valve(7),
  Valve(8),
  Valve(9),
  Valve(10),
  Valve(11),
  Valve(12),
};

Cylinder exitCylinder(13, 14);
Cylinder entryCylinder(15, 16);

ConveyerBelt conveyerBelt(17);

PhotoEye photoEye(18);


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
