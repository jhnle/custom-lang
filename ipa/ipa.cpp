#include <iostream>
#include "ipa.h"

static std::string printMember(Place place);
static std::string printMember(Manner manner);
static std::string printMember(Height height);
static std::string printMember(Part part);
static std::string printMember(bool b);

/* Creates an object for each unit of sound and stores them in a map,
 *  Where the symbol is the key, and the corresponding object is the value */
std::map<std::string, SoundSymbol> getSoundSymbols() {
    std::map<std::string, SoundSymbol> soundSymbols;

    //Pulmonic consonants
    SoundSymbol p("p", false, BILABIAL, PLOSIVE, true);
    SoundSymbol b("b", true, BILABIAL, PLOSIVE, true);
    SoundSymbol t("t", false, ALVEOLAR, PLOSIVE, true);
    SoundSymbol d("d", true, ALVEOLAR, PLOSIVE, true);
    SoundSymbol k("k", false, VELAR, PLOSIVE, true);
    SoundSymbol g("g", true, VELAR, PLOSIVE, true);
    SoundSymbol ʔ("ʔ", false, GLOTTAL, PLOSIVE, true);
    SoundSymbol m("m", true, BILABIAL, NASAL, true);
    SoundSymbol n("n", true, ALVEOLAR, NASAL, true);
    SoundSymbol ŋ("ŋ", true, VELAR, NASAL, true);
    SoundSymbol ɾ("ɾ", true, ALVEOLAR, FLAP, true);
    SoundSymbol f("f", false, LABIODENTAL, FRICATIVE, true);
    SoundSymbol v("v", true, LABIODENTAL, FRICATIVE, true);
    SoundSymbol θ("θ", false, DENTAL, FRICATIVE, true);
    SoundSymbol ð("ð", true, DENTAL, FRICATIVE, true);
    SoundSymbol s("s", false, ALVEOLAR, FRICATIVE, true);
    SoundSymbol z("z", true, ALVEOLAR, FRICATIVE, true);
    SoundSymbol ʃ("ʃ", false, POST_ALVEOLAR, FRICATIVE, true);
    SoundSymbol ʒ("ʒ", true, POST_ALVEOLAR, FRICATIVE, true);
    SoundSymbol h("h", false, GLOTTAL, FRICATIVE, true);
    SoundSymbol tʃ("tʃ", false, POST_ALVEOLAR, AFFRICATE, true);
    SoundSymbol dʒ("dʒ", true, POST_ALVEOLAR, AFFRICATE, true);
    SoundSymbol ɹ("ɹ", true, ALVEOLAR, APPROXIMANT, true);
    SoundSymbol l("l", true, ALVEOLAR, LATERAL_APPROXIMANT, true);
    SoundSymbol j("j", true, PALATAL, APPROXIMANT, true);
    SoundSymbol w("w", true, VELAR, APPROXIMANT, true);

    //Vowels
    SoundSymbol i("i", true, CLOSE, FRONT, false, true);
    SoundSymbol u("u", true, CLOSE, FRONT, true, true);
    SoundSymbol ɪ("ɪ", true, NEAR_CLOSE, FRONT, false, false);
    SoundSymbol ʊ("ʊ", true, NEAR_CLOSE, BACK, true, false);
    SoundSymbol e("e", true, CLOSE_MID, FRONT, false, true);
    SoundSymbol o("o", true, CLOSE_MID, BACK, true, true);
    SoundSymbol ə("ə", true, MID, CENTRAL, false, false);
    SoundSymbol ɛ("ɛ", true, OPEN_MID, FRONT, false, false);
    SoundSymbol ʌ("ʌ", true, OPEN_MID, BACK, false, false);
    SoundSymbol ɔ("ɔ", true, OPEN_MID, BACK, true, false);
    SoundSymbol æ("æ", true, NEAR_OPEN, FRONT, false, false);
    SoundSymbol ɑ("ɑ", true, OPEN, BACK, false, false);


    soundSymbols.insert(std::pair<std::string, SoundSymbol>(p.getSymbol(), p));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(b.getSymbol(), b));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(t.getSymbol(), t));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(d.getSymbol(), d));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(k.getSymbol(), k));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(g.getSymbol(), g));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ʔ.getSymbol(), ʔ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(m.getSymbol(), m));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(n.getSymbol(), n));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ŋ.getSymbol(), ŋ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ɾ.getSymbol(), ɾ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(f.getSymbol(), f));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(v.getSymbol(), v));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(θ.getSymbol(), θ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ð.getSymbol(), ð));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(s.getSymbol(), s));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(z.getSymbol(), z));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ʃ.getSymbol(), ʃ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ʒ.getSymbol(), ʒ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(h.getSymbol(), h));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(tʃ.getSymbol(), tʃ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(dʒ.getSymbol(), dʒ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ɹ.getSymbol(), ɹ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(l.getSymbol(), l));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(j.getSymbol(), j));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(w.getSymbol(), w));

    soundSymbols.insert(std::pair<std::string, SoundSymbol>(i.getSymbol(), i));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(u.getSymbol(), u));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ɪ.getSymbol(), ɪ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ʊ.getSymbol(), ʊ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(e.getSymbol(), e));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(o.getSymbol(), o));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ə.getSymbol(), ə));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ɛ.getSymbol(), ɛ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ʌ.getSymbol(), ʌ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ɔ.getSymbol(), ɔ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(æ.getSymbol(), æ));
    soundSymbols.insert(std::pair<std::string, SoundSymbol>(ɑ.getSymbol(), ɑ));

    return soundSymbols;
}

