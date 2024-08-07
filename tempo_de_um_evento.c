#include <stdio.h>

int main(){

    int hi, mi, si, hf, mf, sf, diia, difa;
    int total_segundos_i, total_segundos_f, evento;
    int resd, resh, resm, ress, aux1, aux2;

    scanf("Dia %d\n", &diia);
    scanf("%d : %d : %d\n", &hi, &mi, &si);
    scanf("Dia %d\n", &difa);
    scanf("%d : %d : %d\n", &hf, &mf, &sf);

    total_segundos_i = diia*86400 + hi*3600 + mi*60 + si;
    total_segundos_f = difa*86400 + hf*3600 + mf*60 + sf;
    evento = total_segundos_f - total_segundos_i;

    resd = evento/86400;
    aux1 = evento % 86400;
    resh = aux1/3600;
    aux2 = aux1 % 3600;
    resm = aux2/60;
    ress = aux2 % 60;


    printf("%d dia(s)\n", resd);
    printf("%d hora(s)\n", resh);
    printf("%d minuto(s)\n", resm);
    printf("%d segundo(s)\n", ress);
    


    return 0;
}