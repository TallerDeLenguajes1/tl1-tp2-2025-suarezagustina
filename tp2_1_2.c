#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main()
{

    int i;
    double vt[N], *p_vt;
    srand(time(NULL));
    p_vt = vt;
    //Uso la aritmetica de punteros para recorrer el vector
    for (i = 0; i < N; i++)
    {
        *p_vt = 1 + rand() % 100;
        printf("%f\n", *p_vt++);
    }

    return 0;
}