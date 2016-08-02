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

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> cc;

int ans;
int N;
cc cas[110];
vector<int> ve[110];
bool check[110];

void make_tree(int num);
bool is_parent(int a, int b);
int tree_length(int num);

int main(void) {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d %d %d", &(cas[i].second.first), &(cas[i].second.second), &(cas[i].first));
			ve[i].clear();
			check[i] = false;
		}
		ans = 0;
		check[1] = true;
		sort(cas + 1, cas + N + 1, greater<cc>());
		make_tree(1);
		tree_length(1);
		printf("%d\n", ans);
	}
}

int tree_length(int num) {
	if (ve[num].empty()) {
		return 1;
	}

	int length1 = 0, length2 = 0;
	for (int i = 0; i < ve[num].size(); i++) {
		int temp = tree_length(ve[num][i]);
		if (length1 < temp) {
			length2 = length1;
			length1 = temp;
		}
		else if (length2 < temp) {
			length2 = temp;
		}
	}

	ans = max(ans, length1 + length2);
	return length1 + 1;
}
void make_tree(int num) {
	for (int i = num + 1; i <= N; i++) {
		if (!check[i] && is_parent(num, i)) {
			check[i] = true;
			ve[num].push_back(i);
			make_tree(i);
		}
	}
}

bool is_parent(int a, int b) {
	return ((cas[a].first * cas[a].first) > (((cas[b].second.first - cas[a].second.first) * (cas[b].second.first - cas[a].second.first)) + ((cas[b].second.second - cas[a].second.second) * (cas[b].second.second - cas[a].second.second))));
}