#ifndef MORPHEME_GEN_H
#define MORPHEME_GEN_H

#include "../units/soundsystem.h"
#include "root_morph.h"
#include "function_morph.h"
#include "derivational_affix.h"
#include "inflectional_affix.h"

RootMorph makeRootMorph(SoundSystem&, std::array<int, 4>&, std::array<int, 4>&);
FunctionMorph makeFuncMorph(SoundSystem&, std::array<int, 4>&, std::array<int, 4>&);
DerivationalAffix makeDerivAffix(SoundSystem&, std::array<int, 4>&, std::array<int, 4>&);
InflectionalAffix makeInflecAffix(SoundSystem&, std::array<int, 4>&, std::array<int, 4>&);

#endif
