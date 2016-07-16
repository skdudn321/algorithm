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
int table[3][1002];

int main(void) {
	int N = 2;
	table[0][1000] = 1;
	table[1][1000] = 1;

	while(1) {
		for (int j = 1000; j >= 1; j--) {
			table[2][j] = table[0][j] + table[1][j] + (table[2][j + 1] / 10);
			table[2][j + 1] %= 10;
		}
		N++;
		if (table[2][1] != 0) {
			printf("%d", N);
			return 0;
		}
		for (int j = 1; j <= 1000; j++) {
			table[0][j] = table[1][j];
			table[1][j] = table[2][j];
		}
	}
}