void printSymbol(SoundSymbol sym) {
    switch (sym.getType()) {
        case CONSONANT:
            std::cout << "~~~\n[" << sym.getSymbol() << "]\n"
                      << "Place of Articulation: " << printMember(sym.getPlace()) << std::endl
                      << "Manner of Articulation: " << printMember(sym.getManner()) << std::endl
                      << "Is voiced: " << printMember(sym.isSymVoiced()) << std::endl
                      << "Is pulmonic: " << printMember(sym.isSymPulmonic()) << std::endl;
            break;
        case VOWEL:
            std::cout << "~~~\n[" << sym.getSymbol() << "]\n"
                      << "Tongue Height: " << printMember(sym.getHeight()) << std::endl
                      << "Tongue Position: " << printMember(sym.getPart()) << std::endl
                      << "Is Rounded: " << printMember(sym.isSymRounded()) << std::endl
                      << "Is Tense: " << printMember(sym.isSymTense()) << std::endl
                      << "Is voiced: " << printMember(sym.isSymVoiced()) << std::endl;
            break;
        default:
            std::cout << "N/A\n";
            break;
    }
}

static std::string printMember(Place place) {
    switch (place) {
        case BILABIAL:
            return "Bilabial";
            break;
        case LABIODENTAL:
            return "Labiodental";
            break;
        case DENTAL:
            return "Dental";
            break;
        case ALVEOLAR:
            return "Alveolar";
            break;
        case POST_ALVEOLAR:
            return "Post Alveolar";
            break;
        case RETROFLEX:
            return "Retroflex";
            break;
        case PALATAL:
            return "Palatal";
            break;
        case VELAR:
            return "Velar";
            break;
        case UVULAR:
            return "Uvular";
            break;
        case PHARYNGEAL:
            return "Pharyngeal";
            break;
        case GLOTTAL:
            return "Glottal";
            break;
        default:
            return "N/A\n";
            break;
    }
}

static std::string printMember(Manner manner) {
    switch (manner) {
        case PLOSIVE:
            return "Plosive";
            break;
        case NASAL:
            return "Nasal";
            break;
        case TRILL:
            return "Trill";
            break;
        case FLAP:
            return "Flap";
        case FRICATIVE:
            return "Fricative";
            break;
        case LATERAL_FRICATIVE:
            return "Lateral Fricative";
            break;
        case AFFRICATE:
            return "Affricate";
            break;
        case APPROXIMANT:
            return "Approximant";
            break;
        case LATERAL_APPROXIMANT:
            return "Lateral Approximant";
            break;
        default:
            return "N/A\n";
            break;
    }
}

static std::string printMember(Height height) {
    switch (height) {
        case CLOSE:
            return "Close";
            break;
        case NEAR_CLOSE:
            return "Near Close";
            break;
        case CLOSE_MID:
            return "Close Mid";
            break;
        case MID:
            return "Mid";
        case OPEN_MID:
            return "Open Mid";
            break;
        case NEAR_OPEN:
            return "Near Open";
            break;
        case OPEN:
            return "Open";
            break;
        default:
            return "N/A\n";
            break;
    }
}

static std::string printMember(Part part) {
    switch (part) {
        case FRONT:
            return "Front";
            break;
        case CENTRAL:
            return "Central";
            break;
        case BACK:
            return "Back";
            break;
        default:
            return "N/A\n";
            break;
    }
}

static std::string printMember(bool b) {
    if (b) {
        return "True";
    } else {
        return "False";
    }
}
