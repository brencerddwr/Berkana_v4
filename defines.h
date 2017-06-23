#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

// How many leds are in the strip?
#define NUM_LEDS 12
// Data pin that led data will be written out over
#define DATA_PIN 11
// define analog color pins for color selector output
#define REDPIN   5
#define GREENPIN 6
#define BLUEPIN  3
// These #defines make it easy to set the LCD backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

// define the delay between frames in milliseconds.
unsigned int menuDelay = 500;

// define initial intensity levels
byte high_intensity = 128;

// This is an array of leds.  One item for each led in your strip.
CRGBArray <NUM_LEDS> leds;

// setup analog control
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
unsigned int sensorValue;        // value read from the pot

unsigned long last_millis;
unsigned long current_millis;
byte brightness = high_intensity;
unsigned long last_button;
byte chasePostiion=0;
unsigned long lastRandomizerChange;
unsigned long randomizerInterval = 600000L;

// Kelley Pattern variables
int F16pos = 0;
byte F16delta = 1;
byte Width = 3; // width of line
unsigned int InterframeDelay = 10; //ms

uint8_t gCurrentTrackNumber = 0; // Index number of which pattern is current
uint8_t gCurrentUITrackNumber; //index number of current menu pattern

uint8_t buttons;

bool setHue = true;
bool setSaturation = false;
uint8_t randomizerTrackNumber;
// logical order arrays

// start of logical array one
int logical_array_one_start = 2; //the range of this variable is 0 to NUM_LEDS-1
int logical_array_one[NUM_LEDS/2];
int logical_array_two[NUM_LEDS/2];

// List of patterns to cycle through.  Each is defined as a separate function below.

typedef void (*SimplePattern)();
typedef SimplePattern SimplePatternList[];
typedef struct { SimplePattern mPattern; char mName[20]; bool mUIVariable; byte mColorCycle; uint16_t mFPS; uint8_t mHue; uint8_t mSaturation; byte mLcdColor;} PatternTimeAndFPS;
typedef PatternTimeAndFPS PatternTimeAndFPSList[];

//format {subroutine name, name of pattern to display, enable variables in ui, color cycle(0=none,1=down, 2=up), frames per second, hue, saturation, lcd color}
PatternTimeAndFPSList gPlaylist = {
	{ kelley_pattern_new,"Kelley Red",0,0,60,0,255,RED},
	{ kelley_pattern_new,"Kelley Orange",0,0,60,32,255,YELLOW},
	{ kelley_pattern_new,"Kelley Yellow",0,0,60,64,255,YELLOW},
	{ kelley_pattern_new,"Kelley Green",0,0,60,96,255,GREEN},
	{ kelley_pattern_new,"Kelley Aqua",0,0,60,128,255,BLUE},
	{ kelley_pattern_new,"Kelley Blue",0,0,60,160,255,BLUE},
	{ kelley_pattern_new,"Kelley Purple",0,0,60,192,255,VIOLET},
	{ kelley_pattern_new,"Kelley White",0,0,60,0,0,WHITE},
	{ kelley_pattern_new,"Kelley Pink",0,0,60,224,255,RED},
	{ kelley_pattern_new,"Kelley Variable",1,0,60,0,255,TEAL},
	{ kelley_pattern_new,"Kelley Rainbow",0,2,60,160,255,BLUE},
	{ chase_sub,"Rainbow Chase",0,1,12,0,255,GREEN},
	{ cycle_sub,"Rainbow Cycle",0,1,10,0,255,BLUE},
	{randomizer,"Randomizer",0,0,75,0,255,RED}

};

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

