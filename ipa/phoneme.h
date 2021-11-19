#ifndef PHONEME_H
#define PHONEME_H

#include <string>

#include "ipa.h"

/* Represents a discrete unit of sound */
class Phoneme {
protected:
    Type type;
    Diacritic diacritic;
    unsigned int id;
    std::string symbol;
    std::string desc;
    bool isVoiced;
public:
    Type getType() const { return type; }
    Diacritic getDiacritic() const { return diacritic; }
    unsigned int getId() const { return id; }
    std::string getSymbol() const { return symbol; }
    std::string getDesc() const { return desc; }
    bool isSymVoiced() const { return isVoiced; }

    std::string getStrVoiced (bool) const;
};

#endif
