#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdarg.h>

#include "limits.h"
#include "languages.h"
#include "rangeChecker.h"

enum languages_t chosenLanguage = English;//choose based on enum present in switches.h file

bool highLow;//indicates high or low violation 1=high violation, 0=low violation

struct parameter{
	char * name;
	float value;
	float lowerLimit;
	float upperLimit;
};

void alert(char * paramName, bool isOk, int languageNumber)
{
	if(!isOk)
	{
		printf("%s %s %s!\n", paramName, suppotStr[languageNumber], highLowStr[languageNumber][highLow]);
	}
}

int batteryIsOk(struct parameter paramList[3], int noParameters) {
	int i;
	bool paramOk;
	
	for(i =0; i < noParameters; i++)
	{
		paramOk = isParamInRange(paramList[i].value, paramList[i].upperLimit, paramList[i].lowerLimit);
		
		alert(paramList[i].name, paramOk, chosenLanguage);
		
		if(!paramOk)
		{
			return 0;
		}
	}
	
	return 1;
}

int main() {
	struct parameter paramList[3] = {{"Temperature", 25.0, LOWER_LIM_TEMPERATURE, UPPER_LIM_TEMPERATURE}, {"State of Charge", 70.0, LOWER_LIM_SOC, UPPER_LIM_SOC}, {"Charge rate", 0.7, LOWER_LIM_CHARGE_RATE, UPPER_LIM_CHARGE_RATE}};
	assert(batteryIsOk(paramList, 3));//all is well

	paramList[0].value = 50.0;
	paramList[1].value = 85.0;
	paramList[2].value = 0.0;
	assert(!batteryIsOk(paramList, 3));//temperature out of range high
	
	paramList[0].value = -10.0;
	paramList[1].value = 85.0;
	paramList[2].value = 0.0;
	assert(!batteryIsOk(paramList, 3));//temperature out of range low

	paramList[0].value = 25.0;
	paramList[1].value = 85.0;
	paramList[2].value = 0.0;  
	assert(!batteryIsOk(paramList, 3));//SOC out of range high

	paramList[0].value = 25.0;
	paramList[1].value = 10.0;
	paramList[2].value = 0.0;
	assert(!batteryIsOk(paramList, 3));//SOC out of range low
 
	paramList[0].value = 25.0;
	paramList[1].value = 70.0;
	paramList[2].value = 0.9; 
	assert(!batteryIsOk(paramList, 3));//rate of charge out of range high
}
