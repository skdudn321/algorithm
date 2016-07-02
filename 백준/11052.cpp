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

int table[1001];

int main(void) {
	int N;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &table[i]);
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			table[i] = max(table[i], table[j] + table[i - j]);
		}
	}

	printf("%d", table[N]);
}