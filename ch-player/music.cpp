#include "music.h"
using namespace Music;

Melody::Melody(int* frequencies, int* durations, int notes_len, int tempo_):
pin(0),
freqs(frequencies),
durations(durations),
lens(notes_len),
tempo(tempo_)
{
	// this->pin = 0;
	// this->freqs = frequencies;
	// this->durations = durations;
	// this->lens = notes_len;
	// this->tempo = tempo;
}

Melody::Melody()
{
	Melody(NULL, NULL, 0, 100);
}

void Melody::set_tempo(const int tempo)
{
	this->tempo = tempo;
}

void Melody::setPin(int pin)
{
	this-> pin = pin;
}

void Melody::play()
{
	float tempof = (float) this->tempo;
	for (int i = 0; i < this->lens; i++)
	{
		float durationf = (float) this->durations[i];
		float dur = 60.0 / (durationf * tempof);
		// time in ms
		long play_time = (long) 4000 * dur;
		play_note(this->pin, this->freqs[i], play_time);
	}
}

void play_note(int pin, int freq, long duration, int separation)
{
	/**
	* @param pin: pin on which buzzer is connected
	* @param freq: frequencies
	* @param duration: duration in ms
	* @param separation: notes will be separated with given amount of time.
	*/
	Serial.print("freq: ");
	Serial.print(freq);
	Serial.print(" duration: ");
	Serial.println(duration);
	if (freq){
		tone(pin, freq);
		delay(duration-separation);
		noTone(pin);
		delay(separation);
	} else {
		delay(duration);
	}
}