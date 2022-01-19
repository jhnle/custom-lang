#include "syllable_gen.h"

#include <random>
#include <array>
#include <algorithm>

/*
 * Return a syllable using the phonemes from the passed in
 * soundSystem.
 *
 */
Syllable makeSyllable(SoundSystem& soundSystem,
                      std::array<int, 4>& max,
                      std::array<int, 4>& min) {

    std::map<unsigned int, Consonant> consonants = soundSystem.getConsonants();
    std::map<unsigned int, Vowel> vowels = soundSystem.getVowels();
    std::map<unsigned int, Suprasegmental> suprasegmentals = soundSystem.getSupraSegs();

    std::vector<float> probOnsets = soundSystem.getProbOnsets();
    std::vector<float> probNuclei = soundSystem.getProbNuclei();
    std::vector<float> probCodas = soundSystem.getProbCodas();
    std::vector<float> probSupras = soundSystem.getProbSupras();

    std::vector<unsigned int> onsetIds = soundSystem.getOnsetIds();
    std::vector<unsigned int> nucleusIds = soundSystem.getNucleusIds();
    std::vector<unsigned int> codaIds = soundSystem.getCodaIds();
    std::vector<unsigned int> supraIds = soundSystem.getSupraIds();

    std::vector<Consonant> onset, coda;
    std::vector<Vowel> nucleus;
    std::vector<Suprasegmental> suprasegs;

    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::discrete_distribution<> disOnset(probOnsets.begin(), probOnsets.end());
    std::discrete_distribution<> disNucleus(probNuclei.begin(), probNuclei.end());
    std::discrete_distribution<> disCoda(probCodas.begin(), probCodas.end());
    std::discrete_distribution<> disSupra(probSupras.begin(), probSupras.end());

    std::array<int, 4> sylType = genSyllableType(max, min);

    // Push to onset
    for (int i = 0; i < sylType[0]; i++) {

        /*
         * Keep picking until the current consonant
         * does not exist in the onset; prevent duplicates.
         *
         * NOTE sylType[0] > consonants.size() will cause an
         * infinite loop. This should be prevented in the future
         * through the ruleSystem.
         */
        Consonant consonant = consonants[onsetIds[disOnset(gen)]];
        while (!onset.empty() &&
               std::find(begin(onset), end(onset), consonant) != std::end(onset)) {

            consonant = consonants[onsetIds[disOnset(gen)]];
        }

        onset.push_back(consonant);
    }

    // Push to nucleus
    for (int i = 0; i < sylType[1]; i++) {

        Vowel vowel = vowels[nucleusIds[disNucleus(gen)]];
        while (!nucleus.empty() &&
            std::find(begin(nucleus), end(nucleus), vowel) != std::end(nucleus)) {

            vowel = vowels[nucleusIds[disNucleus(gen)]];
        }

        nucleus.push_back(vowel);
    }

    // Push to coda
    for (int i = 0; i < sylType[2]; i++) {

        Consonant consonant = consonants[codaIds[disCoda(gen)]];
        while (!coda.empty() &&
               std::find(begin(coda), end(coda), consonant) != std::end(coda)) {

            consonant = consonants[codaIds[disCoda(gen)]];
        }
        coda.push_back(consonant);
    }

    // Push to suprasegmental
    for (int i = 0; i < sylType[3]; i++) {

        Suprasegmental supra = suprasegmentals[supraIds[disSupra(gen)]];
        while(!suprasegs.empty() &&
              std::find(begin(suprasegs), end(suprasegs), supra) != std::end(suprasegs)) {

            supra = suprasegmentals[supraIds[disSupra(gen)]];
        }
        suprasegs.push_back(suprasegmentals[supraIds[disSupra(gen)]]);
    }

    return Syllable(onset, nucleus, coda, suprasegs);
}

/*
 * Generates a syllable type (such as CVC, CV, etc)
 * based on the minimum and maximum
 * amount of phonemes per syllable part (onset, nucleus, etc)
 * allowed in the language, where each type is equally as likely.
 *
 * The output syllable is represented by the array "result", where index
 * 0 = onset, 1 = nucleus, 2 = coda, and 3 = suprasegmental.
 * The value at the index represents the amount of phonemes or
 * suprasegmentals at the corresponding part.
 *
 * So for instance, if result = {2, 1, 0, 0}, result represents
 * a CCV syllable.
 *
 */
std::array<int, 4> genSyllableType(std::array<int, 4>& max, std::array<int, 4>& min) {
    std::array<int, 4> result = {0};

    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    std::uniform_int_distribution<> disOnset(min[0], max[0]);
    std::uniform_int_distribution<> disNucleus(min[1], max[1]);
    std::uniform_int_distribution<> disCoda(min[2], max[2]);
    std::uniform_int_distribution<> disSupra(min[3], max[3]);

    result[0] = disOnset(gen);
    result[1] = disNucleus(gen);
    result[2] = disCoda(gen);
    result[3] = disSupra(gen);

    return result;
}
