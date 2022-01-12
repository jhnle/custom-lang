#ifndef FUNCTION_MORPH_H
#define FUNCTION_MORPH_H

#include "morpheme.h"

/*
 * Represents free function morphemes
 */
class FunctionMorph : public Morpheme {
private:
    FuncLexCat lexCat;
public:
    FunctionMorph(std::vector<Syllable>& syllables, FuncLexCat lexCat) {
        this->type = MorphType::function;
        this->lexCat = lexCat;
        this->free = true;
        this->numSyl = 0;

        for (auto const& syl : syllables) {
            addSyllable(syl);
        }
    }

    FunctionMorph() {
        this->type = MorphType::function;
        free = true;
        numSyl = 0;
    }

    FuncLexCat getLexCat() const { return lexCat; }
};

#endif
