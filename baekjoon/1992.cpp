#include<stdio.h>
#include<string.h>

int recursion(int size, int x, int y);

char base[64][64];
char buf[10000];

int main(void) {
	int num;
	int i, j;

	scanf("%d", &num);
	getchar();
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			base[i][j] = getchar();
		}
		getchar();
	}
	buf[0] = 0;
	recursion(num, 0, 0);
	printf("%s", buf);

	return 0;
}

int recursion(int size, int x, int y) {
	int lu, ru, ld, rd, length;
	if (size == 1) {
		length = strlen(buf);
		buf[length] = base[x][y];
		buf[length + 1] = 0;
		return base[x][y] - '0';
	}
	length = strlen(buf);
	buf[length] = '(';
	buf[length + 1] = 0;

	lu = recursion(size / 2, x, y);
	ru = recursion(size / 2, x, y + size / 2);
	ld = recursion(size / 2, x + size / 2, y);
	rd = recursion(size / 2, x + size / 2, y + size / 2);

	if ((lu == ru) && (ld == rd) && (ru == ld) && (lu != 2)) {
		length = strlen(buf);
		buf[length - 5] = buf[length - 4];
		buf[length - 4] = 0;
		return lu;
	}
	else {
		length = strlen(buf);
		buf[length] = ')';
		buf[length + 1] = 0;
		return 2;
	}
}