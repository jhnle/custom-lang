#include "vowel.h"
#include <map>

std::string Vowel::getStrHeight(Height height) const{
    static std::map<Height, std::string> heights {
        {Height::close, "Close"},
        {Height::nearClose, "Near-Close"},
        {Height::closeMid, "Close-Mid"},
        {Height::mid, "Mid"},
        {Height::openMid, "Open-Mid"},
        {Height::nearOpen, "Near-Open"},
        {Height::open, "Open"}
    };

    std::map<Height, std::string>::iterator it;

    it = heights.find(height);
    if (it != heights.end()) {
        return it->second;
    } else {
        return "NA";
    }
}

std::string Vowel::getStrBackness(Backness back) const{
    static std::map<Backness, std::string> backs {
        {Backness::front, "Front"},
        {Backness::central, "Central"},
        {Backness::back, "Back"}
    };

    std::map<Backness, std::string>::iterator it;

    it = backs.find(back);
    if (it != backs.end()) {
        return it->second;
    } else {
        return "NA";
    }
}

std::string Vowel::getStrRounding(Rounding roun) const{
    static std::map<Rounding, std::string> rouns {
        {Rounding::unrounded, "Unrounded"},
        {Rounding::lessRounded, "Less-rounded"},
        {Rounding::rounded, "Rounded"},
        {Rounding::moreRounded, "More-rounded"}
    };

    std::map<Rounding, std::string>::iterator it;

    it = rouns.find(roun);
    if (it != rouns.end()) {
        return it->second;
    } else {
        return "NA";
    }
}

std::string Vowel::getStrTngRoot(TongueRoot ton) const{
    static std::map<TongueRoot, std::string> tons {
        {TongueRoot::retracted, "Retracted"},
        {TongueRoot::advanced, "Advanced"}
    };

    std::map<TongueRoot, std::string>::iterator it;

    it = tons.find(ton);
    if (it != tons.end()) {
        return it->second;
    } else {
        return "";
    }
}
