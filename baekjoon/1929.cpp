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

int ans;
bool sosu[1000001];

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	sosu[0] = true;
	sosu[1] = true;
	for (int i = 2; i <= M; i++) {
		if (sosu[i] == false) {
			for (int j = 2; j * i <= M; j++) {
				sosu[i * j] = true;
			}
		}
	}

	for (int i = N; i <= M; i++) {
		if (sosu[i] == false) {
			printf("%d\n", i);
		}
	}
}