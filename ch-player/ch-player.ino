#include "music.h"

using namespace Music;
namespace melodies{
	using namespace Freq;
  Note NOTES[] = {
    Note(g3, Duration(QUATER)), Note(c4, Duration(QUATER))
  };
}

void setup() {
	Serial.begin(9600);
	pinMode(A5, OUTPUT);
}

void loop() {
	melodies::NOTES[0].play(A5);
	melodies::NOTES[1].play(A5);
	while(true){}
}
