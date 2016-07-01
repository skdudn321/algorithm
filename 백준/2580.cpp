#include<stdio.h>

int map[10][10];

bool recursion(int x, int y);
bool sero(int x, int y, int num);
bool garo(int x, int y, int num);
bool squ(int x, int y, int num);

int main(void) {
	int i, j;

	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	recursion(1, 1);

	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			printf("%d", map[i][j]);
			if (j != 9) {
				printf(" ");
			}
		}
		if (i != 9) {
			printf("\n");
		}
	}
}

bool recursion(int x, int y) {
	if (x == 10) {
		return true;
	}
	if (!map[x][y]) {
		for (int i = 1; i <= 9; i++) {
			if (sero(x, y, i) && garo(x, y, i) && squ(x, y, i)) {
				map[x][y] = i;
				if (y == 9) {
					if (recursion(x + 1, 1)) {
						return true;
					}
				}
				else {
					if (recursion(x, y + 1)) {
						return true;
					}
				}
			}
		}
		map[x][y] = 0;
		return false;
	}
	else {
		if (y == 9) {
			if (recursion(x + 1, 1)) {
				return true;
			}
		}
		else {
			if (recursion(x, y + 1)) {
				return true;
			}
		}

		return false;
	}
}

bool sero(int x, int y, int num) {
	for (int i = 1; i <= 9; i++) {
		if (map[x][i] == num) {
			return false;
		}
	}
	return true;
}
bool garo(int x, int y, int num) {
	for (int i = 1; i <= 9; i++) {
		if (map[i][y] == num) {
			return false;
		}
	}
	return true;
}
bool squ(int x, int y, int num) {
	for (int i = ((x - 1) / 3) * 3 + 1; i <= (((x - 1) / 3) + 1) * 3; i++) {
		for (int j = ((y - 1) / 3) * 3 + 1; j <= (((y - 1) / 3) + 1) * 3; j++) {
			if (map[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}