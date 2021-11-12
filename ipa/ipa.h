#ifndef IPA_H
#define IPA_H

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

enum Type {
    CONSONANT,
    VOWEL
};

/* Where obstruction occurs during consonant production */
enum Place {
    BILABIAL,
    LABIODENTAL,
    DENTAL,
    ALVEOLAR,
    POST_ALVEOLAR,
    RETROFLEX,
    PALATAL,
    VELAR,
    UVULAR,
    PHARYNGEAL,
    GLOTTAL
};

/* How articulators are used during consonant production */
enum Manner {
    PLOSIVE,
    NASAL,
    TRILL,
    FLAP,
    FRICATIVE,
    LATERAL_FRICATIVE,
    AFFRICATE,
    APPROXIMANT,
    LATERAL_APPROXIMANT
};

/* Tongue height during vowel production */
enum Height {
    CLOSE,
    NEAR_CLOSE,
    CLOSE_MID,
    MID,
    OPEN_MID,
    NEAR_OPEN,
    OPEN
};

/* Tongue position during vowel production */
enum Part {
    FRONT,
    CENTRAL,
    BACK
};

/* Represents a discrete unit of sound */
class Phoneme {
protected:
    Type type;
    std::string symbol;
    std::string desc;
    bool isVoiced;
public:
    Type getType() const { return type; }
    std::string getSymbol() const { return symbol; }
    std::string getDesc() const { return desc; }
    bool isSymVoiced() const { return isVoiced; }

    std::string getStrVoiced (bool) const;
};

class Consonant : public Phoneme {
private:
    Place place;
    Manner manner;
    bool isPulmonic;

    std::string getStrPlace (Place) const;
    std::string getStrManner (Manner) const;
public:
    Consonant(std::string symbol, bool isVoiced, Place place,
                Manner manner, bool isPulmonic) {

        type = CONSONANT;
        this->symbol = symbol;
        this->isVoiced = isVoiced;
        this->place = place;
        this->manner = manner;
        this->isPulmonic = isPulmonic;

        desc += getStrVoiced(isVoiced) + " " + getStrPlace(place)
                + " " + getStrManner(manner);
    }

    Consonant() {}

    Place getPlace() const { return place; }
    Manner getManner() const { return manner; }
    bool isSymPulmonic() const { return isPulmonic; }
};

class Vowel : public Phoneme {
private:
    Height height;
    Part part;
    bool isRounded;
    bool isTense;

    std::string getStrHeight (Height) const;
    std::string getStrPart (Part) const;
    std::string getStrRounded (bool) const;
    std::string getStrTense (bool) const;
public:
    Vowel(std::string symbol, bool isVoiced, Height height,
                Part part, bool isRounded, bool isTense) {

        type = VOWEL;
        this->symbol = symbol;
        this->isVoiced = isVoiced;
        this->height = height;
        this->part = part;
        this->isRounded = isRounded;
        this->isTense = isTense;

        desc += ((!isVoiced) ? getStrVoiced(isVoiced) + " " : "") + getStrHeight(height) + " "
                + getStrPart(part) + " " + getStrRounded(isRounded) + " "
                + getStrTense(isTense) + " Vowel";
    }

    Vowel() {}

    bool isSymRounded() const { return isRounded; }
    bool isSymTense() const { return isTense; }
    Height getHeight() const { return height; }
    Part getPart() const { return part; }

};

/* Represents all possible phonemes or the
 * particular set of phonemes of a language */
class SoundSystem {
private:
    std::string name;
    std::map<std::string, Consonant> consonants;
    std::map<std::string, Vowel> vowels;

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

                        // Insert consonant only if all fields are valid
                        if (tokens[0] != "" && isVoiced != -1 && place != -1 && manner != -1 && isPulmonic != -1) {
                            Consonant consonant(tokens[0], (bool)isVoiced, (Place)place, (Manner)manner, (bool)isPulmonic);
                            consonants.insert(std::pair<std::string, Consonant>(tokens[0], consonant));
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

                        // Insert vowel only if all fields are valid
                        if (tokens[0] != "" && isVoiced != -1 && height != -1 && part != -1 && isRounded != -1 && isTense != -1) {
                            Vowel vowel(tokens[0], (bool)isVoiced, (Height)height, (Part)part, (bool)isRounded, (bool)isTense);
                            vowels.insert(std::pair<std::string, Vowel>(tokens[0], vowel));
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

    std::map<std::string, Consonant> getConsonants() const { return consonants; }
    std::map<std::string, Vowel> getVowels() const { return vowels; }
};

#endif
