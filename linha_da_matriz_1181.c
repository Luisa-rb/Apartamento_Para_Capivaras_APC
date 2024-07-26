#include <stdio.h>

int main(){

    int linha;
    double matriz[12][12], soma, media;
    char operacao;

    scanf("%d", &linha);
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
        soma += matriz[linha][j];
    }

    if(operacao == 'S'){
        printf("%.1lf\n", soma);
    }else if(operacao == 'M'){
        media = soma/12;
        printf("%.1lf\n", media);
    }


    return 0;
}

/*
#include <stdio.h>

int main(){

    int linha;
    double matriz[12][12], soma, media;
    char operacao[3];

    scanf("%d", &linha);
    scanf("%s", operacao);

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; i++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int j = 0; j < 12; j++){

        if(operacao == 'S'){
            soma += matriz[linha][j];
            printf("%.1lf\n", soma);
        }else if(operacao == 'M'){
            media = matriz[linha][j]/12;
            printf("%.1lf\n", media);
        }
    }


    return 0;
}
*/