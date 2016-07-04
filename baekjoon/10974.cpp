#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int N;
bool check[10];
int pr[10];
void recursion(int N);

int main(void) {
	scanf("%d", &N);
	recursion(1);
}

void recursion(int ind) {
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			check[i] = true;
			pr[ind] = i;
			if (ind == N) {
				for (int j = 1; j <= N; j++) {
					printf("%d ", pr[j]);
				}
				printf("\n");
			}
			else {
				recursion(ind + 1);
			}
			check[i] = false;
		}
	}
}