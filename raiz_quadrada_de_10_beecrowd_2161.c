#include <stdio.h>

double fracoes(int num) {
    double res;

    if(num == 0){

        res = 3;

    } else if(num == 1) {

        res = 1.0/6.0;

    } else {
    
        res = 1.0/(6.0 +fracoes(num - 1));

    }

    return res;
}

int main() {

    int num;
    double ans;

    scanf("%d", &num);

    ans = fracoes(num);

    if(num == 0) {

        printf("%.10lf\n", ans);

    } else {

        printf("%.10lf\n", ans + 3);

    }

    return 0;
}