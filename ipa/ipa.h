#ifndef IPA_H
#define IPA_H

#include <string>
#include <map>

enum Type {
    CONSONANT,
    VOWEL
};

/* Where obstruction occurs during consonant production */
enum Place {
    BILABIAL,
    LABIODENTAL,
    DENTAL,
    ALVEOLAR,
    POST_ALVEOLAR,
    RETROFLEX,
    PALATAL,
    VELAR,
    UVULAR,
    PHARYNGEAL,
    GLOTTAL
};

/* How articulators are used during consonant production */
enum Manner {
    PLOSIVE,
    NASAL,
    TRILL,
    FLAP,
    FRICATIVE,
    LATERAL_FRICATIVE,
    AFFRICATE,
    APPROXIMANT,
    LATERAL_APPROXIMANT
};

/* Tongue height during vowel production */
enum Height {
    CLOSE,
    NEAR_CLOSE,
    CLOSE_MID,
    MID,
    OPEN_MID,
    NEAR_OPEN,
    OPEN
};

/* Tongue position during vowel production */
enum Part {
    FRONT,
    CENTRAL,
    BACK
};

/* Represents a discrete unit of sound */
class SoundSymbol {
private:
    Type type;
    std::string symbol;
    bool isVoiced;

    // Consonant members
    Place place;
    Manner manner;
    bool isPulmonic;

    // Vowel members
    Height height;
    Part part;
    bool isRounded;
    bool isTense;
public:
    // Consonant Constructor
    SoundSymbol(std::string symbol, bool isVoiced, Place place, Manner manner, bool isPulmonic) {
        type = CONSONANT;
        this->symbol = symbol;
        this->isVoiced = isVoiced;
        this->place = place;
        this->manner = manner;
        this-> isPulmonic = isPulmonic;
    }

    // Vowel Constructor
    SoundSymbol(std::string symbol, bool isVoiced, Height height, Part part, bool isRounded, bool isTense) {
        type = VOWEL;
        this->symbol = symbol;
        this->isVoiced = isVoiced;
        this->height = height;
        this->part = part;
        this->isRounded = isRounded;
        this->isTense = isTense;
    }

    SoundSymbol(){}

    Type getType() { return type; }
    std::string getSymbol() { return symbol; }
    bool isSymVoiced() { return isVoiced; }
    bool isSymPulmonic() { return isPulmonic; }
    bool isSymRounded() { return isRounded; }
    bool isSymTense() { return isTense; }
    Place getPlace() { return place; }
    Manner getManner() { return manner; }
    Height getHeight() { return height; }
    Part getPart() { return part; }

};

std::map<std::string, SoundSymbol> getSoundSymbols();
void printSymbol(SoundSymbol sym);
#endif
