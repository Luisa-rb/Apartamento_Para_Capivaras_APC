#include <stdio.h>

int main (){

    int n, i, j, mat[71][71], meio;

    while ( scanf("%d", &n) != EOF ) {

        meio = n/2; 

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                if(n % 2 != 0){ // se for impar, o elemento do meio é 2
                    if(j == i && j != meio && i != meio){

                        mat[i][j] = 1;

                    }else if(i + j == n - 1){ //diagonal secundaria toda de 2

                        mat[i][j] = 2;

                    }else{

                        mat[i][j] = 3; // o resto eh tudo 3

                    }
                }else{ // se for par, nao tem elemento que fique exatamente no meio
                    if(j == i){

                        mat[i][j] = 1;

                    }else if(i + j == n - 1){ //diagonal secundaria toda de 2

                        mat[i][j] = 2;

                    }else{

                        mat[i][j] = 3; // o resto eh tudo 3

                    }
                }

                printf("%d", mat[i][j]);

            }

            printf("\n"); // quebra de linha a cada linha da matriz

        }
                
                
        meio = 0; // zera o meio pra ser usado dps de novo

    }


    return 0;
}