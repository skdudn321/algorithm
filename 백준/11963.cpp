#include<stdio.h>

int card[200200];

int main(void) {
	int N, temp, check, ans1, ans2, count;

	scanf("%d", &N);

	for (int i = 0; i < (N / 2); i++) {
		scanf("%d", &temp);
		card[temp] = 1;
	}
	for (int i = 0; i < (N / 2); i++) {
		scanf("%d", &temp);
		card[temp] = 2;
	}
	check = 0;
	ans1 = N / 2;
	count = 0;
	for (int i = 2 * N; count < (N / 2); i--) {
		if (card[i] == 0) {
			check++;
			count++;
		}
		else if(card[i] == 1){
			if (check == 0) {
				ans1--;
			}
			else {
				check--;
			}
		}
	}

	check = 0;
	count = 0;
	ans2 = N / 2;
	for (int i = 1; count < (N / 2); i++) {
		if (card[i] == 0) {
			check++;
			count++;
		}
		else if (card[i] == 2) {
			if (check == 0) {
				ans2--;
			}
			else {
				check--;
			}
		}
	}

	printf("%d", ans1 + ans2);
}