#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "../ipa/ipa.h"

int main() {
    std::map<std::string, SoundSymbol> soundSymbols;
    soundSymbols = getSoundSymbols();

    std::vector<std::string> consonants;
    std::vector<std::string> vowels;

    /* Iterate through all terms of soundSymbols and place the
     * current soundSymbol in the appropriate vector
     */
    for (auto const& sym : soundSymbols) {
        if (sym.second.getType() == CONSONANT)
            consonants.push_back("[" + sym.first + "] " + sym.second.getName());
        else
            vowels.push_back("[" + sym.first + "] " + sym.second.getName());
    }

    // Print all consonants
    std::cout << "Consonants\n----\n";
    for (auto const& sym: consonants) {
        std::cout << sym << std::endl;
    }

    // Print all vowels
    std::cout << "\nVowels\n----\n";
    for (auto const& sym: vowels) {
        std::cout << sym << std::endl;
    }

    return 0;
}
