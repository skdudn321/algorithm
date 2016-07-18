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
int table[3001];

int main(void) {
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j < i; j++) {
			for (int k = j; k < i; k++) {
				if (i * i == j * j + k * k) {
					table[i + j + k]++;
				}
			}
		}
	}
	int ind = 0;
	for (int i = 1; i <= 1000; i++) {
		if (ans < table[i]) {
			ans = table[i];
			ind = i;
		}
	}

	printf("%d", ind);
}