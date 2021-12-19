#ifndef PHONEME_H
#define PHONEME_H

#include <string>

#include "ipa.h"

/* Represents a discrete unit of sound */
class Phoneme {
protected:
    Type type;
    unsigned int id;
    float freq;
    std::string symbol;
    std::string desc;

    std::string getStrVoicing (Voicing) const;
    std::string getStrCoart (Coarticulation) const;
public:
    Type getType() const { return type; }
    unsigned int getId() const { return id; }
    float getFreq() const { return freq; }
    std::string getSymbol() const { return symbol; }
    std::string getDesc() const { return desc; }
};

#endif
