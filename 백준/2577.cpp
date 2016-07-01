#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[20];
int check[10];

int main(void){
	int A, B, C, temp, len;

	scanf("%d %d %d", &A, &B, &C);

	temp = A * B * C;

	sprintf(str, "%d", temp);

	len = strlen(str);
	for (int i = 0; i < len; i++){
		check[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++){
		printf("%d\n", check[i]);
	}
}