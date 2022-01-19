#include "morpheme_gen.h"
#include "syllable_gen.h"

#include <random>

RootMorph makeRootMorph(SoundSystem& soundSystem,
                        std::array<int, 4>& max,
                        std::array<int, 4>& min) {

    ConLexCat lexAttach;
    int numSyl;
    bool free;
    std::vector<Syllable> syllables;
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    // TODO max and min # syllables should be defined in the ruleSystem
    std::uniform_int_distribution<> disSyl(1, 2);
    std::uniform_int_distribution<> disCon(0, 3);
    std::uniform_int_distribution<> disFree(0, 1);

    lexAttach = (ConLexCat)(disCon(gen));
    numSyl = disSyl(gen);
    free = disFree(gen);

    for (int i = 0; i < numSyl; i++) {
        syllables.push_back(makeSyllable(soundSystem, max, min));
    }

    return RootMorph(syllables, lexAttach, free);
}

FunctionMorph makeFuncMorph(SoundSystem& soundSystem,
                                std::array<int, 4>& max,
                                std::array<int, 4>& min) {

    FuncLexCat lexCat;
    int numSyl;
    std::vector<Syllable> syllables;
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    // TODO max and min # syllables should be defined in the ruleSystem
    std::uniform_int_distribution<> disSyl(1, 2);
    std::uniform_int_distribution<> disFunc(0, 3);

    lexCat = (FuncLexCat)(disFunc(gen));
    numSyl = disSyl(gen);

    for (int i = 0; i < numSyl; i++) {
        syllables.push_back(makeSyllable(soundSystem, max, min));
    }

    return FunctionMorph(syllables, lexCat);
}

DerivationalAffix makeDerivAffix(SoundSystem& soundSystem,
                                 std::array<int, 4>& max,
                                 std::array<int, 4>& min) {

    ConLexCat lexAttach, lexChange;
    int numSyl;
    std::vector<Syllable> syllables;
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    // TODO max and min # syllables should be defined in the ruleSystem
    std::uniform_int_distribution<> disSyl(1, 2);
    std::uniform_int_distribution<> disCon(0, 3);

    lexAttach = (ConLexCat)(disCon(gen));
    lexChange = (ConLexCat)(disCon(gen));
    numSyl = disSyl(gen);

    for (int i = 0; i < numSyl; i++) {
        syllables.push_back(makeSyllable(soundSystem, max, min));
    }

    return DerivationalAffix(syllables, lexAttach, lexChange);
}

InflectionalAffix makeInflecAffix(SoundSystem& soundSystem,
                                  std::array<int, 4>& max,
                                  std::array<int, 4>& min) {

    ConLexCat lexAttach;
    int numSyl;
    std::vector<Syllable> syllables;
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    // TODO max and min # syllables should be defined in the ruleSystem
    std::uniform_int_distribution<> disSyl(1, 2);
    std::uniform_int_distribution<> disCon(0, 3);

    lexAttach = (ConLexCat)(disCon(gen));
    numSyl = disSyl(gen);

    for (int i = 0; i < numSyl; i++) {
        syllables.push_back(makeSyllable(soundSystem, max, min));
    }

    return InflectionalAffix(syllables, lexAttach);
}
