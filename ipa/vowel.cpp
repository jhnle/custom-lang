#include "vowel.h"
#include <map>

std::string Vowel::getStrHeight(Height height) const{
    static std::map<Height, std::string> heights {
        {CLOSE, "Close"},
        {NEAR_CLOSE, "Near-Close"},
        {CLOSE_MID, "Close-Mid"},
        {MID, "Mid"},
        {OPEN_MID, "Open-Mid"},
        {NEAR_OPEN, "Near-Open"},
        {OPEN, "Open"}
    };

    std::map<Height, std::string>::iterator it;

    it = heights.find(height);
    if (it != heights.end()) {
        return it->second;
    } else {
        return "NA";
    }
}

std::string Vowel::getStrPart(Part part) const{
    static std::map<Part, std::string> parts {
        {FRONT, "Front"},
        {CENTRAL, "Central"},
        {BACK, "Back"}
    };

    std::map<Part, std::string>::iterator it;

    it = parts.find(part);
    if (it != parts.end()) {
        return it->second;
    } else {
        return "NA";
    }
}

std::string Vowel::getStrRounded(bool isRounded) const{
    if (isRounded) {
        return "Rounded";
    } else {
        return "Unrounded";
    }
}

std::string Vowel::getStrTense(bool isTense) const{
    if (isTense) {
        return "Tense";
    } else {
        return "Lax";
    }
}
