// plays Panie Janie
namespace Notes
{
  int   g = 195;
  int  c1 = 261;
  int  d1 = 293;
  int  e1 = 329;
  int  f1 = 349;
  int  g1 = 392;
  int  a1 = 440;
  int  h1 = 493;
  int  c2 = 523;
}

using namespace Notes;

void play_sound(int pin, int sound, float len=1, int tempo=500){
  float note_time = len * tempo;
  tone(pin, sound, note_time);
  delay(note_time);
}

void play_sequence(int pin, int* notes, float* note_lens, int notes_size){
  for(int i = 0; i < notes_size; i++){
    play_sound(pin, notes[i], note_lens[i]);
  }
}
 
void setup() {
  int notes[] = {
    c1, d1, e1, c1, c1, d1, e1, c1,
    e1, f1, g1,     e1, f1, g1, 
    g1, a1, g1, f1, e1, c1,
    g1, a1, g1, f1, e1, c1,
    c1, g, c1,
    c1, g, c1
  };
  float note_lens[] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 2,  1, 1 ,2,
    0.5, 0.5, 0.5, 0.5, 1, 1,
    0.5, 0.5, 0.5, 0.5, 1, 1,
    1, 1, 2,
    1, 1, 3 
  };
  
  play_sequence(A5, notes, note_lens, 32);
}
 
void loop() {

}
