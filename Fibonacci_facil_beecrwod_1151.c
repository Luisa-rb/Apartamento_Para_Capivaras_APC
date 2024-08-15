#include <stdio.h>

int main(){

    int num, fib[47], fib_ant1 = 0, fib_ant2 = 0, i;

    scanf ("%d", &num);

    if(num == 1) {
        printf("0\n");
    } else if (num == 2) {
        printf("0 1\n");
    } else {

        fib[0] = 0;
        fib[1] = 1;

        printf("%d %d ", fib[0], fib[1]);

        for(i = 2; i < num; i++){

            fib_ant1 = fib[i - 1];
            fib_ant2 = fib[i - 2];

            fib[i] = fib_ant1 + fib_ant2;

            printf("%d ", fib[i]);

        }

        printf("\n");

    }

    return 0;
}