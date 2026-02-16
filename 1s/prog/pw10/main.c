#include "stringfunc.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("EOROER\n");
    return 1;
  }

  int functionNum = atoi(argv[1]);
  int paramValue = 0;

  if (functionNum == 3) {
    if (argc < 3) {
      printf("EROROR\n");
      return 1;
    }
    paramValue = atoi(argv[2]);
  }

  char *buffer = readInput();
  if (buffer == NULL) {
    printf("ERORO\n");
    return 1;
  }

  switch (functionNum) {
  case 1:
    countChars(buffer);
    printf("\n");
    break;

  case 2:
    countSecWordsChars(buffer);
    printf("\n");
    break;

  case 3:
    printf("words %d\n", countInputWordLen(buffer, paramValue));
    break;
  case 4:
    output(buffer);
    printf("\n");
    break;
  default:
    printf("ERORROR\n");
    free(buffer);
    return 1;
  }

  free(buffer);
  return 0;
}