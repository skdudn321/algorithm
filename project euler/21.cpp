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

int table[20010];
int ans;

int main(void) {
	for (int i = 1; i <= 20000; i++) {
		for (int j = 2; i * j <= 20000; j++) {
			table[i * j] += i;
		}
	}

	for (int i = 2; i <= 10000; i++) {
		if (i != table[i] && i == table[table[i]]) {
			printf("%d %d\n", i, table[i]);
			ans += i + table[i];
		}
	}

	printf("%d", ans / 2);
}