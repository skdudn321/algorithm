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

typedef pair<int, int> ii;

ii line[100];
int ans;
vector<int> kk;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		line[i] = ii(x, y);
	}
	sort(line, line + N);

	for (int i = 0; i < N; i++) {
		vector<int>::iterator temp = lower_bound(kk.begin(), kk.end(), line[i].second);
		if (temp == kk.end()) {
			kk.push_back(line[i].second);
		}
		else {
			*temp = line[i].second;
		}
	}

	printf("%d", N - kk.size());
}