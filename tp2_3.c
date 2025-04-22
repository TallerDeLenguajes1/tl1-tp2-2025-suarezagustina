#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main(){

    int mt[N][M];

    srand(time(NULL));
//Usando Aritmetica de punteros:
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            *(*(mt + i) + j) = 1 + rand() % 100;         
            printf("%d ", *(*(mt + i) + j)); 
        }
        printf("\n");
    }

    return 0;
}