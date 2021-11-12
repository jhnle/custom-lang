#ifndef PHONEME_H
#define PHONEME_H

#include <string>

#include "ipa.h"

/* Represents a discrete unit of sound */
class Phoneme {
protected:
    Type type;
    std::string symbol;
    std::string desc;
    bool isVoiced;
public:
    Type getType() const { return type; }
    std::string getSymbol() const { return symbol; }
    std::string getDesc() const { return desc; }
    bool isSymVoiced() const { return isVoiced; }

    std::string getStrVoiced (bool) const;
};

#endif
