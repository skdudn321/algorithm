#include<stdio.h>
#define default 20000

int num_of_chu, num_of_ball;
int chu[40];
int weight[40][50000];
int ball[10];

int main(void) {
	int i, j;
	int check = 0;

	weight[0][default] = 1;

	scanf("%d", &num_of_chu);
	for (i = 1; i <= num_of_chu; i++) {
		scanf("%d", &chu[i]);
	}
	scanf("%d", &num_of_ball);
	for (i = 0; i < num_of_ball; i++) {
		scanf("%d", &ball[i]);
	}
	for (i = 1; i <= num_of_chu; i++) {
		check += chu[i];
	}

	for (i = 1; i <= num_of_chu; i++) {
		for (j = 0; j <= 50000; j++) {
			if (weight[i - 1][j] == 1) {
				weight[i][j] = 1;
				weight[i][j + chu[i]] = 1;
				weight[i][j - chu[i]] = 1;
			}
		}
	}

	for (i = 0; i < num_of_ball; i++) {
		if (ball[i] > check) {
			printf("N ");
		}
		else if (weight[num_of_chu][ball[i] + default] == 1) {
			printf("Y ");
		}
		else {
			printf("N ");
		}
	}
	return 0;
}