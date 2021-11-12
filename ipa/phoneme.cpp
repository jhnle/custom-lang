#include "phoneme.h"

std::string Phoneme::getStrVoiced (bool isVoiced) const{
    if (isVoiced)
        return "Voiced";
    else
        return "Voiceless";
}
