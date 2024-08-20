#include <stdio.h>
#include <stdlib.h>

void check (int *mags, int *pico, int amostras) {
    // Caso especial com apenas dois pontos

    if (amostras == 2 && mags[0] != mags[1]) {
        
        (*pico) = 2; // Ambos são picos, já que um é o máximo e o outro o mínimo

    } else {
    
        // Verificar picos no meio da sequência
        for (int i = 1; i < amostras - 1; i++) {

            if ((mags[i] > mags[i - 1] && mags[i] > mags[i + 1]) || (mags[i] < mags[i - 1] && mags[i] < mags[i + 1])) {
                (*pico)++;
            }

        }

        // Verificar o pico entre o último e o primeiro
        if ((mags[0] > mags[amostras - 1] && mags[0] > mags[1]) || (mags[0] < mags[amostras - 1] && mags[0] < mags[1])) {
            (*pico)++;
        }

        // Verificar o pico entre o penúltimo e o último
        if ((mags[amostras - 1] > mags[amostras - 2] && mags[amostras - 1] > mags[0]) || (mags[amostras - 1] < mags[amostras - 2] && mags[amostras - 1] < mags[0])) {
            (*pico)++;
        }
    }
}

int main() {
    int amostras, pico;
    int *mags;

    while (1) {
        pico = 0;
        
        scanf("%d", &amostras);

        if (amostras == 0) {
            break;
        }

        // Alocação dinâmica para as amostras
        mags = (int *)malloc(amostras * sizeof(int));
        
        for (int i = 0; i < amostras; i++) {
            scanf("%d", &mags[i]);
        }

        // Verificação dos picos
        check(mags, &pico, amostras);

        printf("%d\n", pico);

        free(mags);
    }

    return 0;
}
