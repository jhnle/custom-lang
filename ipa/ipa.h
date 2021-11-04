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
    std::string name;
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
    SoundSymbol(std::string symbol, bool isVoiced, Place place,
                Manner manner, bool isPulmonic) {

        type = CONSONANT;
        this->symbol = symbol;
        this->isVoiced = isVoiced;
        this->place = place;
        this->manner = manner;
        this-> isPulmonic = isPulmonic;

        name += getStrVoiced(isVoiced) + " " + getStrPlace(place)
                + " " + getStrManner(manner);
    }

    // Vowel Constructor
    SoundSymbol(std::string symbol, bool isVoiced, Height height,
                Part part, bool isRounded, bool isTense) {

        type = VOWEL;
        this->symbol = symbol;
        this->isVoiced = isVoiced;
        this->height = height;
        this->part = part;
        this->isRounded = isRounded;
        this->isTense = isTense;

        name += ((!isVoiced) ? getStrVoiced(isVoiced) + " " : "") + getStrHeight(height) + " "
                + getStrPart(part) + " " + getStrRounded(isRounded) + " "
                + getStrTense(isTense) + " Vowel";
    }

    SoundSymbol(){}

    Type getType() const { return type; }
    std::string getSymbol() const { return symbol; }
    std::string getName() const { return name; }
    bool isSymVoiced() const { return isVoiced; }
    bool isSymPulmonic() const { return isPulmonic; }
    bool isSymRounded() const { return isRounded; }
    bool isSymTense() const { return isTense; }
    Place getPlace() const { return place; }
    Manner getManner() const { return manner; }
    Height getHeight() const { return height; }
    Part getPart() const { return part; }

    std::string getStrVoiced (bool);
    std::string getStrPlace (Place);
    std::string getStrManner (Manner);
    std::string getStrHeight (Height);
    std::string getStrPart (Part);
    std::string getStrRounded (bool);
    std::string getStrTense (bool);
};

std::map<std::string, SoundSymbol> getSoundSymbols();
void printSymbol(SoundSymbol);

#endif
