#pragma once
#ifndef _MUSIC_H
#define _MUSIC_H

#include <Arduino.h>
namespace Music
{
	namespace Freq 
	{
		const int  PAUSE = 0;
		// oktawa mała
		const int  g0 = 196;
		const int  h0 = 246;
		// oktawa razkreślna
		const int  c1 = 261;
		const int  d1 = 293;
		const int  e1 = 329;
		const int  f1 = 349;
		const int  g1 = 392;
		const int  a1 = 440;
		const int  h1 = 493;
		
		const int cis1 = 277, des1 = 277;
		const int dis1 = 311, es1 = 311;
		const int fis1 = 370, ges1 = 370;
		const int gis1 = 415, as1 = 415;
		const int ais1 = 466, b1 = 466;
		// oktawa dwukreślna
		const int  c2 = 523;
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