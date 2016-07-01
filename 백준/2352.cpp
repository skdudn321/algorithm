#include<stdio.h>

#define oo 1000000000

int ban[40010];

int main(void) {
	int n;
	int temp;
	int i, j;

	for (i = 1; i < 40001; i++) {
		ban[i] = oo;
	}

	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &temp);
		for (j = 1; ; j++) {
			if (ban[j] > temp) {
				ban[j] = temp;
				break;
			}
		}
	}

	for (i = 1; ; i++) {
		if (ban[i] == oo) {
			break;
		}
	}

	printf("%d", i - 1);
}