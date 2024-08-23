#include <stdio.h>
#include <stdlib.h>

struct Cavalo {
    char letra;
    int numero;
};

typedef struct Cavalo pos_cavalo;

int main () {

    pos_cavalo inicial, final;
    int dif_letra, dif_num;

    scanf("%c%d %c%d", &inicial.letra, &inicial.numero, &final.letra, &final.numero);

    dif_letra = abs((int)inicial.letra - (int)final.letra); //código ascii
    dif_num = abs(inicial.numero - final.numero);

    if (dif_letra == 2 && dif_num == 1 || dif_letra == 1 && dif_num == 2) {

        printf("VALIDO\n");
    } else {
        
        printf("INVALIDO\n");
    }
    


    return 0;
}