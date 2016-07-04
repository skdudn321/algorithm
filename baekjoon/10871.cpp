#include<stdio.h>

int bae[20000];

int main(void){
    int N, num, i;
    scanf("%d %d", &N, &num);
    for(i = 0; i < N; i++){
        scanf("%d", &bae[i]);
    }
    for(i = 0; i < N; i++){
        if(bae[i] < num){
            printf("%d ", bae[i]);
        }
    }
}