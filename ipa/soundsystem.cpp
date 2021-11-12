#include "soundsystem.h"

/* A phoneme symbol is valid if its length is between
 * 1 and the MAX_PHONEME_LENGTH (inclusive), is not the empty string
 * and does not contain spaces.
 */
bool SoundSystem::isValidSym(std::string str) const{
    if (str.length() > 0 && str.length() <= MAX_PHONEME_LENGTH
        && str.find(" ") == std::string::npos)
        return true;
    else
        return false;
}

/* Returns 1 if true, 0 if false, -1 if neither */
int SoundSystem::getBoolFromStr(std::string str) const{
    if (str == "TRUE")
        return 1;
    else if (str == "FALSE")
        return 0;
    else
        return -1;
}

int SoundSystem::getPlaceFromStr(std::string str) const{
    if (str == "BILABIAL")
        return BILABIAL;
    else if (str == "LABIODENTAL")
        return LABIODENTAL;
    else if (str == "DENTAL")
        return DENTAL;
    else if (str == "ALVEOLAR")
        return ALVEOLAR;
    else if (str == "POST_ALVEOLAR")
        return POST_ALVEOLAR;
    else if (str == "RETROFLEX")
        return RETROFLEX;
    else if (str == "PALATAL")
        return PALATAL;
    else if (str == "VELAR")
        return VELAR;
    else if (str == "UVULAR")
        return UVULAR;
    else if (str == "PHARYNGEAL")
        return PHARYNGEAL;
    else if (str == "GLOTTAL")
        return GLOTTAL;
    else
        return -1;
}

int SoundSystem::getMannerFromStr(std::string str) const{
    if (str == "PLOSIVE")
        return PLOSIVE;
    else if(str == "NASAL")
        return NASAL;
    else if(str == "TRILL")
        return TRILL;
    else if(str == "FLAP")
        return FLAP;
    else if (str == "FRICATIVE")
        return FRICATIVE;
    else if (str == "LATERAL_FRICATIVE")
        return LATERAL_FRICATIVE;
    else if (str == "AFFRICATE")
        return AFFRICATE;
    else if (str == "APPROXIMANT")
        return APPROXIMANT;
    else if (str == "LATERAL_APPROXIMANT")
        return LATERAL_APPROXIMANT;
    else
        return -1;
}

int SoundSystem::getHeightFromStr(std::string str) const{
    if (str == "CLOSE")
        return CLOSE;
    else if (str == "NEAR_CLOSE")
        return NEAR_CLOSE;
    else if (str == "CLOSE_MID")
        return CLOSE_MID;
    else if (str == "MID")
        return MID;
    else if (str == "OPEN_MID")
        return OPEN_MID;
    else if (str == "NEAR_OPEN")
        return NEAR_OPEN;
    else if (str == "OPEN")
        return OPEN;
    else
        return -1;
}

int SoundSystem::getPartFromStr(std::string str) const{
    if (str == "FRONT")
        return FRONT;
    else if (str == "CENTRAL")
        return CENTRAL;
    else if (str == "BACK")
        return BACK;
    else
        return -1;
}
