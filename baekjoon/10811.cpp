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

int num[101];

stack<int> st;

int main(void) {
	int N, M;
	int a, b;

	for (int i = 0; i <= 100; i++) {
		num[i] = i;
	}

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		for (int j = a; j <= b; j++) {
			st.push(num[j]);
		}
		for (int j = a; j <= b; j++) {
			num[j] = st.top();
			st.pop();
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", num[i]);
	}
}