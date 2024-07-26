#include <stdio.h>
#include <string.h>

int main(){

    char ali[11], vert[13], tipo[9];

    scanf("%s", vert);
    scanf("%s", tipo);
    scanf("%s", ali);

    if(!strcmp (vert, "vertebrado")){
        if(!strcmp (tipo, "ave")){
            if(!strcmp (ali, "carnivoro")){
                printf("aguia\n");
            }else{
                printf("pomba\n");
            }
        }else{
            if(!strcmp (ali, "onivoro")){
                printf("homem\n");
            }else{
                printf("vaca\n");
            }
        }
    }else{
        if(!strcmp (tipo, "inseto")){
            if(!strcmp (ali, "hematofago")){
                printf("pulga\n");
            }else{
                printf("lagarta\n");
            }
        }else{
            if(!strcmp (ali, "hematofago")){
                printf("sanguessuga\n");
            }else{
                printf("minhoca\n");
            }
        }
    }


    return 0;
}