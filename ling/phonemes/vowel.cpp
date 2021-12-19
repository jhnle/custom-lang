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

std::string Vowel::getStrTone(Tone tone) const {
    static std::map<Tone, std::string> tones {
        {EXTRA_LOW, "Extra-low"},
        {LOW, "Low"},
        {T_MID, "Mid"},
        {HIGH, "High"},
        {EXTRA_HIGH, "Extra high"},
        {DOWNSTEP, "Downstep"},
        {UPSTEP, "Upstep"}
    };

    std::map<Tone, std::string>::iterator it;

    it = tones.find(tone);
    if (it != tones.end()) {
        return it->second;
    } else {
        return "";
    }
}

std::string Vowel::getStrRounding(Rounding roun) const{
    static std::map<Rounding, std::string> rouns {
        {UNROUNDED, "Unrounded"},
        {LESS_ROUNDED, "Less-rounded"},
        {ROUNDED, "Rounded"},
        {MORE_ROUNDED, "More-rounded"}
    };

    std::map<Rounding, std::string>::iterator it;

    it = rouns.find(roun);
    if (it != rouns.end()) {
        return it->second;
    } else {
        return "NA";
    }
}

std::string Vowel::getStrLength(Length len) const{
    static std::map<Length, std::string> lens {
        {EXTRA_SHORT, "Extra-short"},
        {HALF_LONG, "Half-long"},
        {LONG, "long"},
        {EXTRA_LONG, "Extra-long"}
    };

    std::map<Length, std::string>::iterator it;

    it = lens.find(len);
    if (it != lens.end()) {
        return it->second;
    } else {
        return "";
    }
}
