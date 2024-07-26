#include <stdio.h>

int main () {

    int i, j, num = 0;
    char operacao;
    double soma = 0.0, media, matriz[12][12];

    scanf("%c", &operacao); // soma ou media
    getchar();

    for(i = 0; i < 12; i++){

        for(j = 0; j < 12; j++){

            scanf("%lf", &matriz[i][j]); // pede os elementos da matriz

            if(j + i < 11){
                soma += matriz[i][j]; // soma os elementos da matriz acima da diagonal sec
                num++;
            }
        }

    }


    if(operacao == 'S'){
        printf("%.1lf\n", soma);
    }else if(operacao == 'M'){
        printf("%.1lf\n", soma/num);
    }


    return 0;
}