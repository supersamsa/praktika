#include <stdio.h>

int arr[] = {1, 3, 5, 2, 1, 4, 10, 2, 3, 0, 5, 15, 1, 3, 100, 0};
int len = 18;
int pc = 0;
int acc = 0;

int main() {
  printf("Commands: 1-inc, 2-dec, 3-add, 4-jump, 5-jump if zero, 0-stop\n");

  while (arr[pc] != 0 && pc < len) {
    int command = arr[pc];

    switch (command) {
    case 1:
      acc += 1;
      pc += 1;
      break;

    case 2:
      acc -= 1;
      pc += 1;
      break;

    case 3:
      acc = acc + arr[pc + 1];
      pc += 2;
      break;

    case 4: {
      int jump = arr[pc + 1];
      if (jump >= 0 && jump < len) {
        pc = jump;
      } else {
        pc += 2;
      }
    } break;

    case 5: {
      int jump = arr[pc + 1];
      if (acc == 0) {
        pc = jump;
      } else {
        pc += 2;
      }
    } break;

    default:
      pc += 1;
      break;
    }

    printf("comand = %d, acc = %d\n", command, acc);
  }

  return 0;
}