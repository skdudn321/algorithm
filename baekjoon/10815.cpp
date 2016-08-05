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

vector<int> ve;

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		ve.push_back(t);
	}
	sort(ve.begin(), ve.end());

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		vector<int>::iterator tt;
		tt = upper_bound(ve.begin(), ve.end(), t);
		if (*(tt - 1) == t) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
}