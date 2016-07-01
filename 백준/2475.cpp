#include<stdio.h>

int main(void){
    int i;
    int temp;
    int sum = 0;
    
    for(i = 0; i < 5; i ++){
        scanf("%d", &temp);
        temp *= temp;
        sum += temp;
    }
    sum %= 10;
    
    printf("%d", sum);
}