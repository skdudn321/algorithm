#include<stdio.h>

int main(void) {
	int n, temp;
	int i;
	int num[3];
	int answer = 0;

	scanf("%d", &n);

	if (n < 100) {
		answer = n;
	}
	else {
		answer += 99;
		temp = n / 100;
		answer += (temp - 1) * 5;
		for (i = 100 * temp; i <= n; i++) {
			num[2] = i / 100;
			num[1] = (i % 100) / 10;
			num[0] = i % 10;
			if (num[2] - num[1] == num[1] - num[0]) {
				answer++;
			}
		}
	}

	printf("%d", answer);
}