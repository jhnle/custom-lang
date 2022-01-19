#ifndef ROOT_MORPH_H
#define ROOT_MORPH_H

#include "morpheme.h"

/*
 * Represents free and bound root morphemes
 */
class RootMorph : public Morpheme {
private:
    ConLexCat lexCat;
public:
    RootMorph(std::vector<Syllable>& syllables, ConLexCat lexCat, bool free) {
        this->type = MorphType::root;
        this->lexCat = lexCat;
        this->free = free;
        this->numSyl = 0;

        for (auto const& syl : syllables) {
            addSyllable(syl);
        }
    }

    RootMorph() {
        this->type = MorphType::root;
        free = false;
        numSyl = 0;
    }

    ConLexCat getLexCat() const { return lexCat; }
};

#endif
