#include "vowel.h"

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
