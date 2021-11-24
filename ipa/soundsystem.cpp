#include "soundsystem.h"

/* A phoneme symbol is valid if its length is between
 * 1 and the MAX_PHONEME_LENGTH (inclusive), is not the empty string
 * and does not contain spaces.
 */
bool SoundSystem::isValidSym(std::string str) const{
    if (str.length() > 0 && str.length() <= MAX_PHONEME_LENGTH
        && str.find(" ") == std::string::npos) {

        return true;
    } else {
        return false;
    }
}

/* Save all phonemes into a csv with the same name
 * as the soundsystem
 *
 * Return true if file couldnt be opened, consonants is empty, or vowels is empty
 * Return false otherwise
 */
bool SoundSystem::save() {
    std::ofstream phonemes("ipa/" + name + ".csv");

    if (!phonemes.is_open()) {
        return true;
    }

    if (consonants.size() == 0 || vowels.size() == 0) {
        std::cerr << "Cannot save " << name << ".csv, consonants and/or vowels is empty.\n";
        return true;
    }

    // Save consonants
    for (auto const& phon: consonants) {
        phonemes << phon.second.getSymbol() << "," << std::hex << phon.second.getId() << "\n";
    }

    // Save vowels
    for (auto const& phon: vowels) {
        phonemes << phon.second.getSymbol() << "," << std::hex << phon.second.getId() << "\n";
    }
    return false;
}

/* Load phonemes from a csv with the same name
 * as the soundsystem
 *
 * Return true if file couldnt be opened
 * Return false otherwise
 */
bool SoundSystem::load() {
    std::ifstream phonemes("ipa/" + name + ".csv");

    if (!phonemes.is_open()) {
        return true;
    }

    // Read each line in file
    std::string line;
    while (getline(phonemes, line)) {
        std::vector<std::string> tokens;
        std::stringstream ss(line);
        std::string token;

        // Tokenize line
        while(getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        // Check if line has correct amount of values
        if (tokens.size() != 2) {
            std::cerr << "Invalid amount of values: " << tokens.size() << "\n";
            continue; // Skip to next line
        }

        // Check if phoneme symbol is valid. If not, do not attempt to insert it.
        if (isValidSym(tokens[0]) == false) {
            std::cerr << "The symbol [" << tokens[0] << "] is invalid\n";
            continue; // Skip to next line
        }

        // Try to convert id from string to unsigned int
        unsigned int id;
        try {
            id = std::stoi(tokens[1], nullptr, 16);
        } catch (...) {
            std::cerr << "Could not convert '" << tokens[1] << "' into an integer id\n";
            continue; // Skip to next line
        }

        // Insert based on type
        if (id % 0x10 == CONSONANT) {
            // Get fields from id
            unsigned int isVoiced = (id % 0x100 / 0x10);                  // _T
            Place place = (Place)(id % 0x1000 / 0x100);                   // _VT
            Manner manner = (Manner)(id % 0x10000 / 0x1000);              // _PVT
            Diacritic diacritic = (Diacritic)(id % 0x1000000 / 0x10000);  // __MPVT

            // Check if id is valid
            if (isVoiced < 0 || isVoiced > 1
                || place < BILABIAL || place > GLOTTAL
                || manner < PLOSIVE || manner > LAT_CLICK
                || diacritic < 0 || diacritic > NO_AUD_REL) {

                std::cerr << "Could not add the consonant [" << tokens[0] << "] with id " << std::hex << id << "\n";
            } else {
                // Insert Consonant
                Consonant consonant(tokens[0], isVoiced, place, manner, diacritic);

                consonants.insert(std::pair<unsigned int, Consonant>(id, consonant));
                ids.insert(std::pair<std::string, unsigned int>(tokens[0], id));
            }
        } else if (id % 0x10 == VOWEL) {
            // Get fields from id
            unsigned int isVoiced = true;
            Height height = (Height)(id % 0x100 / 0x10);                    // _T
            Part part = (Part)(id % 0x1000 / 0x100);                        // _HT
            unsigned int isRounded = (id % 0x10000 / 0x1000);               // _PHT
            unsigned int isTense = (id % 0x100000 / 0x10000);               // _RPHT
            Diacritic diacritic = (Diacritic)(id % 0x10000000 / 0x100000);  // __TRPHT

            // Insert only if id is valid
            if (isVoiced < 0 || isVoiced > 1
                || height > OPEN
                || part > BACK
                || isRounded < 0 || isRounded > 1
                || isTense < 0 || isTense > 1
                || diacritic < 0 || diacritic > NO_AUD_REL) {

                std::cerr << "Could not add the vowel [" << tokens[0] << "] with id " << std::hex << id << "\n";
            } else {
                // Insert vowel
                Vowel vowel(tokens[0], isVoiced, height, part, diacritic, isRounded, isTense);

                vowels.insert(std::pair<unsigned int, Vowel>(id, vowel));
                ids.insert(std::pair<std::string, unsigned int>(tokens[0], id));
            }
        } else {
            std::cerr << std::hex << id % 0x10 << " is not a valid type.\n";
        }
    }
    return false;
}
