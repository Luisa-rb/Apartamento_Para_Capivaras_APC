#include <stdio.h>
#include <string.h>

struct Camisetas {
    char cor[9];  // Cor pode ter até 8 caracteres (VERMELHO + \0) + 1 terminador nulo
    char tam;
    char nome[101];  // Nome pode ter até 100 caracteres + 1 terminador nulo
};

typedef struct Camisetas camisetas;

void troca(camisetas info_cliente[200], int a, int b) {

    camisetas aux;

    // Troca a cor
    strcpy(aux.cor, info_cliente[a].cor);
    strcpy(info_cliente[a].cor, info_cliente[b].cor);
    strcpy(info_cliente[b].cor, aux.cor);

    // Troca o tamanho
    aux.tam = info_cliente[a].tam;
    info_cliente[a].tam = info_cliente[b].tam;
    info_cliente[b].tam = aux.tam;

    // Troca o nome
    strcpy(aux.nome, info_cliente[a].nome);
    strcpy(info_cliente[a].nome, info_cliente[b].nome);
    strcpy(info_cliente[b].nome, aux.nome);

}

void ordena_cor (camisetas info_cliente[200], int qtd_clientes) {

    int i, j;

    for(i = 0; i < qtd_clientes - 1; i++) {
        for(j = i + 1; j < qtd_clientes; j++) {

            // 0 para verificar se a cor e "vermelho" ou "branco" sao iguais à info_cliente.cor
            if(strcmp(info_cliente[i].cor, "vermelho") == 0 && strcmp(info_cliente[j].cor, "branco") == 0) { 

                troca(info_cliente, i, j); 

            }

        }

    }

}

void ordena_tamanho(camisetas info_cliente[200], int qtd_clientes) {

    int i, j;

    for(i = 0; i < qtd_clientes - 1; i++){
        for(j = i + 1; j < qtd_clientes; j++) {

            if (strcmp(info_cliente[i].cor, info_cliente[j].cor) == 0) {

                if ( info_cliente[i].tam == 'G' && info_cliente[j].tam == 'M' ) {

                    troca(info_cliente, i, j);

                } else if ( info_cliente[i].tam == 'M' && info_cliente[j].tam == 'P' ) {

                    troca(info_cliente, i, j);

                } else if ( info_cliente[i].tam == 'G' && info_cliente[j].tam == 'P' ) {

                    troca(info_cliente, i, j);

                }

            }
        }

    }

}

int main() {

    camisetas info_cliente[200];
    int qtd_clientes, i, j, k;
    count = 1;

    while(1) {

        scanf("%d", &qtd_clientes);

        if(qtd_clientes == 0) {

            break;
        }

        if (count == 0) { 
            printf("\n");
        }

        count = 0;

        for(k = 0; k < qtd_clientes; k++) {

            getchar();
            scanf("%[^\n]s", info_cliente[k].nome);
            getchar();
            scanf("%s %c", info_cliente[k].cor, &info_cliente[k].tam);

        }

        ordena_cor(info_cliente, qtd_clientes);

        ordena_tamanho(info_cliente, qtd_clientes);

        for(i = 0; i < qtd_clientes - 1; i++) {
            for(j = i + 1; j < qtd_clientes; j++) {

                if(strcmp(info_cliente[i].nome, info_cliente[j].nome) > 0 && strcmp(info_cliente[i].cor, info_cliente[j].cor) == 0 && info_cliente[i].tam == info_cliente[j].tam) {
                    troca(info_cliente, i, j);
                }

            }

        }

        for (k = 0; k < qtd_clientes; k++) {

            printf("%s %c %s\n", info_cliente[k].cor, info_cliente[k].tam, info_cliente[k].nome);
            
        }
    }
    
    return 0;
}
