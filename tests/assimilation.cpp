#include <iostream>

#include "../ling/units/soundsystem.h"
#include "../ling/word/root_morph.h"

static RootMorph ruleVoicing(std::map<unsigned int,
                             Consonant>&, RootMorph&);

static std::vector<Consonant> applyVRule(std::vector<Consonant>&,
                                         std::map<unsigned int, Consonant>&);

static RootMorph rulePlosive(std::map<unsigned int, Consonant>&,
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
                consonants[ids["s"]],
                consonants[ids["k"]]
            },
            std::vector<Vowel> {
                vowels[ids["æ"]],
            },
            std::vector<Consonant> {
                consonants[ids["d"]],
                consonants[ids["s"]]
            },
            std::vector<Suprasegmental>()
        )
    };
    
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

    // Apply voicing rule
    RootMorph rep1 = ruleVoicing(consonants, morpheme1); // ?mb?li



    std::cout << "/n/ --> [m] / C_\n"
              << "/" << morpheme1.getPhonemic() << "/ --> ["
              << rep1.getPhonemic()  << "]\n"

    return 0;
}


/* Nasal becomes plosive if it occurs before a vowel
 * /nasal/ --> [plosive] / _V
 *
 * Here, only onsets can occur before a vowel, so ignore coda and nucleus
 */
static RootMorph rulePlosive(std::map<unsigned int, Consonant>& consonants,
                            RootMorph& input) {

    RootMorph output;
    int numSyl = input.getNumSyl();

    // Loop for each syllable
    for(int i = 0; i < numSyl - 1; i++) {
        std::vector<Consonant> onset = input.getSyllables()[i + 1].getOnset();
        std::vector<Consonant> coda = input.getSyllables()[i].getCoda();

        //Check if final consonant in onset is a nasal
        if (coda.back().getPlace() == Place::alveolar && coda.back().getManner() == Manner::plosive && onset.front().getPlace::bilabial) {

            // Turn plosive
            unsigned int id = coda.back().getId() + ((static_cast<int>(Place::bilabial
                                                   - static_cast<int>(Manner::alveolar)) * 0x010);

            // Change id only if corresponding plosive exists
            if (consonants.find(id) != consonants.end()) {
                coda.back() = consonants[id];
            }
        }

        output.addSyllable(Syllable(onset, input.getSyllables()[i].getNucleus(),
                                    coda, std::vector<Suprasegmental>()));
    }
    return output;
}
