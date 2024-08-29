#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct produto {

    char nome[101];
    int qtd;
    double precoUnitario;
};


typedef struct produto produtos;

int achaIndice (produtos carrinho[2000], int *num, char nome[101]) {

    for (int i = 0; i < (*num); i++) {
        if (strcmp(nome, carrinho[i].nome) == 0) {
            return i;
        }
    }

    printf("ERRO: O produto %s nao esta no carrinho\n", nome);
    return -1;

}

void ordemAlfabetica (produtos carrinho[2000], int *num) {

    int i, j;
    produtos aux;

    for (i = 0 ; i < (*num) - 1; i++) {

        for (j = i + 1; j < (*num); j++) {

            if (strcmp(carrinho[i].nome, carrinho[j].nome) > 0) {

                aux = carrinho[i];
                carrinho[i] = carrinho[j];
                carrinho[j] = aux;

            }

        }

    }
   
}

double calcularTotal (produtos carrinho[2000], int *num ) {

    double total = 0.0;

    for (int i = 0 ; i < (*num) ; i++) {
        total += carrinho[i].precoUnitario * carrinho[i].qtd;
    }

    return total;
}

void comparaOrcamento(produtos carrinho[2000], int *num, double orcamentoTotal) { 

    double total = calcularTotal(carrinho, num);

    while (total > orcamentoTotal && *num > 0) {

        if (carrinho[*num - 1].qtd > 0) {
            carrinho[*num - 1].qtd--;
            total -= carrinho[*num - 1].precoUnitario;
        }

        if (carrinho[*num - 1].qtd <= 0) {
            (*num)--;
        }
    }
    
}

void comprar(produtos carrinho[2000], int *num, double orcamentoTotal) {

    char nome[101];
    int qtd;
    double precoUnt;

    scanf("%s %lf %d", nome, &precoUnt, &qtd);
    getchar();

    if (qtd <= 0) {return;}

    if (precoUnt > orcamentoTotal) {return;}


    for (int i = 0 ; i < (*num) ; i++) {

        if (strcmp(nome, carrinho[i].nome) == 0) { // se já tiver itens do carrinho que queiram ser comprados novamente
            carrinho[i].qtd += qtd;
            comparaOrcamento(carrinho, num, orcamentoTotal);
            return; 
        }

    }

    strcpy(carrinho[*num].nome, nome);
    carrinho[*num].qtd = qtd;
    carrinho[*num].precoUnitario =  precoUnt;

    (*num)++;

    comparaOrcamento(carrinho, num, orcamentoTotal);

}

void remover(produtos carrinho[2000], int *num, double orcamentoTotal) {

    char nome[101];
    int qtdRemover, sobra;  

    scanf("%s %d", nome, &qtdRemover);
    getchar();

    if (qtdRemover <= 0) {return;}

    int idx = achaIndice(carrinho, num, nome);

    if (idx == -1) {
        return;
    }

    sobra  = carrinho[idx].qtd - qtdRemover;

    if (sobra > 0) {

        carrinho[idx].qtd = sobra;
        comparaOrcamento(carrinho, num, orcamentoTotal);

    } else { // se a sobra for <= 0, tira o produto todo do carrinho

        for (int j = idx; j < (*num) - 1; j++) {
            carrinho[j] = carrinho[j + 1];
        }

        (*num)--;
    } 

}

void atualizar(produtos carrinho[2000], int *num, double orcamentoTotal) {

    char nome[101];
    double precoAtualizado;
    produtos aux;

    scanf("%s %lf", nome, &precoAtualizado);
    getchar();

    // verificar se o produto existe no carrinho 

    int idx = achaIndice(carrinho, num, nome);

    if (idx == -1) {
        return;
    }

    if (idx == (*num) - 1) {

        carrinho[idx].precoUnitario = precoAtualizado;

        // calcula o total de novo agora já tendo feito as modificacoes
        double total = calcularTotal(carrinho, num);
        while (total > orcamentoTotal && *num > 0) {
            if (carrinho[idx].qtd > 0) {
                carrinho[idx].qtd--;
                total -= carrinho[idx].precoUnitario;
            }

            if (carrinho[idx].qtd <= 0) {
                (*num)--;
            }
        }

    } else {

        carrinho[idx].precoUnitario = 0;
        aux.qtd = carrinho[idx].qtd;
        carrinho[idx].qtd = 0;

        comparaOrcamento(carrinho, num, orcamentoTotal);

        (*num)++;

        // recolocando o novo valor no ultimo indice do array
        strcpy(carrinho[*num - 1].nome, nome);
        carrinho[*num - 1].qtd = aux.qtd;
        carrinho[*num - 1].precoUnitario =  precoAtualizado;

        comparaOrcamento(carrinho, num, orcamentoTotal);

    }

}

void mostrar(produtos carrinho[2000], int *num) {
    ordemAlfabetica(carrinho, num);

    double total = 0.0;

    for (int i = 0; i < (*num); i++) {

        if (carrinho[i].qtd != 0) {
            
            printf("%s %d x %.2lf = %.2lf\n",
            carrinho[i].nome, carrinho[i].qtd, carrinho[i].precoUnitario,
            carrinho[i].precoUnitario * carrinho[i].qtd);

            total += carrinho[i].precoUnitario * carrinho[i].qtd;
        }
    }

    printf("TOTAL: %.2lf\n", total);
}

int main() {

    produtos carrinho[2000];
    double orcamentoTotal, orcamentoDisponivel;
    int qtdOperacoes, num = 0;
    char operacao;

    scanf("%d %lf", &qtdOperacoes, &orcamentoTotal);
    getchar();

    for (int j = 0; j < qtdOperacoes; j++) {

        scanf("%c", &operacao);
        getchar();


        if (operacao == 'C') {

            comprar(carrinho, &num, orcamentoTotal);

        } else if (operacao == 'R') {

            remover(carrinho, &num, orcamentoTotal);

        } else if (operacao == 'A') {

            atualizar(carrinho, &num, orcamentoTotal);

        } else if (operacao == 'M') {

            mostrar(carrinho, &num);
        } 
    

    }

}