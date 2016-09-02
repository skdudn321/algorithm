#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

char *str[2][6] = { {"Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"}, {"Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"} };

int ans;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		printf("Case %d: ", C);
		int N, M;
		scanf("%d %d", &N, &M);

		if (M > N) {
			int t = N;
			N = M;
			M = t;
		}

		if (N == M) {
			printf("%s\n", str[1][N - 1]);
		}
		else {
			if (N == 6 && M == 5) {
				printf("Sheesh Beesh\n");
			}
			else {
				printf("%s %s\n", str[0][N - 1], str[0][M - 1]);
			}
		}
	}
}