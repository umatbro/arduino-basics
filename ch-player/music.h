#ifndef _MUSIC_H
#define _MUSIC_H

namespace Music
{
	namespace Freq {
		const int  PAUSE = 0;
		const int  g3 = 196;
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
	
	namespace Tempo{
		const int LARGO		= 40;
		const int LENTO		= 60;
		const int ADAGIO	= 70;
		const int MODERATO	= 115;
		const int ALLEGRO	= 137;
		const int VIVO		= 160;
		const int PRESTO 	= 180;
		const int PRESTISSIMO = 200;
	}
	// notes lengths
	enum Duration {
		WHOLE = 1,
		HALF = 2,
		QUATER = 4,
		EIGTH = 8,
		SIXTEENTH = 16
	};


	class Note
	{
	private:
		float calc_duration(Duration& duration, int tempo);
		void print_values(const int& tempo, const int& play_time);
		
	public:
		int freq;
		int duration;
		
		Note(int height, int duration);
		void play(const int& pin, const int& tempo=Tempo::MODERATO);
		//void play(Duration& duration);
	};

	class Melody
	{
	private:
		int notes_length;
	public:
		Melody(int pin, Note* notes, int notes_len, int tempo=60);
	};

	static Melody melody_out_of_notes(int pin, int* notes, int* notes_durations, int* notes_len, int tempo=60);
	static Melody melody_out_of_notes(int pin, Note* notes, int notes_len, int tempo=60);
}
#endif