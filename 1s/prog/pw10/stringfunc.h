#ifndef STRF
#define STRF

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *readInput();
void countSecWordsChars(char buff[]);
void countChars(char buff[]);
int countInputWordLen(char buff[], int length);
void output(char buff[]);

#endif