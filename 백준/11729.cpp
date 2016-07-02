#include<stdio.h>

int how_many(int num);
void hanoi(int num, int start, int destination);
int cal_other(int start, int destination);

int main(void) {
	int num;
	scanf("%d", &num);
	printf("%d\n", how_many(num));
	hanoi(num, 1, 3);
}

int how_many(int num) {
	int r_value = 1;
	int i;
	for (i = 1; i < num; i++) {
		r_value = r_value * 2 + 1;
	}
	return r_value;
}

void hanoi(int num, int start, int destination) {
	int other = cal_other(start, destination);
	if (num == 1) {
		printf("%d %d\n", start, destination);
	}
	else {
		hanoi(num - 1, start, other);
		printf("%d %d\n", start, destination);
		hanoi(num - 1, other, destination);
	}
}

int cal_other(int start, int destination) {
	switch (start + destination) {
	case 3 :
		return 3;
	case 4 :
		return 2;
	default :
		return 1;
	}
}