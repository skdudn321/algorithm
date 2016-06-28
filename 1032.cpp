#include<stdio.h>
#include<string.h>

char str[100][100];

int main(void) {
	int N, len;
	int i, j;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s\n", str[i]);
	}

	len = strlen(str[0]);

	for (i = 0; i < len; i++) {
		for (j = 1; j < N; j++) {
			if (str[j][i] != str[0][i]) {
				printf("?");
				break;
			}
		}
		if (j == N) {
			printf("%c", str[0][i]);
		}
	}
}