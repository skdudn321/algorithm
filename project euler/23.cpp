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

int table[30001];
int check[30001];
int ans[30001];

int main(void) {
	for (int i = 1; i <= 30000; i++) {
		for (int j = 2; i * j <= 30000; j++) {
			table[i * j] += i;
		}
	}

	for (int i = 12; i <= 30000; i++) {
		if (table[i] > i) {
			check[i] = 1;
		}
	}

	for (int i = 12; i <= 30000; i++) {
		if (check[i] == 1) {
			for (int j = 12; j <= 30000; j++) {
				if (check[j] == 1) {
					if (i + j <= 30000) {
						ans[i + j] = 1;
					}
				}
			}
		}
	}

	long long int ret = 0;
	for (int i = 1; i <= 30000; i++) {
		if (ans[i] == 0) {
			ret += i;
		}
	}
	printf("%lld", ret);
}