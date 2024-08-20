#include <stdio.h>
#include <string.h>

struct Crianca {
    char n;
    char nome[21]; // 20 caracteres + o \0
};

typedef struct Crianca children;

void comportamento (int *bons, int *ruins, children crianca[101], int qtd_nomes) {
    int i;

    for (i = 0; i < qtd_nomes; i++) {

        if (crianca[i].n == '+') {
            (*bons)++;
        } else if (crianca[i].n == '-') {
            (*ruins)++;
        }

    }

}

void ordem_alfabetica (children crianca[101], int i, int j, int qtd_nomes) {
    
    children aux[101];

    for (i = 0; i < qtd_nomes - 1; i++) {
        for(j = i + 1; j < qtd_nomes; j++) {

            if (strcmp(crianca[i].nome, crianca[j].nome) > 0) {

            // troca
            strcpy (aux[i].nome, crianca[i].nome);
            strcpy (crianca[i].nome, crianca[j].nome);
            strcpy (crianca[j].nome, aux[i].nome);

            }
        }
    }


}

int main () {

    children crianca[101];
    int qtd_nomes, bons, ruins, i, j;

    bons = 0;
    ruins = 0;

    scanf("%d", &qtd_nomes);

    for (i = 0; i < qtd_nomes; i++) {

        getchar();
        scanf("%c %s", &crianca[i].n, crianca[i].nome);
        
    }

    comportamento (&bons, &ruins, crianca, qtd_nomes);

    ordem_alfabetica(crianca, i, j, qtd_nomes);

    for (i = 0; i < qtd_nomes; i++) {
        printf("%s\n", crianca[i].nome);
    }

    printf("Se comportaram: %d | Nao se comportaram: %d\n", bons, ruins);

}