#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

int ans;

int table[10][10];

void check(int up, int down);

int main(void) {
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			table[i][j] = -1;
		}
	}

	for (int i = 1; i < 9; i++) {
		for (int j = i + 1; j <= 9; j++) {
			check(i, j);
		}
	}
}

void check(int up, int down) {
	int te_up;
	int te_down;

	for (int i = 0; i <= 9; i++) {
		te_up = up * 10 + i;
		te_down = down * 10 + i;
		if ((double)te_up / te_down == (double)up / down) {
			if ((te_down != down || te_up != up) && (te_down != down * 10 || te_up != up * 10)) {
				printf("%d %d  /  %d %d\n", te_up, te_down, up, down);
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		te_up = up + 10 * i;
		te_down = down + 10 * i;
		if ((double)te_up / te_down == (double)up / down) {
			if ((te_down != down || te_up != up) && (te_down != down * 10 || te_up != up * 10)) {
				printf("%d %d  /  %d %d\n", te_up, te_down, up, down);
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		te_up = up * 10 + i;
		te_down = down + 10 * i;
		if ((double)te_up / te_down == (double)up / down) {
			if ((te_down != down || te_up != up) && (te_down != down * 10 || te_up != up * 10)) {
				printf("%d %d  /  %d %d\n", te_up, te_down, up, down);
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		te_up = up + 10 * i;
		te_down = down * 10 + i;
		if ((double)te_up / te_down == (double)up / down) {
			if ((te_down != down || te_up != up) && (te_down != down * 10 || te_up != up * 10)) {
				printf("%d %d  /  %d %d\n", te_up, te_down, up, down);
			}
		}
	}
	
}