CC = g++
CFLAGS = -g -Wall
PROGS = print_all phon_rules

.PHONY: all clean

all: $(PROGS)

clean:
	rm -f $(PROGS) tests/*.o ling/phonemes/*.o

print_all: tests/print_all.o ling/phonemes/soundsystem.o ling/phonemes/phoneme.o ling/phonemes/consonant.o ling/phonemes/vowel.o
	$(CC) $(CFLAGS) tests/print_all.cpp ling/phonemes/soundsystem.cpp ling/phonemes/phoneme.cpp ling/phonemes/consonant.cpp ling/phonemes/vowel.cpp -o print_all

phon_rules: tests/phon_rules.o ling/phonemes/soundsystem.o ling/phonemes/phoneme.o ling/phonemes/consonant.o ling/phonemes/vowel.o
	$(CC) $(CFLAGS) tests/phon_rules.cpp ling/phonemes/soundsystem.cpp ling/phonemes/phoneme.cpp ling/phonemes/consonant.cpp ling/phonemes/vowel.cpp -o phon_rules
