#ifndef SYLLABLE_GEN_H
#define SYLLABLE_GEN_H

#include "syllable.h"
#include "../units/soundsystem.h"

Syllable makeSyllable(SoundSystem);

std::array<int, 4> genSyllableType(std::array<int, 4>, std::array<int, 4>);

#endif
