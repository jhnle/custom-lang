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

/* Returns 1 if true, 0 if false, -1 if neither */
int SoundSystem::getBoolFromStr(std::string str) const{
    if (str == "TRUE") {
        return 1;
    } else if (str == "FALSE") {
        return 0;
    } else {
        return -1;
    }
}

int SoundSystem::getDiacriticFromStr(std::string str) const{
    static std::map<std::string, Diacritic> diacs {
        {"VOICELESS", VOICELESS},
        {"VOICED", VOICED},
        {"ASPIRATED", ASPIRATED},
        {"MORE_ROUNDED", MORE_ROUNDED},
        {"LESS_ROUNDED", LESS_ROUNDED},
        {"ADVANCED", ADVANCED},
        {"RETRACTED", RETRACTED},
        {"CENTRALIZED", CENTRALIZED},
        {"MID_CENTRALIZED", MID_CENTRALIZED},
        {"SYLLABIC", SYLLABIC},
        {"NON_SYLLABIC", NON_SYLLABIC},
        {"RHOTICITY", RHOTICITY},
        {"BREATHY_VOICED", BREATHY_VOICED},
        {"CREAKY_VOICED", CREAKY_VOICED},
        {"LINGUOLABIAL", LINGUOLABIAL},
        {"LABIALIZED", LABIALIZED},
        {"PALATALIZED", PALATALIZED},
        {"VELARIZED", VELARIZED},
        {"PHARYNGEALIZED", PHARYNGEALIZED},
        {"VEL_PHA", VEL_PHA},
        {"RAISED", RAISED},
        {"LOWERED", LOWERED},
        {"ADV_TONGUE_ROOT", ADV_TONGUE_ROOT},
        {"RET_TONGUE_ROOT", RET_TONGUE_ROOT},
        {"D_DENTAL", D_DENTAL},
        {"LAMINAL", LAMINAL},
        {"NASALIZED", NASALIZED},
        {"D_EJECTIVE", D_EJECTIVE},
        {"NASAL_REL", NASAL_REL},
        {"LAT_REL", LAT_REL},
        {"NO_AUD_REL", NO_AUD_REL}
    };

    std::map<std::string, Diacritic>::iterator it;

    it = diacs.find(str);
    if (it != diacs.end()) {
        return it->second;
    } else {
        return 0;
    }
}

int SoundSystem::getPlaceFromStr(std::string str) const{
    static std::map<std::string, Place> places {
        {"BILABIAL", BILABIAL},
        {"LABIODENTAL", LABIODENTAL},
        {"DENTAL", DENTAL},
        {"ALVEOLAR", ALVEOLAR},
        {"POST_ALVEOLAR", POST_ALVEOLAR},
        {"RETROFLEX", RETROFLEX},
        {"LABIALIZED_PALATAL", LABIALIZED_PALATAL},
        {"POSTALVEOLAR_VELAR", POSTALVEOLAR_VELAR},
        {"ALVEOLO_PALATAL", ALVEOLO_PALATAL},
        {"PALATAL", PALATAL},
        {"LABIAL_VELAR", LABIAL_VELAR},
        {"VELAR", VELAR},
        {"UVULAR", UVULAR},
        {"PHARYNGEAL", PHARYNGEAL},
        {"EPIGLOTTAL", EPIGLOTTAL},
        {"GLOTTAL", GLOTTAL}
    };

    std::map<std::string, Place>::iterator it;

    it = places.find(str);
    if (it != places.end()) {
        return it->second;
    } else {
        return -1;
    }
}

int SoundSystem::getMannerFromStr(std::string str) const{
    static std::map<std::string, Manner> manners {
        {"PLOSIVE", PLOSIVE},
        {"IMPLOSIVE", IMPLOSIVE},
        {"EJECTIVE", EJECTIVE},
        {"NASAL", NASAL},
        {"TRILL", TRILL},
        {"FLAP", FLAP},
        {"LAT_FLAP", LAT_FLAP},
        {"FRICATIVE", FRICATIVE},
        {"LAT_FRICATIVE", LAT_FRICATIVE},
        {"EJEC_FRICATIVE", EJEC_FRICATIVE},
        {"EJEC_LAT_FRICATIVE", EJEC_LAT_FRICATIVE},
        {"AFFRICATE", AFFRICATE},
        {"APPROXIMANT", APPROXIMANT},
        {"LAT_APPROXIMANT", LAT_APPROXIMANT},
        {"CLICK", CLICK},
        {"LAT_CLICK", LAT_CLICK}
    };

    std::map<std::string, Manner>::iterator it;

    it = manners.find(str);
    if (it != manners.end()) {
        return it->second;
    } else {
        return -1;
    }
}

int SoundSystem::getHeightFromStr(std::string str) const{
    static std::map<std::string, Height> heights {
        {"CLOSE", CLOSE},
        {"NEAR_CLOSE", NEAR_CLOSE},
        {"CLOSE_MID", CLOSE_MID},
        {"MID", MID},
        {"OPEN_MID", OPEN_MID},
        {"NEAR_OPEN", NEAR_OPEN},
        {"OPEN", OPEN}
    };

    std::map<std::string, Height>::iterator it;

    it = heights.find(str);
    if (it != heights.end()) {
        return it->second;
    } else {
        return -1;
    }
}

int SoundSystem::getPartFromStr(std::string str) const{
    static std::map<std::string, Part> parts {
        {"FRONT", FRONT},
        {"CENTRAL", CENTRAL},
        {"BACK", BACK}
    };

    std::map<std::string, Part>::iterator it;

    it = parts.find(str);
    if (it != parts.end()) {
        return it->second;
    } else {
        return -1;
    }
}
