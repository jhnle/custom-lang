#include "morpheme.h"

std::string Morpheme::getStrMorphType(MorphType type) {
    static std::map<MorphType, std::string> types {
        {MorphType::root, "Root"},
        {MorphType::function, "Function"},
        {MorphType::derivationalAffix, "Derivational Affix"},
        {MorphType::inflectionalAffix, "Inflectional Affix"}
    };

    std::map<MorphType, std::string>::iterator it;

    it = types.find(type);
    return it != types.end() ? it->second : "NA";
}

std::string Morpheme::getStrConLexCat(ConLexCat lexCat) {
    static std::map<ConLexCat, std::string> lexCats {
        {ConLexCat::noun, "noun"},
        {ConLexCat::verb, "verb"},
        {ConLexCat::adjective, "adjective"},
        {ConLexCat::adverb, "adverb"}
    };

    std::map<ConLexCat, std::string>::iterator it;

    it = lexCats.find(lexCat);
    return it != lexCats.end() ? it->second : "NA";
}

std::string Morpheme::getStrFuncLexCat(FuncLexCat lexCat) {
    static std::map<FuncLexCat, std::string> lexCats {
        {FuncLexCat::determiner, "determiner"},
        {FuncLexCat::preposition, "preposition"},
        {FuncLexCat::pronoun, "pronoun"},
        {FuncLexCat::conjunction, "conjunction"}
    };

    std::map<FuncLexCat, std::string>::iterator it;

    it = lexCats.find(lexCat);
    return it != lexCats.end() ? it->second : "NA";
}
