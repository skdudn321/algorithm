#include<stdio.h>
#include<string.h>

char str1[3000];
char str2[3000];
char str3[3000];

int main(void){
	int N;
	int index1, index2;

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++){
		scanf("%c\n", &str1[i]);
		str2[N - i - 1] = str1[i];
	}

	index1 = 0;
	index2 = 0;
	for (int i = 0; i < N; i++){
		int j = strncmp(str1 + index1, str2 + index2, N - i);
		if (j > 0){
			str3[i] = str2[index2];
			index2++;
		}
		else if (j < 0){
			str3[i] = str1[index1];
			index1++;
		}
		else{
			str3[i] = str1[index1];
			index1++;
		}
	}
	str3[N] = 0;

	for (int i = 0; i < N; i++){
		if (i % 80 == 0 && i != 0){
			printf("\n");
		}
		printf("%c", str3[i]);
	}
}