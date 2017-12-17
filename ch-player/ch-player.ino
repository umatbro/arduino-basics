#include "music.h"
#include "music_lib.h"

using Music::Melody;
Melody betlejem;

void setup() {
	Serial.begin(9600);
	betlejem = MusicLib::PRZYBIEZELI_DO_BETLEJEM;
	betlejem.set_tempo(200);
	betlejem.setPin(A5);
	betlejem.play();
}

void loop() {
	while(true){}
}
