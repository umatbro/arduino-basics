#pragma once
#ifndef _MUSIC_H
#define _MUSIC_H

#include <Arduino.h>
namespace Music
{
	namespace Freq 
	{
		const int  PAUSE = 0;
		const int  g3 = 196;
		const int  h3 = 246;
		const int  c4 = 261;
		const int  d4 = 293;
		const int  e4 = 329;
		const int  f4 = 349;
		const int  g4 = 392;
		const int  a4 = 440;
		const int  h4 = 493;
		const int  c5 = 523;

		const int cis4 = 277, des4 = 277;
		const int dis4 = 311, es4 = 311;
		const int fis4 = 370, ges4 = 370;
		const int gis4 = 415, as4 = 415;
		const int ais4 = 466, b4 = 466;
	}
	
	namespace Tempo
	{
		const int LARGO		= 40;
		const int LENTO		= 60;
		const int ADAGIO	= 70;
		const int MODERATO	= 115;
		const int ALLEGRO	= 137;
		const int VIVO		= 160;
		const int PRESTO 	= 180;
		const int PRESTISSIMO = 200;
	}
	
	class Melody
	{
	private:
		int pin;
		int* freqs;
		int* durations;
		int lens;
		int tempo;
	public:
		Melody();
		Melody(int* frequencies, int* durations, int notes_len, const int tempo=Tempo::MODERATO);
		void set_tempo(const int tempo);
		void setPin(int pin);
		void play();
		//void play(const int tempo=Tempo::MODERATO);
	};
	
}

void play_note(int pin, int freq, long duration, int separation=50);

#endif