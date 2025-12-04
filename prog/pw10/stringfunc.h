#ifndef STRF
#define STRF

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *readInput();
void printChars(char buff[]);
int countChars(char buff[]);
int countSecWordsChars(char buff[]);
int countInputWordLen(char buff[], int length);
void processWords(char buff[]);

#endif