#include "music.h"

namespace melodies{
  using namespace Notes;
  Note NOTES[] = {
    Note(g3, 1), Note(c4, 2), Note(d4,1), Note(e4,1)
  };
}

void setup() {
  Serial.begin(9600);
  Note note = Note(Notes::g3, 1);
  Serial.print("Height: ");
  Serial.println(note.height);
  Serial.print("Duration: ");
  Serial.println(note.duration);
  Serial.println(melodies::NOTES[0].height);
}

void loop() {
  // put your main code here, to run repeatedly:

}
