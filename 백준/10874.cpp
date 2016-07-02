#include<stdio.h>
#include<string.h>

int main(void) {
	char str1[] = "1 2 3 4 5 1 2 3 4 5\n";
	int N, i;
	char str2[100];

	scanf("%d\n", &N);
	for (i = 0; i < N; i++) {
		fgets(str2, 100, stdin);
		if (strcmp(str1, str2) == 0) {
			printf("%d\n", i + 1);
		}
	}
}