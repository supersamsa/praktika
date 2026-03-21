#include "myarrfunc.h"

/*
a. Задать размер массива.
b. Заполнить массив
c. Представление массива (значения, адреса) 
массива
d. Определить количество элементов массива по значению выше введенного k.
e. Поиск индекса последнего положительного элемента массива;
f. Вычислить  индексы элементов значение которых выше среднего значения 
g. Выход
*/

void createArray(int **arr, int *len){
    printf("lenth \n");
    scanf("%d", len);
       if(*len <= 0){
        printf("errororrrr \n");
        return;
    }
    if(*arr != NULL){
      free(*arr);
    }
    *arr = (int*)malloc(*len * sizeof(int));
}

int fillArray(int *arr, int len){
     
    printf("заполнить масив \n");
    int result = 0;
    if((len) != 0){
        for(int i = 0; i < len; i++){
            scanf("%d", &arr[i]);
        }
    }else{
        result = -1;
    }
        return result;
}

void printArray(int *arr, int len){
    for(int i = 0; i < len; i++){
        printf("%6d | %8d | %p\n", i, arr[i], (void*)&arr[i]);
    }
}

void findAboveAverageIndices(int *arr,int len){
     if(arr == NULL || len <= 0){
        printf("errororrrr \n");
        return;
    }
    
    double sum = 0;
    for(int i = 0; i < len; i++){
        sum += arr[i];
    }
    double average = sum / len;
    
    printf("Среднее значение: %.2f\n", average);
    
    int found = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] > average){
            printf("%d ", i);
            found = 1;
        }
    }
    
    if(!found){
        printf("не найдены");
    }
    printf("\n");
}
int countAboveValue(int *arr, int len, int k){
    int result = 0;
       if(arr == NULL || len <= 0){
        printf("errororrrr \n");
        return -1;  }
    for(int i = 0; i < len; i++){
        if(arr[i]> k)
            result++;
    }
    return result;
}
int findLastPositiveIndex(int *arr, int len){
       if(arr == NULL || len <= 0){
        printf("errororrrr \n");
        return -1;
    }
    int result = -1;

    for(int i = len-1; i>=0; i--){
        if(arr[i]>0){
            return i;
        }
    }
    
    return result;
}