#include<stdio.h>
#include<string.h>

char str[300];

void change(int x, int y){
	if (str[x] >= 'A' && str[x] <= 'Z'){
		str[x] = str[x] - 'A' + 'a';
	}
	if (str[y] >= 'A' && str[y] <= 'Z'){
		str[y] = str[y] - 'A' + 'a';
	}
}

int main(void){
	int N, len;
	int i, j;

	scanf("%d\n", &N);

	for (i = 0; i < N; i++){
		gets(str);
		len = strlen(str);
		for (j = 0; j < len / 2; j++){
			change(j, len - j - 1);
			if (str[j] != str[len - j - 1]){
				printf("No");
				break;
			}
		}
		if (j == len / 2){
			printf("Yes");
		}

		if (i != N - 1){
			printf("\n");
		}
	}
}