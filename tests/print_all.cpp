#include <iostream>
#include <string>
#include <map>

#include "../ipa/ipa.h"

int main() {
    std::map<std::string, SoundSymbol> soundSymbols;
    soundSymbols = getSoundSymbols();

    std::cout << "CONSONANTS\n";
    printSymbol(soundSymbols["p"]);
    printSymbol(soundSymbols["b"]);
    printSymbol(soundSymbols["t"]);
    printSymbol(soundSymbols["d"]);
    printSymbol(soundSymbols["k"]);
    printSymbol(soundSymbols["g"]);
    printSymbol(soundSymbols["ʔ"]);
    printSymbol(soundSymbols["m"]);
    printSymbol(soundSymbols["n"]);
    printSymbol(soundSymbols["ŋ"]);
    printSymbol(soundSymbols["ɾ"]);
    printSymbol(soundSymbols["f"]);
    printSymbol(soundSymbols["v"]);
    printSymbol(soundSymbols["θ"]);
    printSymbol(soundSymbols["ð"]);
    printSymbol(soundSymbols["s"]);
    printSymbol(soundSymbols["z"]);
    printSymbol(soundSymbols["ʃ"]);
    printSymbol(soundSymbols["ʒ"]);
    printSymbol(soundSymbols["h"]);
    printSymbol(soundSymbols["tʃ"]);
    printSymbol(soundSymbols["dʒ"]);
    printSymbol(soundSymbols["ɹ"]);
    printSymbol(soundSymbols["l"]);
    printSymbol(soundSymbols["j"]);
    printSymbol(soundSymbols["w"]);

    std::cout << "\nVOWELS\n";
    printSymbol(soundSymbols["i"]);
    printSymbol(soundSymbols["u"]);
    printSymbol(soundSymbols["ɪ"]);
    printSymbol(soundSymbols["ʊ"]);
    printSymbol(soundSymbols["e"]);
    printSymbol(soundSymbols["o"]);
    printSymbol(soundSymbols["ə"]);
    printSymbol(soundSymbols["ɛ"]);
    printSymbol(soundSymbols["ʌ"]);
    printSymbol(soundSymbols["ɔ"]);
    printSymbol(soundSymbols["æ"]);
    printSymbol(soundSymbols["ɑ"]);

    return 0;
}
