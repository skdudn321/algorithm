#include<stdio.h>

int find(int num);
void merge(int x, int y);

int group[101];

int main(void) {
	int N, K;
	int temp1, temp2;
	int sum = 0;

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		group[i] = i;
	}

	for (int i = 1; i <= K; i++) {
		scanf("%d %d", &temp1, &temp2);
		merge(temp1, temp2);
	}

	for (int i = 1; i <= N; i++) {
		if (find(i) == 1) {
			sum++;
		}
	}

	printf("%d", sum - 1);
}

int find(int num) {
	while (group[num] != num) {
		num = group[num];
	}
	return num;
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x < y) {
		group[y] = x;
	}
	else {
		group[x] = y;
	}
}