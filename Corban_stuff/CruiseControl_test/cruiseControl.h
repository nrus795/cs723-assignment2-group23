#ifndef CRUISECONTROL_DATA_H
#define CRUISECONTROL_DATA_H

#include <stddef.h>
#include <stdbool.h>
// #include <csimul.h>
#ifndef BASIC_TYPES_DEFINED
#define BASIC_TYPES_DEFINED
typedef int boolean;
#endif
// typedef int boolean;

float regulateThrottle(boolean isGoingOn, float cruiseSpeed, float vehicleSpeed);
float saturateThrottle(float throttleIn, bool *saturate);

#endif
