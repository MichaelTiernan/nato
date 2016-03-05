/**
 * nato.c
 * Prints all arguments as a sequence of NATO phonetic letters and digits, one word per line.
 * Other characters are printed as-is.
 * (C) 2016 Michael Incardona
 */
 
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LETTERS 26
#define DIGITS 10

#define WHITESPACE_STR "\n"

char* NATO[LETTERS] = {
    "alpha",
    "bravo",
    "charlie",
    "delta",
    "echo",
    "foxtrot",
    "golf",
    "hotel",
    "india",
    "juliet",
    "kilo",
    "lima",
    "mike",
    "november",
    "oscar",
    "papa",
    "quebec",
    "romeo",
    "sierra",
    "tango",
    "uniform",
    "victor",
    "whiskey",
    "xray",
    "yankee",
    "zulu"
};

char* NUMBER[DIGITS] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "niner"
};

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Use: nato words to translate\n");
        return 1;
    }
    for (size_t i = 1; i < argc; i++) {
        size_t wordLength = strlen(argv[i]);
        for (size_t j = 0; j < wordLength; j++) {
            char c = argv[i][j];
            if (isalpha(c)) {
                printf("%s ", NATO[tolower(c) - 'a']);
            } else if (isdigit(c)) {
                printf("%s ", NUMBER[c - '0']);
            } else if (isspace(c)) {
                printf("%s", WHITESPACE_STR);
            } else {
                printf("%c ", c);
            }
        }
        if (i != argc - 1) {
            printf("%s", WHITESPACE_STR);
        }
    }
    printf("\n");
    return 0;
}
