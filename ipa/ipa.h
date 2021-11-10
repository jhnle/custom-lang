#ifndef IPA_H
#define IPA_H

#include <string>
#include <map>

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
class SoundUnit {
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

    std::string getStrVoiced (bool);
};

class Consonant : public SoundUnit {
private:
    Place place;
    Manner manner;
    bool isPulmonic;

    std::string getStrPlace (Place);
    std::string getStrManner (Manner);
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

class Vowel : public SoundUnit {
private:
    Height height;
    Part part;
    bool isRounded;
    bool isTense;

    std::string getStrHeight (Height);
    std::string getStrPart (Part);
    std::string getStrRounded (bool);
    std::string getStrTense (bool);
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
public:
    //Default constructor creates and adds all possible phonemes
    SoundSystem() {
        name = "ALL";

        // Consonants
        Consonant p("p", false, BILABIAL, PLOSIVE, true);
        Consonant b("b", true, BILABIAL, PLOSIVE, true);
        Consonant t("t", false, ALVEOLAR, PLOSIVE, true);
        Consonant d("d", true, ALVEOLAR, PLOSIVE, true);
        Consonant k("k", false, VELAR, PLOSIVE, true);
        Consonant g("g", true, VELAR, PLOSIVE, true);
        Consonant ʔ("ʔ", false, GLOTTAL, PLOSIVE, true);
        Consonant m("m", true, BILABIAL, NASAL, true);
        Consonant n("n", true, ALVEOLAR, NASAL, true);
        Consonant ŋ("ŋ", true, VELAR, NASAL, true);
        Consonant ɾ("ɾ", true, ALVEOLAR, FLAP, true);
        Consonant f("f", false, LABIODENTAL, FRICATIVE, true);
        Consonant v("v", true, LABIODENTAL, FRICATIVE, true);
        Consonant θ("θ", false, DENTAL, FRICATIVE, true);
        Consonant ð("ð", true, DENTAL, FRICATIVE, true);
        Consonant s("s", false, ALVEOLAR, FRICATIVE, true);
        Consonant z("z", true, ALVEOLAR, FRICATIVE, true);
        Consonant ʃ("ʃ", false, POST_ALVEOLAR, FRICATIVE, true);
        Consonant ʒ("ʒ", true, POST_ALVEOLAR, FRICATIVE, true);
        Consonant h("h", false, GLOTTAL, FRICATIVE, true);
        Consonant tʃ("tʃ", false, POST_ALVEOLAR, AFFRICATE, true);
        Consonant dʒ("dʒ", true, POST_ALVEOLAR, AFFRICATE, true);
        Consonant ɹ("ɹ", true, ALVEOLAR, APPROXIMANT, true);
        Consonant l("l", true, ALVEOLAR, LATERAL_APPROXIMANT, true);
        Consonant j("j", true, PALATAL, APPROXIMANT, true);
        Consonant w("w", true, VELAR, APPROXIMANT, true);

        consonants.insert(std::pair<std::string, Consonant>(p.getSymbol(), p));
        consonants.insert(std::pair<std::string, Consonant>(b.getSymbol(), b));
        consonants.insert(std::pair<std::string, Consonant>(t.getSymbol(), t));
        consonants.insert(std::pair<std::string, Consonant>(d.getSymbol(), d));
        consonants.insert(std::pair<std::string, Consonant>(k.getSymbol(), k));
        consonants.insert(std::pair<std::string, Consonant>(g.getSymbol(), g));
        consonants.insert(std::pair<std::string, Consonant>(ʔ.getSymbol(), ʔ));
        consonants.insert(std::pair<std::string, Consonant>(m.getSymbol(), m));
        consonants.insert(std::pair<std::string, Consonant>(n.getSymbol(), n));
        consonants.insert(std::pair<std::string, Consonant>(ŋ.getSymbol(), ŋ));
        consonants.insert(std::pair<std::string, Consonant>(ɾ.getSymbol(), ɾ));
        consonants.insert(std::pair<std::string, Consonant>(f.getSymbol(), f));
        consonants.insert(std::pair<std::string, Consonant>(v.getSymbol(), v));
        consonants.insert(std::pair<std::string, Consonant>(θ.getSymbol(), θ));
        consonants.insert(std::pair<std::string, Consonant>(ð.getSymbol(), ð));
        consonants.insert(std::pair<std::string, Consonant>(s.getSymbol(), s));
        consonants.insert(std::pair<std::string, Consonant>(z.getSymbol(), z));
        consonants.insert(std::pair<std::string, Consonant>(ʃ.getSymbol(), ʃ));
        consonants.insert(std::pair<std::string, Consonant>(ʒ.getSymbol(), ʒ));
        consonants.insert(std::pair<std::string, Consonant>(h.getSymbol(), h));
        consonants.insert(std::pair<std::string, Consonant>(tʃ.getSymbol(), tʃ));
        consonants.insert(std::pair<std::string, Consonant>(dʒ.getSymbol(), dʒ));
        consonants.insert(std::pair<std::string, Consonant>(ɹ.getSymbol(), ɹ));
        consonants.insert(std::pair<std::string, Consonant>(l.getSymbol(), l));
        consonants.insert(std::pair<std::string, Consonant>(j.getSymbol(), j));
        consonants.insert(std::pair<std::string, Consonant>(w.getSymbol(), w));

        //Vowels
        Vowel i("i", true, CLOSE, FRONT, false, true);
        Vowel u("u", true, CLOSE, FRONT, true, true);
        Vowel ɪ("ɪ", true, NEAR_CLOSE, FRONT, false, false);
        Vowel ʊ("ʊ", true, NEAR_CLOSE, BACK, true, false);
        Vowel e("e", true, CLOSE_MID, FRONT, false, true);
        Vowel o("o", true, CLOSE_MID, BACK, true, true);
        Vowel ə("ə", true, MID, CENTRAL, false, false);
        Vowel ɛ("ɛ", true, OPEN_MID, FRONT, false, false);
        Vowel ʌ("ʌ", true, OPEN_MID, BACK, false, false);
        Vowel ɔ("ɔ", true, OPEN_MID, BACK, true, false);
        Vowel æ("æ", true, NEAR_OPEN, FRONT, false, false);
        Vowel ɑ("ɑ", true, OPEN, BACK, false, false);

        vowels.insert(std::pair<std::string, Vowel>(i.getSymbol(), i));
        vowels.insert(std::pair<std::string, Vowel>(u.getSymbol(), u));
        vowels.insert(std::pair<std::string, Vowel>(ɪ.getSymbol(), ɪ));
        vowels.insert(std::pair<std::string, Vowel>(ʊ.getSymbol(), ʊ));
        vowels.insert(std::pair<std::string, Vowel>(e.getSymbol(), e));
        vowels.insert(std::pair<std::string, Vowel>(o.getSymbol(), o));
        vowels.insert(std::pair<std::string, Vowel>(ə.getSymbol(), ə));
        vowels.insert(std::pair<std::string, Vowel>(ɛ.getSymbol(), ɛ));
        vowels.insert(std::pair<std::string, Vowel>(ʌ.getSymbol(), ʌ));
        vowels.insert(std::pair<std::string, Vowel>(ɔ.getSymbol(), ɔ));
        vowels.insert(std::pair<std::string, Vowel>(æ.getSymbol(), æ));
        vowels.insert(std::pair<std::string, Vowel>(ɑ.getSymbol(), ɑ));
    }

    std::map<std::string, Consonant> getConsonants() const { return consonants; }
    std::map<std::string, Vowel> getVowels() const { return vowels; }
};

#endif
