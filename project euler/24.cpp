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
int check[10];
int table[10];
int recursion(int N, int ind);

int main(void) {
	recursion(0, 0);
}

int recursion(int N, int ind) {
	if (ind == 10) {
		N++;
		if (N == 1000000) {
			for (int i = 0; i <= 9; i++) {
				printf("%d", table[i]);
			}
			return -1;
		}
		return N;
	}

	for (int i = 0; i <= 9; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			table[ind] = i;
			N = recursion(N, ind + 1);
			if (N == -1) {
				return -1;
			}
			check[i] = 0;
		}
	}

	return N;
}