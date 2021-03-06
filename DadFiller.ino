#include "Cylinder.h"
#include "Valve.h"
#include "PhotoEye.h"
#include "ConveyorBelt.h"

// pin, timeout
Valve valves[12] = {
  Valve(1, 12000),
  Valve(2, 11000),
  Valve(3, 10000),
  Valve(4, 9000),
  Valve(5, 8000),
  Valve(6, 7000),
  Valve(7, 7000),
  Valve(8, 8000),
  Valve(9, 9000),
  Valve(10, 10000),
  Valve(11, 11000),
  Valve(12, 12000),
};

// extend pin , retract pin
Cylinder exitCylinder(13, 14);
Cylinder entryCylinder(15, 16);

// pin
ConveyorBelt conveyorBelt(17);

// pin, steady state timeout
// 30 seconds considered steadystate of photoEye.
PhotoEye photoEye(18, 30000);

#define TIME_TO_CLEAR_BOTTLE 30000

void setup() {
  reset();
}

void loop() {
  delay(TIME_TO_CLEAR_BOTTLE);

  exitCylinder.extend(true);
  entryCylinder.extend(false);

  // Do until photoEye is blocked.
  int isBlocked = HIGH;
  while (photoEye.hasReachedSteadyState() == false || photoEye.getStatus() != isBlocked) {
    updateDigest();
  }

  // Stop conveyer.
  conveyorBelt.enabled(false);

  // Fill all bottles underneath valves.
  int length = sizeof(valves) / sizeof(Valve);
  for (int i = 0; i < length; i++) {
    valves[i].enabled(true);
  }

  // Wait for all bottles to be filled.
  boolean hasAllBottlesBeenFilled;
  do {
    hasAllBottlesBeenFilled = true;
    for (int i = 0; i < length; i++) {
      // When isEnabled == false means that the valve has filled the bottle.
      hasAllBottlesBeenFilled = hasAllBottlesBeenFilled && (valves[i].isEnabled() == false);
    }
    updateDigest();
  } while (hasAllBottlesBeenFilled == false);


  // Repeat
  reset();
}



void reset() {
  // Shut off all valves.
  int length = sizeof(valves) / sizeof(Valve);
  for (int i = 0; i < length; i++) {
    valves[i].enabled(false);
  }

  exitCylinder.extend(false);
  entryCylinder.extend(true);

  conveyorBelt.enabled(true);
}



void updateDigest() {
  photoEye.updateDigest();

  // Call updateDigest on all valves.
  int length = sizeof(valves) / sizeof(Valve);
  for (int i = 0; i < length; i++) {
    valves[i].updateDigest();
  }
}
