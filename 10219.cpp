#include<stdio.h>

char graph[20][20];

int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int w, h;
		scanf("%d %d", &w, &h);
		getchar();
		for (int j = 1; j <= w; j++) {
			gets(graph[j]);
		}
		for (int j = 1; j <= w; j++) {
			for (int k = h - 1; k >= 0; k--) {
				printf("%c", graph[j][k]);
			}
			printf("\n");
		}
	}
}