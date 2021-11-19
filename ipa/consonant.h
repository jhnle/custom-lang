#ifndef CONSONANT_H
#define CONSONANT_H

#include "phoneme.h"

class Consonant : public Phoneme {
private:
    Place place;
    Manner manner;
    bool isPulmonic;

    std::string getStrPlace (Place) const;
    std::string getStrManner (Manner) const;
public:
    Consonant(std::string symbol, bool isVoiced, Place place, Manner manner, Diacritic diacritic, bool isPulmonic) {
        type = CONSONANT;
        this->diacritic = diacritic;
        this->symbol = symbol;
        this->isVoiced = isVoiced;
        this->place = place;
        this->manner = manner;
        this->isPulmonic = isPulmonic;

        id = (diacritic * 0x10000) + (manner * 0x1000) + (place * 0x100) + (isVoiced * 0x10) + (CONSONANT + 1);

        desc += ((isPulmonic) ? getStrVoiced(isVoiced) + " " : "") + getStrPlace(place)
                + " " + getStrManner(manner);
    }

    Consonant() {}

    Place getPlace() const { return place; }
    Manner getManner() const { return manner; }
    bool isSymPulmonic() const { return isPulmonic; }
};

#endif
