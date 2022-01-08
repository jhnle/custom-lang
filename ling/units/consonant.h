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
    Place place;
    Manner manner;
    Voicing voicing;
    Coarticulation coart;
    Articulation art;
    Release release;
    bool syllabic;
    float probOnset;        // Probabilty of phoneme occuring in onset
    float probNucleus;      // Probabilty of phoneme occuring in nucleus if syllabic
    float probCoda;         // Probabilty of phoneme occuring in coda

    std::string getStrPlace(Place) const;
    std::string getStrManner(Manner) const;
    std::string getStrArt(Articulation) const;
    std::string getStrRel(Release) const;
public:
    Consonant(std::string symbol, float probOnset, float probNucleus, float probCoda,
              Place place, Manner manner, Voicing voicing, Coarticulation coart,
              Articulation art, Release release, bool syllabic) {

        type = Type::consonant;
        this->symbol = symbol;
        this->probOnset = probOnset;
        this->probNucleus = probNucleus;
        this->probCoda = probCoda;
        this->place = place;
        this->manner = manner;
        this->voicing = voicing;
        this->coart = coart;
        this->art = art;
        this->release = release;
        this->syllabic = syllabic;

        // Syllabic|Release|Art|Coart|Voicing|Manner|Place|Type
        id = (syllabic * 0x10000000) + (static_cast<int>(release) * 0x1000000) + (static_cast<int>(art) * 0x100000)
             + (static_cast<int>(coart) * 0x10000) + (static_cast<int>(voicing) * 0x1000)
             + (static_cast<int>(manner) * 0x100) + (static_cast<int>(place) * 0x10)
             + static_cast<int>(Type::consonant);

        std::string srel = getStrRel(release);
        std::string sart = getStrArt(art);
        std::string scoart = getStrCoart(coart);
        std::string svoic = getStrVoicing(voicing);

        desc += (syllabic ? "Syllabic " : "") + std::string(srel != "" ? srel + " " : "") + (sart != "" ? sart + " " : "")
                + (scoart != "" ? scoart + " " : "") + (svoic != "" ? svoic + " " : "") + getStrPlace(place) + " " + getStrManner(manner);
    }

    Consonant() {}

    bool operator==(const Consonant& consonant) {
        return this->getId() == consonant.getId() ? true : false;
    }

    Place getPlace() const { return place; }
    Manner getManner() const { return manner; }
    Voicing getVoicing() const { return voicing; }
    Coarticulation getCoart() const { return coart; }
    Articulation getArt() const { return art; }
    Release getRelease() const { return release; }
    float getProbOnset() const { return probOnset; }
    float getProbNucleus() const { return probNucleus; }
    float getProbCoda() const { return probCoda; }
    bool isSyllabic() const { return syllabic; }
};

#endif
