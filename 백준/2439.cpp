#include<stdio.h>

int main(void){
    int N, i, j;
    scanf("%d", &N);
    for(i = 1; i<= N; i++){
        for(j = 1; j <= N - i; j++){
            printf(" ");
        }
        for(; j<= N; j++){
            printf("*");
        }
        printf("\n");
    }
}