#ifndef CRUISECONTROL_DATA_H
#define CRUISECONTROL_DATA_H

#include <stdbool.h>

float regulateThrottle(bool isGoingOn, float cruiseSpeed, float vehicleSpeed);
float saturateThrottle(float throttleIn, bool* saturate);

#endif
