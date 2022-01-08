CXX = g++
CXXFLAGS = -g -D_GLIBCXX_USE_C99=1 -std=c++11 -Wall
PROGS = print_all phon_rules syl_gen

.PHONY: all clean

all: $(PROGS)

clean:
	rm -f $(PROGS) tests/*.o ling/units/*.o ling/word/*.o

print_all: tests/print_all.o ling/units/soundsystem.o ling/units/phoneme.o ling/units/consonant.o ling/units/vowel.o
	$(CXX) $(CXXFLAGS) tests/print_all.cpp ling/units/soundsystem.cpp ling/units/phoneme.cpp ling/units/consonant.cpp ling/units/vowel.cpp -o print_all

phon_rules: tests/phon_rules.o ling/units/soundsystem.o ling/units/phoneme.o ling/units/consonant.o ling/units/vowel.o
	$(CXX) $(CXXFLAGS) tests/phon_rules.cpp ling/units/soundsystem.cpp ling/units/phoneme.cpp ling/units/consonant.cpp ling/units/vowel.cpp -o phon_rules

syl_gen: tests/syl_gen.o ling/word/syllable_gen.o ling/units/soundsystem.o ling/units/phoneme.o ling/units/consonant.o ling/units/vowel.o
	$(CXX) $(CXXFLAGS) tests/syl_gen.cpp ling/word/syllable_gen.cpp ling/units/soundsystem.cpp ling/units/phoneme.cpp ling/units/consonant.cpp ling/units/vowel.cpp -o syl_gen
