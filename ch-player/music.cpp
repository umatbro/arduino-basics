#include <Arduino.h>
#include "music.h"

using namespace Music;
Note::Note(int freq, int duration)
{
	this -> freq = freq;
	this -> duration = duration;
}

void Note::play(const int& pin, const int& tempo){
	float tempof = (float) tempo;
	float durationf = (float) this -> duration;
	float dur = 60.0 / (durationf * tempof);
	// time in ms
	long play_time = (long) 4000 * dur; // 4k instead 1k because we take QUATER of a unit of tempo
	tone(pin, this -> freq);
	this -> print_values(tempo, play_time);
	delay(play_time);
	noTone(pin);
}


void Note::print_values(const int& tempo, const int& play_time){
	Serial.print("freq: ");
	Serial.print(this -> freq);
	Serial.print(" tempo: ");
	Serial.print(tempo);
	Serial.print(" duration: ");
	Serial.print(this -> duration);
	Serial.print(" play_time: ");
	Serial.println(play_time);
}