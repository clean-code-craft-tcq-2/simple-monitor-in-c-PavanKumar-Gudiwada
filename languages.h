
enum languages_t{
	English = 0,
	Deutsch,
	numberOfLanguages //add any new language above this line only
};

static char * highLowStr[numberOfLanguages][2] = {{"low", "high"},
											{"niedrig","hoch"}};
	
static char * suppotStr[numberOfLanguages] = {"out of range",
									"auﬂer Reichweite"};
