

enum violate{
	earlyLow,
	earlyHigh,
	noEarlyWarning
} violation;
extern enum violate earlyWarning(float paramValue, float upperLim, float lowerLim);
extern void alertEarlyWarning(char * paramName, bool isOk, int languageNumber);
