#include "syllable_gen.h"

#include <random>

Syllable makeSyllable(SoundSystem soundSystem) {
    std::map<unsigned int, Consonant> consonants = soundSystem.getConsonants();
    std::map<unsigned int, Vowel> vowels = soundSystem.getVowels();

    std::vector<float> probOnsets = soundSystem.getProbOnsets();
    std::vector<float> probNuclei = soundSystem.getProbNuclei();
    std::vector<float> probCodas = soundSystem.getProbCodas();

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


    onset.push_back(consonants[onsetIds[disOnset(gen)]]);
    nucleus.push_back(vowels[nucleusIds[disNucleus(gen)]]);
    coda.push_back(consonants[codaIds[disCoda(gen)]]);

    return Syllable(onset, nucleus, coda, suprasegs);
}
