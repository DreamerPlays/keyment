#include "audio_out.h"
#include <string>

anshub::AudioOut audio;
void Fn(std::string n) {
  audio.Play("Sounds/" + n + ".aiff", false);
}
void FnS(std::string n) {
  audio.Stop("Sounds/" + n + ".aiff", true);
}

void FnL(std::string n) {
  audio.Load("Sounds/" + n + ".aiff", true);
}