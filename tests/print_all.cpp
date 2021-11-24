#include <iomanip>

#include "../ipa/soundsystem.h"
#include "../ipa/consonant.h"
#include "../ipa/vowel.h"

int main() {

    SoundSystem soundSystem("print_all");
    soundSystem.load();

    std::map<unsigned int, Consonant> consonants = soundSystem.getConsonants();
    std::map<unsigned int, Vowel> vowels = soundSystem.getVowels();

    std::cout << "Consonants: " << consonants.size() << "\n----\n";
    for (auto const& sym: consonants) {
        std::cout << "ID: 0x" << std::setfill('0') << std::setw(6) << std::hex << sym.first
                  << " [" << sym.second.getSymbol() << "] " << sym.second.getDesc() << std::endl;
    }

    std::cout << "\nVowels: " << vowels.size() << "\n----\n";
    for (auto const& sym: vowels) {
        std::cout << "ID: 0x" << std::setfill('0') << std::setw(7) << std::hex << sym.first
                  << " [" << sym.second.getSymbol() << "] " << sym.second.getDesc() << std::endl;
    }


    // Saving will delete any invalid phonemes from the file
    soundSystem.save();
    return 0;
}
