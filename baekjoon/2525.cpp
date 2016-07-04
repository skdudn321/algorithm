#include<stdio.h>

int main(void) {
	int clock;
	int minute;
	int temp;

	scanf("%d %d", &clock, &minute);
	scanf("%d", &temp);

	minute += temp;
	clock += (minute / 60);
	minute %= 60;
	clock %= 24;

	printf("%d %d", clock, minute);
}