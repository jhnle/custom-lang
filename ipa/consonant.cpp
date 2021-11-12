#include "consonant.h"

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
