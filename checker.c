#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdarg.h>

#include "limits.h"

bool highLow;//indicates high or low violation 1=high violation, 0=low violation
char * highLowStr[] = {"low", "high"};

bool isRangeHigh(float paramValue, float upperLim)
{
	if(paramValue > upperLim)
	{
		highLow = 1;
		return 1;
	}else return 0;
}

bool isRangeLow(float paramValue, float lowerLim)
{
	if(paramValue < lowerLim)
	{
		highLow = 0;
		return 1;
	}else return 0;
}

bool isParamInRange(float paramValue, float upperLim, float lowerLim)
{
	if(isRangeHigh(paramValue, upperLim))
	{
		return 0;
	}
	else if(isRangeLow(paramValue, lowerLim))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void alert(char * paramName, bool isOk)
{
	if(!isOk)
	{
		printf("%s out of range %s!\n", paramName, highLowStr[highLow]);
	}
}

//note maintain the parameter-names list and their limits in limits.h file
int batteryIsOk(double parameters, ...) {//parameter list in order: temperature, soc, chargeRate, append to this list to define order consistent with limits.h file
	bool paramOk;
	float upperLimit, lowerLimit;
	int i;
	va_list parameterList;
	
	/* initialize valist for num number of arguments */
    va_start(parameterList, parameters);
	
	for(i=0 ;i < parameters; i++)
	{
		double param = va_arg(parameterList, double);
		//printf("parameter %f \t upper limit: %f \t lower limit: %f\n", param, upperLimits[i], lowerLimits[i]);
		paramOk = isParamInRange(param, upperLimits[i], lowerLimits[i]);
		alert(paramNames[i],paramOk);
		if(!paramOk)
		{
			/* clean memory reserved for valist */
    		va_end(parameterList);
			return 0;
		}
	}
	
	/* clean memory reserved for valist */
    va_end(parameterList);

  return 1;
}

int main() {
  assert(batteryIsOk(3, 25.0, 70.0, 0.7));//all is well
  
  assert(!batteryIsOk(3, 50.0, 85.0, 0.0));//temperature out of range high
  assert(!batteryIsOk(3, -10.0, 85.0, 0.0));//temperature out of range low
  
  assert(!batteryIsOk(3, 25.0, 85.0, 0.0));//SOC out of range high
  assert(!batteryIsOk(3, 25.0, 10.0, 0.0));//SOC out of range low
  
  assert(!batteryIsOk(3, 25.0, 70.0, 0.9));//rate of charge out of range high
}
