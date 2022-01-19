#ifndef INFLEC_AFFIX_H
#define INFLEC_AFFIX_H

#include "morpheme.h"

class InflectionalAffix : public Morpheme {
private:
    ConLexCat lexAttach;    // Lexical category affix attaches to
public:
    InflectionalAffix(std::vector<Syllable>& syllables, ConLexCat lexAttach) {
        this->type = MorphType::inflectionalAffix;
        this->lexAttach = lexAttach;
        this->free = false;
        this->numSyl = 0;

        for (auto const& syl : syllables) {
            addSyllable(syl);
        }
    }

    InflectionalAffix() {
        this->type = MorphType::inflectionalAffix;
        free = false;
        numSyl = 0;
    }

    ConLexCat getLexAttach() const { return lexAttach; }
};
#endif
