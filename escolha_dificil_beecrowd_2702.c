#include <stdio.h>

int main () {

    int frango, bife, massa;
    int pedido_f, pedido_b, pedido_m;
    int dif_f, dif_b, dif_m, total; 

    total = 0;

    scanf("%d %d %d", &frango, &bife, &massa);
    scanf("%d %d %d", &pedido_f, &pedido_b, &pedido_m);

    dif_f = frango - pedido_f;
    dif_b = bife - pedido_b;
    dif_m = massa - pedido_m;

    if (dif_f < 0) {

        dif_f *= -1;
        total += dif_f;
    }

    if (dif_b < 0) {

        dif_b *= -1;
        total += dif_b;
    }

    if (dif_m < 0) {

        dif_m *= -1;
        total += dif_m;
    }

    printf("%d\n", total);

    return 0;
}