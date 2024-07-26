#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b, c, d, soma1, soma2, dif;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    soma1 = a + d;
    soma2 = b + c;
    dif = abs(soma1 - soma2);

    printf("%d\n", dif);

    return 0;
}