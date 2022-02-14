#include "checker.h"

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
