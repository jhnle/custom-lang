#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "../ipa/ipa.h"

static std::vector<SoundUnit> ruleVoicing(SoundSystem * const,
                                          std::vector<SoundUnit> * const);

static std::string getRepresentation(std::vector<SoundUnit> * const);

int main() {
    SoundSystem soundSystem{};
    std::map<std::string, Consonant> consonants = soundSystem.getConsonants();
    std::map<std::string, Vowel> vowels = soundSystem.getVowels();

    std::vector<SoundUnit> word1 = {
        consonants["s"],
        consonants["k"],
        vowels["æ"],
        consonants["d"],
        consonants["s"]
    };

    std::vector<SoundUnit> word2 = {
        consonants["t"],
        vowels["æ"],
        consonants["t"],
        consonants["s"],
        vowels["ə"],
        consonants["s"]
    };

    std::vector<SoundUnit> word3 = {
        consonants["s"],
        vowels["o"],
        vowels["ʊ"],
        consonants["g"],
        consonants["s"],
        consonants["d"],
        vowels["i"]
    };

    // Phonetic Representation
    std::vector<SoundUnit> rep1 = ruleVoicing(&soundSystem, &word1); //skædz
    std::vector<SoundUnit> rep2 = ruleVoicing(&soundSystem, &word2); //tætsəs
    std::vector<SoundUnit> rep3 = ruleVoicing(&soundSystem, &word3); //soʊgzdi

    std::cout << "/" << getRepresentation(&word1) << "/ --> ["
              << getRepresentation(&rep1)  << "]" << std::endl
              << "/" << getRepresentation(&word2) << "/ --> ["
              << getRepresentation(&rep2)  << "]" << std::endl
              << "/" << getRepresentation(&word3) << "/ --> ["
              << getRepresentation(&rep3)  << "]" << std::endl;

    return 0;
}

/* Given a vector of sound symbols, return its
 * string representation
 */
static std::string getRepresentation(std::vector<SoundUnit> * const input) {
    std::string output = "";
    int len = (*input).size();

    for (int i = 0; i < len; i++) {
        output += (*input)[i].getSymbol();
    }
    return output;
}

/* Voiceless alveolar fricative becomes voiced if it occurs after a voiced consonant
 * /s/ --> [z] / C_
 */
static std::vector<SoundUnit> ruleVoicing(SoundSystem * const soundSymbols,
                                          std::vector<SoundUnit> * const input) {
    std::vector<SoundUnit> output;
    int len = (*input).size();

    for (int i = 0; i < len; i++) {
        // Check if current symbol is a voiceless alveolar fricative,
        // if there is a symbol before it,
        // if the preceeding symbol is a consonant,
        // and if the preceeding symbol is voiced
        if ((*input)[i].getSymbol() == "s" && (i - 1) >= 0
            && (*input)[i - 1].getType() == CONSONANT
            && (*input)[i - 1].isSymVoiced() == true) {

            output.push_back(soundSymbols->getConsonants()["z"]);
        } else {
            output.push_back((*input)[i]);
        }
    }
    return output;
}
