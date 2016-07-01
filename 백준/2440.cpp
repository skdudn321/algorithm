#include<stdio.h>

int main(void){
    int N, i, j;
    scanf("%d", &N);
    for(i = N; i >= 1; i--){
        for(j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}