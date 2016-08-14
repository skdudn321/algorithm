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

int ans;
vector<int> ve;

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		vector<int>::iterator tt = lower_bound(ve.begin(), ve.end(), -temp);
		if (tt == ve.end()) {
			ve.push_back(-temp);
		}
		else {
			*tt = -temp;
		}
	}
	printf("%d", ve.size());
}