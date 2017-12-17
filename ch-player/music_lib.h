#ifndef _MUSICLIB
#define _MUSICLIB
#include <Arduino.h>
#include "music.h"
const int wn = 1;
const int hn = 2;
const int qn = 4;
const int en = 8;
namespace MusicLib
{
	using namespace Music::Freq;

	Music::Melody melody_out_of_notes(int* freqs, int* lens, int notes_len)
	{
		// Note* notes = new Note[notes_len];
		Serial.println("====================");
		for (int i = 0; i < notes_len; i++)
		{
			Serial.print("freq: ");
			Serial.print(freqs[i]);
			Serial.print(" len: ");
			Serial.println(lens[i]);
		}
		Serial.println("====================");
		
		return Music::Melody(freqs, lens, notes_len);
	}
	
	namespace Betlejem
	{
		int freqs[] = {
			c4, h3, c4, d4, e4, d4, e4, f4, g4, a4, g4,
			c4, h3, c4, d4, e4, d4, e4, f4, g4, a4, g4, //22
			c5, g4, g4, a4, g4, f4, e4, f4, PAUSE, f4, a4, g4, f4, e4, d4,
			e4, f4, g4, e4, d4, c4, //21
			c5, g4, g4, a4, g4, f4, e4, f4, PAUSE, f4, a4, g4, f4, e4, d4,
			e4, f4, g4, e4, d4, c4
		};
		int lens[] = {
			en, en, en, en, en, en, en, en, qn, qn, hn,
			en, en, en, en, en, en, en, en, qn, qn, hn,
			qn, en, en, en, en, en, en, en, en, en, en, en, en, en, en,
			qn, qn, hn, qn, qn, hn,
			qn, en, en, en, en, en, en, en, en, en, en, en, en, en, en,
			qn, qn, hn, qn, qn, hn
		};
		const int len = 64;
	}
	namespace Simple
	{
		int freqs[] = {c4, d4, PAUSE, e4};
		int lens[] = {hn, en, en, hn};
		const int len = 4;
	}
	Music::Melody PRZYBIEZELI_DO_BETLEJEM = melody_out_of_notes(Betlejem::freqs, Betlejem::lens, Betlejem::len);
	Music::Melody SIMPLE = melody_out_of_notes(Simple::freqs, Simple::lens, Simple::len);
}

#endif