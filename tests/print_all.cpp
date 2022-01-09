#include <iostream>
#include <iomanip>

#include "../ling/units/soundsystem.h"

int main() {

    SoundSystem soundSystem("preset01");
    soundSystem.load();

    std::map<unsigned int, Consonant> consonants = soundSystem.getConsonants();
    std::map<unsigned int, Vowel> vowels = soundSystem.getVowels();
    std::map<unsigned int, Suprasegmental> suprasegmentals = soundSystem.getSupraSegs();

    std::cout << "Consonants: " << consonants.size() << "\n----\n";
    for (auto const& sym: consonants) {
        std::cout << "ID: 0x" << std::setfill('0') << std::setw(8) << std::hex << sym.first
                  << " [" << sym.second.getSymbol() << "] " << sym.second.getDesc() << "\n";
    }

    std::cout << "\nVowels: " << std::dec << vowels.size() << "\n----\n";
    for (auto const& sym: vowels) {
        std::cout << "ID: 0x" << std::setfill('0') << std::setw(8) << std::hex << sym.first
                  << " [" << sym.second.getSymbol() << "] " << sym.second.getDesc() << "\n";
    }

    // Having suprasegmentals is optional
    if (!suprasegmentals.empty()) {
        std::cout << "\nSuprasegmentals: " << std::dec << suprasegmentals.size() << "\n----\n";
        for (auto const& sym: suprasegmentals) {
            std::cout << "ID: 0x" << std::setfill('0') << std::setw(3) << std::hex << sym.first
                      << " " << sym.second.getSymbol() << " " << sym.second.getDesc() << "\n";
        }
    }

    // Saving will delete any invalid phonemes from the file
    soundSystem.save();
    return 0;
}
