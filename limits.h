#include <math.h>

#define LOW_TEMPERATURE  0 
#define HIGH_TEMPERATURE 45

#define LOW_SOC  20 
#define HIGH_SOC 80

#define LOW_CHARGERATE (-INFINITY)
#define HIGH_CHARGERATE 0.8

float upperLimits[3] = {45, 80, 0.8};
float lowerLimits[3] = {0, 20, -INFINITY};

char * paramNames[] = {"Temperature", "State of Charge", "Charge Rate"};
