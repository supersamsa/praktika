#include "myarrfunc.h" 

int main(){
    char c = ' ';
    int len = 0;
    int *arr = NULL;  
    while(c != 'g'){
           printf("a. Задать размер массива.\nb. Заполнить массив\nc. Представление массива (значения, адреса) массива\nd. Определить количество элементов массива по значению выше введенного k.\ne. Поиск индекса последнего положительного элемента массива;\nf. Вычислить индексы элементов значение которых выше среднего значения \ng.  Выход\n  ");
            scanf(" %c", &c);
           switch (c)
           {
           case 'a':
                createArray(&arr, &len);
               break;
           case 'b':
                fillArray(arr, len);
                break;
           case 'p':
                printArray(arr, len);
                break; 
            case 'c':
                printArray(arr, len);
                break;    
            case 'd': {
                if(arr == NULL || len <= 0){
                    printf("erroror\n");
                    break;
                }
                int k;
                scanf("%d", &k);
                int count = countAboveValue(arr, len, k);
                if(count==0){
                    printf("none\n");
                }else{
                    printf("%d\n", count);
                }
                break;
            }
                
            case 'e': {
                if(arr == NULL || len <= 0){
                    printf("errroror\n");
                    break;
                }
                int index = findLastPositiveIndex(arr, len);
                if(index != -1){
                    printf("%d\n", index);
                } else {
                    printf("none\n");
                }
                break;
            }
                
            case 'f':
                findAboveAverageIndices(arr, len);
                break;
                
            case 'g':
                if(arr != NULL){
                    free(arr);
                }
                break;
                       
           default:
               break;
           }
       }
    
    return 0;
}

//gcc -Wall -Wextra -std=c99 -o program main.c myarrfunc.c