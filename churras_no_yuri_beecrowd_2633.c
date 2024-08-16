#include <stdio.h>
#include <string.h>

struct Churras {

    char corte[21]; 
    int val;
    
};

typedef struct Churras churras; //definindo a struct como um tipo

void troca(churras barb[25], int a, int b, char dest[25]) {

    churras aux[25];

    aux[a].val = barb[a].val;
    barb[a].val = barb[b].val;
    barb[b].val = aux[a].val;
    //troca os valores 

    strcpy(dest, barb[a].corte);
    strcpy(barb[a].corte, barb[b].corte);
    strcpy(barb[b].corte, dest);
    //troca os nomes também
    //fazer dest = barb[a].corte é errado! tem que usar a strcpy

}

void imprime_cortes(churras barb[25], int num, int i) {

    printf("%s", barb[0].corte); 

    for(i = 1; i < num - 1; i++) {

        printf(" %s", barb[i].corte);

    }
        
    printf(" %s\n", barb[num - 1].corte);

    //organizacao da funcao de acordo com os padroes do beecrowd (um espaco entre cada palavra e o \n ao final)

}

int main() {

    int num, i, j, k; //num = numero de cortes
    char dest[25]; //vetor auxiliar pra usar na funcao troca
    churras barb[25]; //barb = "barbecue", é o vetor que corresponde aos dados da struct;


    while(scanf("%d", &num) != EOF){

        for(i = 0; i < num; i++){

            scanf("%s %d", barb[i].corte, &barb[i].val);
            getchar(); //se livra dos \n

        }

        for(i = 0; i < num - 1; i++){
            for(j = i + 1; j < num; j++){

                if(barb[i].val > barb[j].val){

                    //se a validade do i[0] for maior do que a [1], então troca. Por exemplo
                    
                    troca(barb, i, j, dest); 

                }
            }

        }

        imprime_cortes(barb, num, i); 
        //faz a impressao de acordo com os padroes beecrowd já com os cortes ordenados de acordo com a data de validade

    }


    return 0;
}