#include <map>

#include "phoneme.h"

std::string Phoneme::getStrVoicing(Voicing voic) const{
    static std::map<Voicing , std::string> voics {
        {VOICELESS, "Voiceless"},
        {BREATHY_VOICED, "Breathy-voiced"},
        {CREAKY_VOICED, "Creaky-voiced"},
        {VOICED, "Voiced"}
    };

    std::map<Voicing, std::string>::iterator it;

    it = voics.find(voic);
    if (it != voics.end()) {
        return it->second;
    } else {
        return "";
    }
}

std::string Phoneme::getStrCoart(Coarticulation coart) const {
    static std::map<Coarticulation, std::string> coarts {
        {LABIALIZED, "Labialized"},
        {PALATALIZED, "Palatalized"},
        {VELARIZED, "Velarized"},
        {PHARYNGEALIZED, "Pharyngealized"},
        {VEL_PHA, "Velar. or Phary."},
        {RHOTICIZED, "Rhoticized"},
        {NASALIZED, "Nasalized"}
    };

    std::map<Coarticulation, std::string>::iterator it;

    it = coarts.find(coart);
    if (it != coarts.end()) {
        return it->second;
    } else {
        return "";
    }
}
