#include<stdio.h>

int main(void){
	int A, B, C;
	int answer;

	scanf("%d %d %d", &A, &B, &C);

	answer = (B - A) > (C - B) ? (B - A) : (C - B);

	printf("%d", answer - 1);
}