#include <stdio.h>

void chline(char ch, int i, int j) {
    for (int col = 1; col < i; col++) {
        printf(" ");
    }
    for (int col = i; col <= j; col++) {
        printf("%c", ch);
    }
    printf("\n");
}

int main() {
    printf("Тестирование функции chline:\n");
    chline('*', 3, 7);
    chline('A', 1, 5);
    chline('#', 10, 15);
    return 0;
}
