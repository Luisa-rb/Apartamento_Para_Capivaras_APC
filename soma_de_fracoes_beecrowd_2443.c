#include <stdio.h>

int main (){

    int a, b, c, d, numerador, denominador;
    int res, menop, i, div1, div2; // a/b & c/d são as fracoes

    scanf("%d %d %d %d", &a, &b, &c, &d);

    numerador = d*a + b*c;
    denominador = b*d;
    res = numerador/denominador;

    if(numerador % denominador == 0){
        printf("%d 1\n", res);
    }else{

        if(numerador < denominador){
            menop = numerador;
        }else{
            menop = denominador;
        }
    
        for(; menop >= 1; menop--){
            if(numerador % menop == 0 && denominador % menop == 0){
                div1 = numerador/menop;
                div2 = denominador/menop;
    
                printf("%d %d\n", div1, div2);
                break;
            }
        }

    }

    return 0;
}
