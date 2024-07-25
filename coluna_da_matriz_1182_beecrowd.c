#include <stdio.h>

int main(){

    int coluna;
    double matriz[12][12], soma, media;
    char operacao;

    scanf("%d", &coluna);
    getchar();
    scanf("%c", &operacao);

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    media = 0;
    soma = 0;

    for(int j = 0; j < 12; j++){
        soma += matriz[j][coluna];
    }

    if(operacao == 'S'){
        printf("%.1lf\n", soma);
    }else if(operacao == 'M'){
        media = soma/12;
        printf("%.1lf\n", media);
    }


    return 0;
}