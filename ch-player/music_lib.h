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

	Music::Melody melody_out_of_notes(int* freqs, int* lens, int notes_len, int tempo=110)
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
		
		return Music::Melody(freqs, lens, notes_len, tempo);
	}
	
	namespace Betlejem
	{
		int freqs[] = {
			c1, h0, c1, d1, e1, d1, e1, f1, g1, a1, g1,
			c1, h0, c1, d1, e1, d1, e1, f1, g1, a1, g1, //22
			c2, g1, g1, a1, g1, f1, e1, f1, PAUSE, f1, a1, g1, f1, e1, d1,
			e1, f1, g1, e1, d1, c1, //21
			c2, g1, g1, a1, g1, f1, e1, f1, PAUSE, f1, a1, g1, f1, e1, d1,
			e1, f1, g1, e1, d1, c1
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
		int freqs[] = {c1, d1, PAUSE, e1};
		int lens[] = {hn, en, en, hn};
		const int len = 4;
	}
	Music::Melody PRZYBIEZELI_DO_BETLEJEM = melody_out_of_notes(Betlejem::freqs, Betlejem::lens, Betlejem::len);
	Music::Melody SIMPLE = melody_out_of_notes(Simple::freqs, Simple::lens, Simple::len);
}

#endif