#include <stdio.h>
#include <string.h>
#define max 200000

int main(){

    int n, andares[max], dis, maior; 
    
    scanf("%d", &n);
    scanf("%d", &andares[0]);
    
    maior = 0;

    for(int i = 1; i < n; i++){

        scanf("%d", &andares[i]);

        for (int j=i-1; j >= 0; j--) {

            dis = andares[i] + andares[j] + (i - j);

            if(dis > maior){
                maior = dis;
            }

        }

    }

    printf("%d\n", maior);

 return 0;
}
