#ifndef CONSONANT_H
#define CONSONANT_H

#include "phoneme.h"

/* Where obstruction occurs during consonant production */
enum class Place {
    bilabial,
    labiodental,
    dental,
    alveolar,
    postAlveolar,
    retroflex,
    labPalatal,     // Labialized Palatal
    postalvVel,     // Postalveolar Velar
    alvPalatal,     // Alveolo Palatal
    palatal,
    labialVelar,
    velar,
    uvular,
    pharyngeal,
    epiglottal,
    glottal
};

/* How articulators are used during consonant production */
enum class Manner {
    plosive,
    implosive,
    ejective,
    nasal,
    trill,
    flap,
    latFlap,
    fricative,
    latFricative,
    ejecFricative,
    ejecLatFricative,
    affricate,
    approximant,
    latApproximant,
    click,
    latClick
};

enum class Articulation {
    linguolabial = 1,
    apical,
    laminal,
    advanced,
    retracted,
    centralized,
    midCentralized,
    raised,
    lowered
};

enum class Release {
    aspirated = 1,
    nasalRel,
    latRel,
    noAudRel
};

class Consonant : public Phoneme {
private:
    std::string getStrPlace(Place) const;
    std::string getStrManner(Manner) const;
    std::string getStrArt(Articulation) const;
    std::string getStrRel(Release) const;
public:
    Consonant(std::string symbol, float freq, Place place, Manner manner, Voicing voicing,
              Coarticulation coarticulation, Articulation articulation, Release release, bool isSyllabic) {

        type = Type::consonant;
        this->symbol = symbol;
        this->freq = freq;

        // Syllabic|Release|Art|Coart|Voicing|Manner|Place|Type
        id = (isSyllabic * 0x10000000) + (static_cast<int>(release) * 0x1000000) + (static_cast<int>(articulation) * 0x100000)
             + (static_cast<int>(coarticulation) * 0x10000) + (static_cast<int>(voicing) * 0x1000)
             + (static_cast<int>(manner) * 0x100) + (static_cast<int>(place) * 0x10)
             + static_cast<int>(Type::consonant);

        std::string rel = getStrRel(release);
        std::string art = getStrArt(articulation);
        std::string coart = getStrCoart(coarticulation);
        std::string voic = getStrVoicing(voicing);

        desc += (isSyllabic ? "Syllabic " : "") + std::string(rel != "" ? rel + " " : "") + (art != "" ? art + " " : "")
                + (coart != "" ? coart + " " : "") + (voic != "" ? voic + " " : "") + getStrPlace(place) + " " + getStrManner(manner);
    }

    Consonant() {}
};

#endif
