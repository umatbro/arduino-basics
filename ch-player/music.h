#ifndef _MUSIC_H
#define _MUSIC_H

namespace Notes
{
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

class Note
{
public:
	int height;
	int duration;
	
	Note(int height, int duration);
};

class Melody
{
private:
	int notes_length;
public:
	Melody(Note* notes, int notes_len);
};

static Melody melody_out_of_notes(int* notes, int* notes_durations, int* notes_len);
static Melody melody_out_of_notes(Note* notes, int notes_len);

#endif