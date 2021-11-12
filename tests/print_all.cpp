#include "../ipa/soundsystem.h"
#include "../ipa/consonant.h"
#include "../ipa/vowel.h"

int main() {

    SoundSystem soundSystem{};
    std::map<std::string, Consonant> consonants = soundSystem.getConsonants();
    std::map<std::string, Vowel> vowels = soundSystem.getVowels();

    std::cout << "Consonants\n----\n";
    for (auto const& sym: consonants) {
        std::cout << "[" << sym.first << "] " << sym.second.getDesc() << std::endl;
    }

    std::cout << "\nVowels\n----\n";
    for (auto const& sym: vowels) {
        std::cout << "[" << sym.first << "] " << sym.second.getDesc() << std::endl;
    }

    return 0;
}
