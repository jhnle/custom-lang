#ifndef VOWEL_H
#define VOWEL_H

#include "phoneme.h"

class Vowel : public Phoneme {
private:
    Height height;
    Part part;
    bool isRounded;
    bool isTense;

    std::string getStrHeight (Height) const;
    std::string getStrPart (Part) const;
    std::string getStrRounded (bool) const;
    std::string getStrTense (bool) const;
public:
    Vowel(std::string symbol, bool isVoiced, Height height, Part part, Diacritic diacritic, bool isRounded, bool isTense) {

        type = VOWEL;
        this->diacritic = diacritic;
        this->symbol = symbol;
        this->isVoiced = isVoiced;
        this->height = height;
        this->part = part;
        this->isRounded = isRounded;
        this->isTense = isTense;

        id = (diacritic * 0x100000) + (isTense * 0x10000) + (isRounded * 0x1000) + (part * 0x100) + (height * 0x10) + (VOWEL);

        desc += ((!isVoiced) ? getStrVoiced(isVoiced) + " " : "") + getStrHeight(height) + " "
                + getStrPart(part) + " " + getStrRounded(isRounded) + " "
                + getStrTense(isTense) + " Vowel";
    }

    Vowel() {}

    bool isSymRounded() const { return isRounded; }
    bool isSymTense() const { return isTense; }
    Height getHeight() const { return height; }
    Part getPart() const { return part; }

};

#endif
