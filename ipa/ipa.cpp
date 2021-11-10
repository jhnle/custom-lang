#include <iostream>
#include "ipa.h"

std::string SoundUnit::getStrVoiced (bool isVoiced) {
    if (isVoiced)
        return "Voiced";
    else
        return "Voiceless";
}

std::string Consonant::getStrPlace (Place place) {
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

std::string Consonant::getStrManner(Manner manner) {
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

std::string Vowel::getStrHeight(Height height) {
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

std::string Vowel::getStrPart(Part part) {
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

std::string Vowel::getStrRounded(bool isRounded) {
    if (isRounded)
        return "Rounded";
    else
        return "Unrounded";
}

std::string Vowel::getStrTense(bool isTense) {
    if (isTense)
        return "Tense";
    else
        return "Lax";
}
