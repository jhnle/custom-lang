CC = g++
CFLAGS = -g -Wall
PROGS = print_all phon_rules

.PHONY: all clean

all: $(PROGS)

clean:
	rm -f $(PROGS) tests/*.o ipa/*.o

print_all: tests/print_all.o ipa/ipa.o
	$(CC) $(CFLAGS) tests/print_all.cpp ipa/ipa.cpp -o print_all

phon_rules: tests/phon_rules.o ipa/ipa.o
	$(CC) $(CFLAGS) tests/phon_rules.cpp ipa/ipa.cpp -o phon_rules
