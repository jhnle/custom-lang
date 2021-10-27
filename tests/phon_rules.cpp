#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "../ipa/ipa.h"

static std::vector<SoundSymbol> ruleVoicing(
    std::map<std::string, SoundSymbol> * const soundSymbols,
    std::vector<SoundSymbol> * const input);

static std::string getRepresentation(std::vector<SoundSymbol> * const input);

int main() {
    std::map<std::string, SoundSymbol> soundSymbols;
    soundSymbols = getSoundSymbols();

    std::vector<SoundSymbol> word1 = {
        soundSymbols["s"],
        soundSymbols["k"],
        soundSymbols["æ"],
        soundSymbols["d"],
        soundSymbols["s"]
    };

    std::vector<SoundSymbol> word2 = {
        soundSymbols["t"],
        soundSymbols["æ"],
        soundSymbols["t"],
        soundSymbols["s"],
        soundSymbols["ʌ"],
        soundSymbols["s"]
    };

    std::vector<SoundSymbol> word3 = {
        soundSymbols["s"],
        soundSymbols["o"],
        soundSymbols["ʊ"],
        soundSymbols["g"],
        soundSymbols["s"],
        soundSymbols["d"],
        soundSymbols["i"]
    };

    // Phonetic Representation
    std::vector<SoundSymbol> rep1 = ruleVoicing(&soundSymbols, &word1); //skædz
    std::vector<SoundSymbol> rep2 = ruleVoicing(&soundSymbols, &word2); //tætsʌs
    std::vector<SoundSymbol> rep3 = ruleVoicing(&soundSymbols, &word3); //soʊgzdi

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
static std::string getRepresentation(std::vector<SoundSymbol> * const input) {
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
static std::vector<SoundSymbol> ruleVoicing(
    std::map<std::string, SoundSymbol> * const soundSymbols,
    std::vector<SoundSymbol> * const input) {

    std::vector<SoundSymbol> output;
    int len = (*input).size();

    for (int i = 0; i < len; i++) {
        // Check if current symbol is a voiceless alveolar fricative,
        // if there is a symbol before it,
        // if the preceeding symbol is a consonant,
        // and if the preceeding symbol is voiced
        if ((*input)[i].getSymbol() == "s" && (i - 1) >= 0
            && (*input)[i - 1].getType() == CONSONANT
            && (*input)[i - 1].isSymVoiced() == true) {

            output.push_back((*soundSymbols)["z"]);
        } else {
            output.push_back((*input)[i]);
        }
    }
    return output;
}
