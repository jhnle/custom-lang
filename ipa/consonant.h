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
    Consonant(std::string symbol, bool isVoiced, Place place,
                Manner manner, bool isPulmonic) {

        type = CONSONANT;
        this->symbol = symbol;
        this->isVoiced = isVoiced;
        this->place = place;
        this->manner = manner;
        this->isPulmonic = isPulmonic;

        desc += getStrVoiced(isVoiced) + " " + getStrPlace(place)
                + " " + getStrManner(manner);
    }

    Consonant() {}

    Place getPlace() const { return place; }
    Manner getManner() const { return manner; }
    bool isSymPulmonic() const { return isPulmonic; }
};

#endif
