#include "../ling/units/soundsystem.h"
#include "../ling/word/syllable_gen.h"

int main() {
    SoundSystem soundSystem("preset01");
    soundSystem.load();

    std::map<unsigned int, Consonant> consonants = soundSystem.getConsonants();
    std::map<unsigned int, Vowel> vowels = soundSystem.getVowels();

    for (int i = 1; i <= 100; i++) {
        std::cout << makeSyllable(soundSystem).getStrSyl() << " ";

        if (i % 10 == 0)
            std::cout << "\n";
    }

    return 0;
}
