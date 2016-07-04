#include<stdio.h>
#include<string.h>

char str[5][20];

int main(void){
	int len[5];
	int i, j;

	for (i = 0; i < 5; i++){
		scanf("%s\n", str[i]);
		len[i] = strlen(str[i]);
	}

	for (i = 0; i < 15; i++){
		for (j = 0; j < 5; j++){
			if (len[j] > i){
				printf("%c", str[j][i]);
			}
		}
	}
}