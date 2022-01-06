#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

#include "consonant.h"
#include "vowel.h"
#include "suprasegmental.h"

#define MAX_PHONEME_LENGTH 10

/* Represents all possible phonemes in a language */
class SoundSystem {
private:
    std::string name;
    std::map<unsigned int, Consonant> consonants;
    std::map<unsigned int, Vowel> vowels;
    std::map<unsigned int, Suprasegmental> suprasegmentals;
    std::map<std::string, unsigned int> ids;
    std::vector<float> probOnsets, probNuclei, probCodas, probSupras;
    std::vector<unsigned int> onsetIds, nucleusIds, codaIds, supraIds;
    bool isValidSym(std::string) const;
public:
    SoundSystem(std::string name) {
        this->name = name;
    }

    bool save();
    bool load();

    std::map<unsigned int, Consonant> getConsonants() const { return consonants; }
    std::map<unsigned int, Vowel> getVowels() const { return vowels; }
    std::map<unsigned int, Suprasegmental> getSupraSegs() const { return suprasegmentals; }
    std::map<std::string, unsigned int> getIds() const { return ids; }

    std::vector<float> getProbOnsets() const { return probOnsets; }
    std::vector<float> getProbNuclei() const { return probNuclei; }
    std::vector<float> getProbCodas() const { return probCodas; }
    std::vector<float> getProbSupras() const { return probSupras; }

    std::vector<unsigned int> getOnsetIds() const { return onsetIds; }
    std::vector<unsigned int> getNucleusIds() const { return nucleusIds; }
    std::vector<unsigned int> getCodaIds() const { return codaIds; }
    std::vector<unsigned int> getSupraIds() const { return supraIds; }
};

#endif
