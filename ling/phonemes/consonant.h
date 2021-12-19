#ifndef CONSONANT_H
#define CONSONANT_H

#include "phoneme.h"

class Consonant : public Phoneme {
private:
    std::string getStrPlace (Place) const;
    std::string getStrManner (Manner) const;
    std::string getStrArt (Articulation) const;
    std::string getStrRel (Release) const;
public:
    Consonant(std::string symbol, float freq, Place place, Manner manner, Voicing voicing,
              Coarticulation coarticulation, Articulation articulation, Release release, bool isSyllabic) {

        type = CONSONANT;
        this->symbol = symbol;
        this->freq = freq;

        // Syllabic|Release|Art|Coart|Voicing|Manner|Place|Type
        id = (isSyllabic * 0x10000000) + (release * 0x1000000) + (articulation * 0x100000) + (coarticulation * 0x10000)
             + (voicing * 0x1000) + (manner * 0x100) + (place * 0x10) + (CONSONANT);

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
