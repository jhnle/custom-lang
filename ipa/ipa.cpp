#include <iostream>
#include "ipa.h"

#define MAX_PHONEME_LENGTH 10

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

bool SoundSystem::isValidSym(std::string str) const{
    if (str.length() > 0 && str.length() <= MAX_PHONEME_LENGTH
        && str.find(" ") == std::string::npos)
        return true;
    else
        return false;
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

std::string Phoneme::getStrVoiced (bool isVoiced) const{
    if (isVoiced)
        return "Voiced";
    else
        return "Voiceless";
}

std::string Consonant::getStrPlace (Place place) const{
    switch (place) {
        case BILABIAL:
            return "Bilabial";
            break;
        case LABIODENTAL:
            return "Labiodental";
            break;
        case DENTAL:
            return "Dental";
            break;
        case ALVEOLAR:
            return "Alveolar";
            break;
        case POST_ALVEOLAR:
            return "Post Alveolar";
            break;
        case RETROFLEX:
            return "Retroflex";
            break;
        case PALATAL:
            return "Palatal";
            break;
        case VELAR:
            return "Velar";
            break;
        case UVULAR:
            return "Uvular";
            break;
        case PHARYNGEAL:
            return "Pharyngeal";
            break;
        case GLOTTAL:
            return "Glottal";
            break;
        default:
            return "N/A\n";
            break;
    }
}

std::string Consonant::getStrManner(Manner manner) const{
    switch (manner) {
        case PLOSIVE:
            return "Plosive";
            break;
        case NASAL:
            return "Nasal";
            break;
        case TRILL:
            return "Trill";
            break;
        case FLAP:
            return "Flap";
            break;
        case FRICATIVE:
            return "Fricative";
            break;
        case LATERAL_FRICATIVE:
            return "Lateral Fricative";
            break;
        case AFFRICATE:
            return "Affricate";
            break;
        case APPROXIMANT:
            return "Approximant";
            break;
        case LATERAL_APPROXIMANT:
            return "Lateral Approximant";
            break;
        default:
            return "N/A\n";
            break;
        }
}

std::string Vowel::getStrHeight(Height height) const{
    switch (height) {
        case CLOSE:
            return "Close";
            break;
        case NEAR_CLOSE:
            return "Near-Close";
            break;
        case CLOSE_MID:
            return "Close-Mid";
            break;
        case MID:
            return "Mid";
            break;
        case OPEN_MID:
            return "Open-Mid";
            break;
        case NEAR_OPEN:
            return "Near-Open";
            break;
        case OPEN:
            return "Open";
            break;
        default:
            return "N/A\n";
            break;
    }
}

std::string Vowel::getStrPart(Part part) const{
    switch (part) {
        case FRONT:
            return "Front";
            break;
        case CENTRAL:
            return "Central";
            break;
        case BACK:
            return "Back";
            break;
        default:
            return "N/A\n";
            break;
    }
}

std::string Vowel::getStrRounded(bool isRounded) const{
    if (isRounded)
        return "Rounded";
    else
        return "Unrounded";
}

std::string Vowel::getStrTense(bool isTense) const{
    if (isTense)
        return "Tense";
    else
        return "Lax";
}
