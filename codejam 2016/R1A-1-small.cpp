#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[2000];
char make[3000];
int length;
int cur = 1500;

int main(void) {
	int T;
	int N;
	int i, j, k;

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%s\n", str);
		length = strlen(str);

		make[cur] = str[0];
		
		for (j = 1; j < length; j++) {
			if (str[j] >= make[cur]) {
				make[--cur] = str[j];
			}
			else {
				make[cur + j] = str[j];
			}
		}
		make[cur + j] = 0;

		printf("Case #%d: %s\n", i, make + cur);
	}


}