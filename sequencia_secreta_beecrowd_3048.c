#include <stdio.h>
#define max 501

int main(){

    int n, seq[max], count;

    scanf("%d", &n);
    scanf("%d", &seq[0]);

    count = 1;

    for(int i = 1; i < n; i++){
        scanf("%d", &seq[i]);

        if(seq[i] != seq[i - 1]){
            count++;
        }
    }

    printf("%d\n", count);


    return 0;
}