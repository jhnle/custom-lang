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

/* Save all phonemes into a csv for the corresponding language
 *
 * Return true if file couldnt be opened, consonants is empty, or vowels is empty
 * Return false otherwise
 */
bool SoundSystem::save() {
    std::ofstream phonemes("langs/" + name + "/phonemes.csv");

    if (!phonemes.is_open()) {
        return true;
    }

    if (consonants.size() == 0 || vowels.size() == 0) {
        std::cerr << "Cannot save " << name << " phonemes, consonants and/or vowels is empty.\n";
        return true;
    }

    // Save consonants
    for (auto const& phon: consonants) {
        phonemes << phon.second.getSymbol() << ","
                 << std::hex << phon.second.getId() << ","
                 << std::dec << phon.second.getProbOnset() << ","
                 << phon.second.getProbNucleus() << ","
                 << phon.second.getProbCoda() << ",0\n";
    }

    // Save vowels
    for (auto const& phon: vowels) {
        phonemes << phon.second.getSymbol() << ","
                 << std::hex << phon.second.getId() << ",0,"
                 << std::dec << phon.second.getProbNucleus() << ",0,0\n";
    }

    // Save suprasegmentals
    for (auto const& seg: suprasegmentals) {
        phonemes << seg.second.getSymbol() << ","
                 << std::hex << seg.second.getId() << ",0,0,0"
                 << std::dec << seg.second.getProbSupra() << "\n";
    }

    phonemes.close();
    return false;
}

/* Load phonemes from a csv from the corresponding language
 *
 * Return true if file couldnt be opened
 * Return false otherwise
 */
bool SoundSystem::load() {
    std::ifstream phonemes("langs/" + name + "/phonemes.csv");

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
        if (tokens.size() != 6) {
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
            std::cerr << "Failed to convert '" << tokens[1] << "' into an integer id\n";
            continue; // Skip to next line
        }

        // Try to convert probabilities from string to float
        float probOnset, probNucleus, probCoda, probSupra;
        try {
            probOnset = std::stof(tokens[2], nullptr);
            probNucleus = std::stof(tokens[3], nullptr);
            probCoda = std::stof(tokens[4], nullptr);
            probSupra = std::stof(tokens[5], nullptr);
        } catch (...) {
            std::cerr << "Failed to convert probabilities for " + tokens[0] + "into floats\n";
            continue; // Skip to next line
        }

        // Insert based on type
        if (id % 0x10 == static_cast<int>(Type::consonant)) {
            // Get fields from id
            Place place = (Place)(id % 0x100 / 0x10);
            Manner manner = (Manner)(id % 0x1000 / 0x100);
            Voicing voicing = (Voicing)(id % 0x10000 / 0x1000);
            Coarticulation coarticulation = (Coarticulation)(id % 0x100000 / 0x10000);
            Articulation articulation = (Articulation)(id % 0x1000000 / 0x100000);
            Release release = (Release)(id % 0x10000000 / 0x1000000);
            unsigned int isSyllabic = (id % 0x100000000 / 0x10000000);

            // Insert only if id is valid
            if (voicing < Voicing::voiceless || voicing > Voicing::voiced
                || place < Place::bilabial || place > Place::glottal
                || manner < Manner::plosive || manner > Manner::latClick
                || articulation > Articulation::lowered
                || coarticulation > Coarticulation::nasalized
                || release > Release::noAudRel
                || isSyllabic < 0   || isSyllabic > 1) {

                std::cerr << "Could not add the consonant [" << tokens[0] << "] with id " << std::hex << id << "\n";
            } else {
                // Insert Consonant
                Consonant consonant(tokens[0], probOnset, probNucleus, probCoda,
                                    place, manner, voicing, coarticulation, articulation, release, (bool)isSyllabic);

                probOnsets.push_back(probOnset);
                probCodas.push_back(probCoda);

                onsetIds.push_back(id);
                codaIds.push_back(id);

                consonants.insert(std::pair<unsigned int, Consonant>(id, consonant));
                ids.insert(std::pair<std::string, unsigned int>(tokens[0], id));
            }
        } else if (id % 0x10 == static_cast<int>(Type::vowel)) {
            // Get fields from id
            Height height = (Height)(id % 0x100 / 0x10);
            Backness back = (Backness)(id % 0x1000 / 0x100);
            Voicing voicing = (Voicing)(id % 0x10000 / 0x1000);
            Rounding rounding = (Rounding)(id % 0x100000 / 0x10000);
            Coarticulation coarticulation = (Coarticulation)(id % 0x1000000 / 0x100000);
            TongueRoot root = (TongueRoot)(id % 0x10000000 / 0x1000000);

            // Insert only if id is valid
            if (voicing < Voicing::voiceless || voicing > Voicing::voiced
                || height < Height::close || height > Height::open
                || back < Backness::front || back > Backness::back
                || rounding < Rounding::unrounded || rounding > Rounding::moreRounded
                || coarticulation > Coarticulation::nasalized
                || root > TongueRoot::advanced) {

                std::cerr << "Could not add the vowel [" << tokens[0] << "] with id " << std::hex << id << "\n";
            } else {
                // Insert vowel
                Vowel vowel(tokens[0], probNucleus, height, back, voicing, rounding, coarticulation, root);

                probNuclei.push_back(probNucleus);
                nucleusIds.push_back(id);

                vowels.insert(std::pair<unsigned int, Vowel>(id, vowel));
                ids.insert(std::pair<std::string, unsigned int>(tokens[0], id));
            }
        } else if (id % 0x10 == 0) {
            // Get fields from id
            SupraType supraType = (SupraType)(id % 0x1000 / 0x10);
            Feature feature = Feature::intonation;

            // Get feature from suprasegmental range
            switch (static_cast<int>(supraType)) {
                case 0:
                    feature = Feature::tone;
                case 6:
                    break;
                case 7:
                    feature = Feature::length;
                case 10:
                    break;
                case 11:
                    feature = Feature::stress;
                case 12:
                    break;
            }

            if (supraType < SupraType::extraLow
                || supraType > SupraType::globalRise) {

                std::cerr << "Could not add the suprasegmental " << tokens[0] << " with id " << std::hex << id << "\n";
            } else {
                // Insert suprasegmental
                Suprasegmental supraseg(tokens[0], probSupra, feature, supraType);

                probSupras.push_back(probSupra);
                supraIds.push_back(id);

                suprasegmentals.insert(std::pair<unsigned int, Suprasegmental>(id, supraseg));
                ids.insert(std::pair<std::string, unsigned int>(tokens[0], id));
            }
        } else {
            // ID does not denote a valid type, skip to next line
            std::cerr << std::hex << id % 0x10 << " is not a valid type.\n";
        }
    }
    phonemes.close();

    return false;
}
