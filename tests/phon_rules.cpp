#include "../ipa/soundsystem.h"
#include "../ipa/consonant.h"
#include "../ipa/vowel.h"

static std::string getRepresentation(std::map<unsigned int, Consonant>&,
                                     std::map<unsigned int, Vowel>&,
                                     std::vector<unsigned int>&);

static std::vector<unsigned int> ruleVoicing(std::map<std::string, unsigned int>&,
                                             std::map<unsigned int, Consonant>&,
                                             std::vector<unsigned int>&);

static std::vector<unsigned int> rulePlosive(std::map<unsigned int, Consonant>&,
                                             std::vector<unsigned int>&);

int main() {
    SoundSystem soundSystem("phon_rules");
    soundSystem.load();

    std::map<unsigned int, Consonant> consonants = soundSystem.getConsonants();
    std::map<unsigned int, Vowel> vowels = soundSystem.getVowels();
    std::map<std::string, unsigned int> ids = soundSystem.getIds();

    /* Use ids map to retrieve phoneme given a symbol,
     * ids may change in the future
     */
    std::vector<unsigned int> word1 = {
        ids["s"],
        ids["k"],
        ids["æ"],
        ids["d"],
        ids["s"]
    };

    std::vector<unsigned int> word2 = {
        ids["t"],
        ids["æ"],
        ids["t"],
        ids["s"],
        ids["ə"],
        ids["s"]
    };

    std::vector<unsigned int> word3 = {
        ids["s"],
        ids["o"],
        ids["ʊ"],
        ids["g"],
        ids["s"],
        ids["d"],
        ids["i"]
    };

    std::vector<unsigned int> word4 = {
        ids["ŋ"],
        ids["ɑ"],
        ids["m"],
        ids["n"],
        ids["ə"],
        ids["l"]
    };

    std::vector<unsigned int> word5 = {
        ids["θ"],
        ids["o"],
        ids["ʊ"],
        ids["b"],
        ids["n"],
        ids["ɑ"]
    };

    // Apply voicing rule
    std::vector<unsigned int> rep1 = ruleVoicing(ids, consonants, word1); // skædz
    std::vector<unsigned int> rep2 = ruleVoicing(ids, consonants, word2); // tætsəs
    std::vector<unsigned int> rep3 = ruleVoicing(ids, consonants, word3); // soʊgzdi

    // Apply plosive rule
    std::vector<unsigned int> rep4 = rulePlosive(consonants, word4); // gɑmdəl
    std::vector<unsigned int> rep5 = rulePlosive(consonants, word5); // θoʊbdɑ

    std::cout << "/s/ --> [z] / C_\n"
              << "/" << getRepresentation(consonants, vowels, word1) << "/ --> ["
              << getRepresentation(consonants, vowels, rep1)  << "]\n"
              << "/" << getRepresentation(consonants, vowels, word2) << "/ --> ["
              << getRepresentation(consonants, vowels, rep2)  << "]\n"
              << "/" << getRepresentation(consonants, vowels, word3) << "/ --> ["
              << getRepresentation(consonants, vowels, rep3)  << "]\n";

    std::cout << "\n/nasal/ --> [plosive] / _V\n"
              << "/" << getRepresentation(consonants, vowels, word4) << "/ --> ["
              << getRepresentation(consonants, vowels, rep4)  << "]\n"
              << "/" << getRepresentation(consonants, vowels, word5) << "/ --> ["
              << getRepresentation(consonants, vowels, rep5)  << "]\n";

    return 0;
}

/*
 * Given a vector of phonemes, print out their symbols
 */
static std::string getRepresentation(std::map<unsigned int, Consonant>& consonants,
                                     std::map<unsigned int, Vowel>& vowels,
                                     std::vector<unsigned int>& word) {

    std::string output = "";

    for(const auto& phoneme: word) {

        // Calculate if phoneme is consonant or vowel
        if(phoneme % 0x10 == 1) {
            output += consonants[phoneme].getSymbol();
        } else {
            output += vowels[phoneme].getSymbol();
        }
    }

    return output;
}

/* Voiceless alveolar fricative becom es voiced if it occurs after a voiced consonant
 * /s/ --> [z] / C_
 */
static std::vector<unsigned int> ruleVoicing(std::map<std::string, unsigned int>& ids,
                                             std::map<unsigned int, Consonant>& consonants,
                                             std::vector<unsigned int>& word) {
    std::vector<unsigned int> output;
    int len = word.size();

    for(int i = 0; i < len; i ++) {
        unsigned int curId = word[i];

        /* Check if there is a phoneme before current position,
         * if current phoneme is a voiceless alveolar fricative,
         * and if the preceeding symbol is a voiced consonant,
         */
        if (i - 1 > 0 && consonants[curId].getSymbol() == "s"
            && word[i - 1] % 0x10 == 0x1
            && word[i - 1] % 0x10000 / 0x1000 == 0x4) {

            // Add voicing
            curId += 0x3000;
        }
        output.push_back(curId);
    }

    return output;
}

/* Nasal becomes plosive if it occurs before a vowel
 * /nasal/ --> [plosive] / _V
 */
static std::vector<unsigned int> rulePlosive(std::map<unsigned int, Consonant>& consonants,
                                             std::vector<unsigned int>& word) {
    std::vector<unsigned int> output;
    int len = word.size();

    for(int i = 0; i < len; i ++) {
        unsigned int curID = word[i];

        /* Check if there is a phoneme after current position,
         * if current phoneme is nasal consonant,
         * and if the proceeding symbol is a vowel
         */
        if (i + 1 < len
            && curID % 0x10 == 0x1
            && curID % 0x1000 / 0x100 == NASAL
            && word[i + 1] % 0x10 == 0x2) {

            // Turn plosive
            unsigned int tempID = curID + ((PLOSIVE - NASAL) * 0x100);

            // Change id only if corresponding plosive exists
            if (consonants.find(curID) != consonants.end()) {
                curID = tempID;
            }
        }
        output.push_back(curID);
    }

    return output;
}
