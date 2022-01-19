#include <iostream>

#include "../ling/units/soundsystem.h"
#include "../ling/word/root_morph.h"

static RootMorph assimilation(std::map<unsigned int, Consonant>&,
                             RootMorph&);

int main() {
    SoundSystem soundSystem("preset00");
    soundSystem.load();

    std::map<unsigned int, Consonant> consonants = soundSystem.getConsonants();
    std::map<unsigned int, Vowel> vowels = soundSystem.getVowels();
    std::map<std::string, unsigned int> ids = soundSystem.getIds();

    
    std::vector<Syllable> syl1 {
        Syllable(
            std::vector<Consonant> {
                consonants[ids["?"]],
                consonants[ids["n"]]
            }
        ),
        Syllable(    
            std::vector<Consonant>{
                consonants[ids["b"]]
            },
            std::vector<Vowel> {
                vowels[ids["?"]],
            }
            std::vector<Consonant>{
                consonants[ids["l"]],
                consonants[ids["i"]]
            }
        )
    };

    RootMorph morpheme1 (syl1, ConLexCat::noun, true); // ?nb?li
    RootMorph rep1 = assimilate(consonants, morpheme1); // ?mb?li



    std::cout << "/n/ --> [m] / C_\n"
              << "/" << morpheme1.getPhonemic() << "/ --> ["
              << rep1.getPhonemic()  << "]\n"

    return 0;
}


/* /t/(alveolar plosive) -> [p] (bilabial plosive) before /m/, /b/, /p/ (bilabial)
 * using examples from http://phonetics-cediel.blogspot.com/2011/08/assimilation-in-english.html,
 * consonant before consonant is changed, so only coda changed
 */
static RootMorph assimilate(std::map<unsigned int, Consonant>& consonants,
                            RootMorph& input) {

    RootMorph output;
    int numSyl = input.getNumSyl();

    // Loop for each syllable
    for(int i = 0; i < numSyl - 1; i++) {
        std::vector<Consonant> onset = input.getSyllables()[i + 1].getOnset();
        std::vector<Consonant> coda = input.getSyllables()[i].getCoda();

        //Check if final consonant in onset is a nasal
        if (coda.back().getPlace() == Place::alveolar && coda.back().getManner() == Manner::plosive && onset.front().getPlace::bilabial) {

            // Set bilabial
            unsigned int id = coda.back().getId() + ((static_cast<int>(Place::bilabial
                                                   - static_cast<int>(Manner::alveolar)) * 0x010);

            if (consonants.find(id) != consonants.end()) {
                coda.back() = consonants[id];
            }
        }

        output.addSyllable(Syllable(onset, input.getSyllables()[i].getNucleus(),
                                    coda));
    }
    return output;
}
