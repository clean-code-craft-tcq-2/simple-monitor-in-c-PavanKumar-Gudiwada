#include <stdbool.h>
#include <stdio.h>
#include "languages.h"
#include "earlyWarnings.h"

#define EARLY_WARNING_PERCENT 5

static char * earlyStr[numberOfLanguages][2] = {{"Approaching minimum", "Approaching peak"},
													{"Nähert sich dem Minimum","Nähert sich dem Maximum"}};

enum violate earlyWarning(float paramValue, float upperLim, float lowerLim)
{
	float lowerWarningLimit, upperWarningLimit, buffer;
	
	buffer = EARLY_WARNING_PERCENT / 100.0 * upperLim;
	
	lowerWarningLimit = lowerLim + buffer;
	upperWarningLimit = upperLim - buffer;
	
	if((paramValue > lowerLim)&&(paramValue < lowerWarningLimit)){
		return 0;
	}
	else if((paramValue > upperWarningLimit)&&(paramValue < upperLim)){
		return 1;
	}
	
	return 2;
}

void alertEarlyWarning(char * paramName, bool isOk, int languageNumber)
{
	if(isOk == 0)
	{
		printf("Warning: %s-%s!\n",earlyStr[languageNumber][0] , paramName );
	}
	else if(isOk == 1)
	{
		printf("Warning: %s-%s!\n",earlyStr[languageNumber][1] , paramName );
	}
}
