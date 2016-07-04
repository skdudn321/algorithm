#include<stdio.h>

int main(void) {
	int N, i, sum = 0;
	scanf("%d", &N);
    for(i = 1; i <= N; i++){
        sum += i;
    }
    printf("%d\n", sum);
}