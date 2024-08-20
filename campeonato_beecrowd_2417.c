#include <stdio.h>

struct Time {
    int vitorias;
    int empates;
    int saldo;
};

typedef struct Time time;

void check_print (time cor, time fla, int *pontos_f, int *pontos_c) {

    (*pontos_f) = fla.vitorias * 3 + fla.empates;
    (*pontos_c) = cor.vitorias * 3 + cor.empates;

    if ((*pontos_c) > (*pontos_f)) {
        printf("C\n");
    } else if ((*pontos_f) > (*pontos_c)) {
        printf("F\n");
    } else {

        if (cor.saldo == fla.saldo) {
            printf("=\n");
        } else if (cor.saldo > fla.saldo) {
            printf("C\n");
        } else {
            printf("F\n");
        }
    
    }

}

int main () {

    time cor, fla;
    int pontos_c, pontos_f, i;
    pontos_c = 0;
    pontos_f = 0;

    scanf("%d %d %d %d %d %d", &cor.vitorias, &cor.empates, &cor.saldo, &fla.vitorias, &fla.empates, &fla.saldo);

    check_print(cor, fla, &pontos_f, &pontos_c);

    return 0;
}