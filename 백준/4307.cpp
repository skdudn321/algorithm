#include<stdio.h>

int main(void) {
	int N;
	int length, count;
	int i, j;
	int temp;
	int max, min;
	int pivot;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &length, &count);
		min = 0;
		max = 0;
		pivot = length / 2;

		for (j = 0; j < count; j++) {
			scanf("%d", &temp);
			if (temp > pivot) {
				if (length - temp > min) {
					min = length - temp;
				}
				if (temp > max) {
					max = temp;
				}
			}
			else {
				if (temp > min) {
					min = temp;
				}
				if (length - temp > max) {
					max = length - temp;
				}
			}
		}
		printf("%d %d\n", min, max);
	}
}