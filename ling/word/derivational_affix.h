#ifndef DERIV_AFFIX_H
#define DERIV_AFFIX_H

#include "morpheme.h"

class DerivationalAffix : public Morpheme {
private:
    ConLexCat lexAttach;    // Lexical category affix attaches to
    ConLexCat lexChange;    // Lexical category affix changes morpheme to
public:
    DerivationalAffix(std::vector<Syllable>& syllables, ConLexCat lexAttach, ConLexCat lexChange) {
        this->type = MorphType::derivationalAffix;
        this->lexAttach = lexAttach;
        this->lexChange = lexChange;
        this->free = false;
        this->numSyl = 0;

        for (auto const& syl : syllables) {
            addSyllable(syl);
        }
    }

    DerivationalAffix() {
        this->type = MorphType::derivationalAffix;
        free = false;
        numSyl = 0;
    }

    ConLexCat getLexAttach() const { return lexAttach; }
    ConLexCat getLexChange() const { return lexChange; }
};

#endif
