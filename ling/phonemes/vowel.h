#ifndef VOWEL_H
#define VOWEL_H

#include "phoneme.h"

class Vowel : public Phoneme {
private:
    std::string getStrHeight (Height) const;
    std::string getStrPart (Part) const;
    std::string getStrRounding (Rounding) const;
    std::string getStrLength (Length) const;
    std::string getStrTone (Tone) const;
public:
    Vowel(std::string symbol, float freq, Height height, Part part, Voicing voicing, Rounding rounding, Coarticulation coarticulation,
          Tone tone, Length length) {

        type = VOWEL;
        this->symbol = symbol;
        this->freq = freq;

        // |Length|Tone|Coarticulation|Rounding|Voicing|Part|Height|Type
        id = (length * 0x10000000) + (tone * 0x1000000) + (coarticulation * 0x100000) + (rounding * 0x10000)
            + (voicing * 0x1000) + (part * 0x100) + (height * 0x10) + (VOWEL);

        std::string voic = getStrVoicing(voicing);
        std::string coart = getStrCoart(coarticulation);
        std::string ton = getStrTone(tone);
        std::string len = getStrLength(length);

        desc += (len != "" ? len + " " : "" ) + (ton != "" ? ton + " " : "" ) + (coart != "" ? coart + " " : "" )
             + (voic != "Voiced" ? voic + " " : "" ) + getStrHeight(height) + " " + getStrPart(part) + " "
             + getStrRounding(rounding) + " Vowel";
    }

    Vowel() {}
};

#endif
