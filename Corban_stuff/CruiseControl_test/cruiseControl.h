#ifndef CRUISECONTROL_DATA_H
#define CRUISECONTROL_DATA_H

// #include <csimul.h>
// #include <csimul.h>
#include <stddef.h>
// #include <csimul.h>
#include <stdbool.h>
// #include <csimul.h>
// typedef int boolean;

float regulateThrottle(boolean isGoingOn, float cruiseSpeed, float vehicleSpeed);
float saturateThrottle(float throttleIn, bool* saturate);

#endif
