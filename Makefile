CC = g++
CFLAGS = -g -Wall
PROGS = print_all phon_rules

.PHONY: all clean

all: $(PROGS)

clean:
	rm -f $(PROGS) tests/*.o ipa/*.o

print_all: tests/print_all.o ipa/soundsystem.o ipa/phoneme.o ipa/consonant.o ipa/vowel.o
	$(CC) $(CFLAGS) tests/print_all.cpp ipa/soundsystem.cpp ipa/phoneme.cpp ipa/consonant.cpp ipa/vowel.cpp -o print_all

phon_rules: tests/phon_rules.o ipa/soundsystem.o ipa/phoneme.o ipa/consonant.o ipa/vowel.o
	$(CC) $(CFLAGS) tests/phon_rules.cpp ipa/soundsystem.cpp ipa/phoneme.cpp ipa/consonant.cpp ipa/vowel.cpp -o phon_rules
