#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int high;
int T;
int N;
long long int sum;
int price[1000001];

int main(void) {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &price[j]);
		}
		sum = 0;
		high = price[N - 1];
		for (int j = N - 2; j >= 0; j--) {
			if (high > price[j]) {
				sum += high - price[j];
			}
			else {
				high = price[j];
			}
		}
		printf("%lld\n", sum);
	}
}