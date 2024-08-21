#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_pontos_cardeais (int count_d, int count_e, int diferenca) {

    if(diferenca % 4 == 0) {

            printf("N\n");

        } else if (count_e > count_d) {

            if (diferenca % 4 == 1) {
                printf("O\n");
            } else if (diferenca % 4 == 2) {
                printf("S\n");
            } else if (diferenca % 4 == 3) {
                printf("L\n");
            }
        } else if (count_e < count_d) {

            if (diferenca % 4 == 1) {
                printf("L\n");
            } else if (diferenca % 4 == 2) {
                printf("S\n");
            } else if (diferenca % 4 == 3) {
                printf("O\n");
            }
        }

}

int main () {

    char *instrucoes;
    int comandos, i, count_d, count_e, diferenca;

    while (1) {

        count_d = 0;
        count_e = 0;
        diferenca = 0;

        scanf ("%d", &comandos);

        if (comandos == 0) {
            break;
        }

        instrucoes = (char *) malloc (comandos * sizeof(char));

        scanf ("%s", instrucoes);

        for (i = 0; i < comandos; i++) {
            
            if (instrucoes[i] == 'D') {
                count_d++;
            } else if (instrucoes[i] == 'E') {
                count_e++;
            }
        }

        diferenca = abs(count_d - count_e);

        print_pontos_cardeais(count_d, count_e, diferenca);

        free(instrucoes);
 
    }


    return 0;
}