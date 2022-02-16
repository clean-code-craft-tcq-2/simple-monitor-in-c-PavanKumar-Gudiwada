#include <stdbool.h>
#include <stdio.h>
#include "languages.h"
#include "earlyWarnings.h"

#define EARLY_WARNING_PERCENT 5

static char * earlyStr[numberOfLanguages][2] = {{"Approaching minimum", "Approaching peak"},
													{"Nähert sich dem Minimum","Nähert sich dem Maximum"}};
													
bool earlyWarningLow(float paramValue, float lowerLim, float lowerWarningLimit)
{
	if((paramValue > lowerLim)&&(paramValue < lowerWarningLimit)){
		return 1;
	}else{
		return 0;
	}
}

bool earlyWarningHigh(float paramValue, float upperLim, float upperWarningLimit)
{
	if((paramValue > upperWarningLimit)&&(paramValue < upperLim)){
		return 1;
	}else{
		return 0;
	}
}													

enum violate earlyWarning(float paramValue, float upperLim, float lowerLim)
{
	float lowerWarningLimit, upperWarningLimit, buffer;
	bool earlyWarningHighPresent, earlyWarningLowPresent;
	buffer = EARLY_WARNING_PERCENT / 100.0 * upperLim;
	
	lowerWarningLimit = lowerLim + buffer;
	upperWarningLimit = upperLim - buffer;
	
	earlyWarningLowPresent = earlyWarningLow(paramValue, lowerLim, lowerWarningLimit);
	earlyWarningHighPresent = earlyWarningHigh(paramValue, upperLim, upperWarningLimit);
	
	if(earlyWarningLowPresent){
		return earlyLow;
	}else if(earlyWarningHighPresent){
		return earlyHigh;
	}else{
		return noEarlyWarning;
	}
	
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
