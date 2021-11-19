#include "consonant.h"
#include <map>

std::string Consonant::getStrPlace (Place place) const{
    static std::map<Place, std::string> places {
        {BILABIAL, "Bilabial"},
        {LABIODENTAL, "Labiodental"},
        {DENTAL, "Dental"},
        {ALVEOLAR, "Alveolar"},
        {POST_ALVEOLAR, "Post-Alveolar"},
        {RETROFLEX, "Retroflex"},
        {LABIALIZED_PALATAL, "Labialized Palatal"},
        {POSTALVEOLAR_VELAR, "Postalveolar-Velar"},
        {ALVEOLO_PALATAL, "Alveolo-Palatal"},
        {PALATAL, "Palatal"},
        {LABIAL_VELAR, "Labial-Velar"},
        {VELAR, "Velar"},
        {UVULAR, "Uvular"},
        {PHARYNGEAL, "Pharyngeal"},
        {EPIGLOTTAL, "Epiglottal"},
        {GLOTTAL, "Glottal"}
    };

    std::map<Place, std::string>::iterator it;

    it = places.find(place);
    if (it != places.end()) {
        return it->second;
    } else {
        return "NA";
    }
}

std::string Consonant::getStrManner(Manner manner) const{
    static std::map<Manner, std::string> manners {
        {PLOSIVE, "Plosive"},
        {IMPLOSIVE, "Implosive"},
        {EJECTIVE, "Ejective"},
        {NASAL, "Nasal"},
        {TRILL, "Trill"},
        {FLAP, "Flap"},
        {LAT_FLAP, "Lateral Flap"},
        {FRICATIVE, "Fricative"},
        {LAT_FRICATIVE, "Lateral Fricative"},
        {EJEC_FRICATIVE, "Ejective Fricative"},
        {EJEC_LAT_FRICATIVE, "Ejective Lateral Fricative"},
        {AFFRICATE, "Affricate"},
        {APPROXIMANT, "Approximant"},
        {LAT_APPROXIMANT, "Lateral Approximant"},
        {CLICK, "Click"},
        {LAT_CLICK, "Lateral Click"}
    };

    std::map<Manner, std::string>::iterator it;

    it = manners.find(manner);
    if (it != manners.end()) {
        return it->second;
    } else {
        return "NA";
    }
}
