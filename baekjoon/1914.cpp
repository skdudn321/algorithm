#include<stdio.h>

void how_many(int num);
void hanoi(int num, int start, int destination);
int cal_other(int start, int destination);

int main(void) {
	int num;
	scanf("%d", &num);
	how_many(num);
	if (num <= 20) {
		hanoi(num, 1, 3);
	}
}

void how_many(int num) {
	long long l_value = 2;
	long long f_value = 0;
	int i;
	for (i = 1; i < num; i++) {
		l_value *= 2;
		f_value *= 2;
		if (l_value >= 1000000000000000000) {
			f_value += (l_value / 1000000000000000000);
			l_value %= 1000000000000000000;
		}
	}
	if (f_value == 0) {
		printf("%lld\n", l_value - 1);
	}
	else if(l_value != 0){
		printf("%lld%018lld\n", f_value, l_value - 1);
	}
	else {
		printf("%lld%018lld\n", f_value - 1, l_value + 999999999999999999);
	}
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
	case 3:
		return 3;
	case 4:
		return 2;
	default:
		return 1;
	}
}