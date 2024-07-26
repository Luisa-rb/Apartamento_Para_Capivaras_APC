#include <stdio.h>

int main(){

    int n, c, p;
    double totut = 0.0, uti;

    scanf("%d", &n); //numero de operacoes a serem realizados

    for (int i = 0; i < n; i++){

        scanf("%d %d", &c, &p); //custo computacional = c, periodo = p
        
        uti = (double) c/p; //divisao com double pra pegar a parte decimal
        totut += uti; //guarda em totut o valor da utilizacao e vai somando

    }
    
    if (totut <= 1.0){ 
        /* se o total de utilizacao for menor 
        ou igual a 1, eh ok o processo de EDF */
        printf("OK\n");
    } else {
        /* se nao, fail */
        printf("FAIL\n");
    }
    
    return 0;

}
