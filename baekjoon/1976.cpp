#include<stdio.h>

int group[300];

int find(int x);
void merge(int x, int y);

int main(void) {
	int i, j;
	int N, K;
	int temp;
	int link;

	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++) {
		group[i] = i;
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &temp);
			if (temp) {
				merge(i, j);
			}
		}
	}

	scanf("%d", &link);
	link = find(link);

	for (i = 2; i <= K; i++) {
		scanf("%d", &temp);
		if (link != find(temp)) {
			printf("NO");
			return 0;
		}
	}

	printf("YES");
	return 0;
}

int find(int x) {
	while (group[x] != x) {
		x = group[x];
	}
	return x;
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x > y) {
		group[x] = y;
	}
	if (x < y) {
		group[y] = x;
	}
}