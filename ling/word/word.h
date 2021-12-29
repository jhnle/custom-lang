/*
 * A word represents a sequence of syllables
 * and their transcription.
 *
 */

#ifndef WORD_H
#define WORD_H

#include <initializer_list>
#include "syllable.h"

class Word {
private:
    std::vector<Syllable> syllables;
    std::string phonemic;               // Phonemic transcription of word
    int numSyl;
public:
    Word(std::initializer_list<Syllable> list) {
        numSyl = 0;
        for (const auto& syllable : list) {
            addSyllable(syllable);
        }
    }

    Word() { numSyl = 0; }

    void addSyllable(Syllable syl) {
        syllables.push_back(syl);
        phonemic += syl.getStrSyl();
        numSyl++;
    }

    std::vector<Syllable> getSyllables() const { return syllables; }
    std::string getPhonemic() const { return phonemic; }
    int getNumSyl() const { return numSyl; }
};

#endif
