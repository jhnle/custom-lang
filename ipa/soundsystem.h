#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

#include "../ipa/consonant.h"
#include "../ipa/vowel.h"

#define MAX_PHONEME_LENGTH 10

/* Represents all possible phonemes or the
 * particular set of phonemes of a language */
class SoundSystem {
private:
    std::string name;
    std::map<unsigned int, Consonant> consonants;
    std::map<unsigned int, Vowel> vowels;
    std::map<std::string, unsigned int> ids;

    int getDiacriticFromStr(std::string) const;
    int getBoolFromStr(std::string) const;
    int getPlaceFromStr(std::string) const;
    int getMannerFromStr(std::string) const;
    int getHeightFromStr(std::string) const;
    int getPartFromStr(std::string) const;
    bool isValidSym(std::string) const;
public:
    //Default constructor creates and inserts all possible phonemes
    SoundSystem() {
        name = "ALL";
        std::ifstream phonemes ("ipa/phonemes.csv");
        if (phonemes.is_open()) {
            std::string line;
            while (getline(phonemes, line)) {
                std::vector<std::string> tokens;
                std::stringstream ss(line);
                std::string token;

                // Tokenize line
                while(getline(ss, token, ',')) {
                    tokens.push_back(token);
                }

                // Check if phoneme symbol is valid. If not, do not attempt to insert it.
                if (isValidSym(tokens[0]) == true) {

                    // Insert phoneme based on type
                    if (tokens[1] == "CONSONANT") {
                        // Convert string tokens to int
                        int isVoiced = getBoolFromStr(tokens[2]);
                        int place = getPlaceFromStr(tokens[3]);
                        int manner = getMannerFromStr(tokens[4]);
                        int isPulmonic = getBoolFromStr(tokens[5]);
                        int diacritic = getDiacriticFromStr(tokens[6]);

                        // Insert consonant only if all fields are valid
                        if (isVoiced != -1 && place != -1 && manner != -1 && isPulmonic != -1) {
                            Consonant consonant(tokens[0], (bool)isVoiced, (Place)place, (Manner)manner, (Diacritic)diacritic, (bool)isPulmonic);

                            consonants.insert(std::pair<unsigned int, Consonant>(consonant.getId(), consonant));
                            ids.insert(std::pair<std::string, unsigned int>(tokens[0], consonant.getId()));
                        } else {
                            std::cerr << "Could not add the consonant [" << tokens[0] << "]" << std::endl;
                        }
                    } else if (tokens[1] == "VOWEL") {
                        // Convert string tokens to int
                        int isVoiced = getBoolFromStr(tokens[2]);
                        int height = getHeightFromStr(tokens[3]);
                        int part = getPartFromStr(tokens[4]);
                        int isRounded = getBoolFromStr(tokens[5]);
                        int isTense = getBoolFromStr(tokens[6]);
                        int diacritic = getDiacriticFromStr(tokens[7]);

                        // Insert vowel only if all fields are valid
                        if (isVoiced != -1 && height != -1 && part != -1 && isRounded != -1 && isTense != -1) {
                            Vowel vowel(tokens[0], (bool)isVoiced, (Height)height, (Part)part, (Diacritic)diacritic, (bool)isRounded, (bool)isTense);

                            vowels.insert(std::pair<unsigned int, Vowel>(vowel.getId(), vowel));
                            ids.insert(std::pair<std::string, unsigned int>(tokens[0], vowel.getId()));
                        } else {
                            std::cerr << "Could not add the vowel [" << tokens[0] << "]\n";
                        }
                    } else {
                        std::cerr << tokens[1] << " is not a valid type.\n";
                    }
                } else {
                    std::cerr << "The symbol [" << tokens[0] << "] is invalid\n";
                }
            }
            phonemes.close();
        } else {
            std::cerr << "Unable to open phonemes.csv\n";
        }
    }

    std::map<unsigned int, Consonant> getConsonants() const { return consonants; }
    std::map<unsigned int, Vowel> getVowels() const { return vowels; }
    std::map<std::string, unsigned int> getIds() const { return ids; }
};

#endif
