#ifndef VOWEL_H
#define VOWEL_H

#include "phoneme.h"

/* Tongue height during vowel production */
enum class Height {
    close,
    nearClose,
    closeMid,
    mid,
    openMid,
    nearOpen,
    open
};

/* Tongue position during vowel production */
enum class Backness {
    front,
    central,
    back
};

// Vowel lip rounding
enum class Rounding {
    unrounded,
    lessRounded,
    rounded,
    moreRounded
};

enum class TongueRoot {
    retracted = 1,
    advanced
};

class Vowel : public Phoneme {
private:
    std::string getStrHeight(Height) const;
    std::string getStrBackness(Backness) const;
    std::string getStrRounding(Rounding) const;
    std::string getStrTngRoot(TongueRoot) const;
public:
    Vowel(std::string symbol, float freq, Height height, Backness backness, Voicing voicing,
          Rounding rounding, Coarticulation coarticulation, TongueRoot root) {

        type = Type::vowel;
        this->symbol = symbol;
        this->freq = freq;

        // |Tongue Root|Coarticulation|Rounding|Voicing|Part|Height|Type
        id = (static_cast<int>(root) * 0x1000000) + (static_cast<int>(coarticulation) * 0x100000)
            + (static_cast<int>(rounding) * 0x10000) + (static_cast<int>(voicing) * 0x1000) + (static_cast<int>(backness) * 0x100)
            + (static_cast<int>(height) * 0x10) + static_cast<int>(Type::vowel);

        std::string voic = getStrVoicing(voicing);
        std::string coart = getStrCoart(coarticulation);
        std::string tng = getStrTngRoot(root);

        desc += (tng != "" ? tng + " " : "" ) + (coart != "" ? coart + " " : "" ) + (voic != "Voiced" ? voic + " " : "" )
             + getStrHeight(height) + " " + getStrBackness(backness) + " " + getStrRounding(rounding) + " Vowel";
    }

    Vowel() {}
};

#endif
