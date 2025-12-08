#include <stdio.h>

int arr[] = {1, 3, 5, 2, 1, 4, 10, 2, 3, 0, 5, 15, 1, 3, 100, 0};
int len = 16;
int pc = 0; 
int acc = 0;  

int main() {
    printf("Commands: 1-inc, 2-dec, 3-add, 4-jump, 5-jump if zero, 0-stop\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    while (pc < len && arr[pc] != 0) {
        int command = arr[pc];
        
        printf("PC=%2d: command %d -> ", pc, command);
        
        switch (command) {
            case 1: 
                acc += 1;
                pc += 1;
                printf("acc = %d\n", acc);
                break;
                
            case 2:
                acc -= 1;
                pc += 1;
                printf("acc = %d\n", acc);
                break;
                
            case 3:
                acc = acc + arr[pc + 1];
                pc += 2;
                printf("acc = %d (added %d)\n", acc, arr[pc - 1]);
                break;
                
            case 4:
                {
                    int jump = arr[pc + 1];
                    if (jump >= 0 && jump < len) {
                        printf("jump to address %d\n", jump);
                        pc = jump;
                    } else {
                        printf("invalid address %d, skipping\n", jump);
                        pc += 2;
                    }
                }
                break;
                
            case 5:
                {
                    int jump = arr[pc + 1];
                    if (acc == 0) {
                        printf("acc==0, jump to address %d\n", jump);
                        pc = jump;
                    } else {
                        printf("acc!=0, continue (jump to %d ignored)\n", jump);
                        pc += 2;
                    }
                }
                break;
                
            default:
                pc += 1;
                break;
        }
    }
    
    printf("\nFinal acc = %d\n", acc);
    return 0;
}