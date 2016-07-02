#include<stdio.h>

int map[10][10];
int N;

bool recursion(int x, int y);
bool sero(void);
bool garo(void);
bool squ(void);

int main(void) {
	int i, j, k;

	scanf("%d", &N);

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= 9; i++) {
			for (j = 1; j <= 9; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		if (sero() && garo() && squ()) {
			printf("Case %d: CORRECT\n", k);
		}
		else {
			printf("Case %d: INCORRECT\n", k);
		}
	}
}

bool sero(void) {
	int num[10];
	
	for (int j = 1; j <= 9; j++) {

		for (int i = 1; i <= 9; i++) {
			num[i] = 0;
		}

		for (int i = 1; i <= 9; i++) {
			if (num[map[j][i]]) {
				return false;
			}
			else {
				num[map[j][i]] = 1;
			}
		}
	}

	return true;
}
bool garo(void) {
	int num[10];

	for (int j = 1; j <= 9; j++) {

		for (int i = 1; i <= 9; i++) {
			num[i] = 0;
		}

		for (int i = 1; i <= 9; i++) {
			if (num[map[i][j]]) {
				return false;
			}
			else {
				num[map[i][j]] = 1;
			}
		}
	}

	return true;
}
bool squ(void) {
	int num[10];

	for (int x = 1; x < 9; x += 3) {
		for (int y = 1; y < 9; y += 3) {
			for (int i = 1; i <= 9; i++) {
				num[i] = 0;
			}
			for (int i = ((x - 1) / 3) * 3 + 1; i <= (((x - 1) / 3) + 1) * 3; i++) {
				for (int j = ((y - 1) / 3) * 3 + 1; j <= (((y - 1) / 3) + 1) * 3; j++) {
					if (num[map[i][j]]) {
						return false;
					}
					else {
						num[map[i][j]] = 1;
					}
				}
			}
		}
	}
	return true;
}