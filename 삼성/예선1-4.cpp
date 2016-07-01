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

typedef pair<int, int> ii;
typedef pair<int, ii> jj;
int check[100001];
int ans[2][100001];
vector<ii> ve[100001];
priority_queue< jj, vector<jj>, greater<jj> > pq;
int N, M, K;

int main(int argc, char** argv) {

	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 1; i <= N; i++) {
			ve[i].clear();
			check[i] = 0;
			ans[0][i] = 2000000000;
			ans[1][i] = 0;
		}
		while (!pq.empty()) {
			pq.pop();
		}
		for (int i = 1; i <= M; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			ve[t1].push_back(ii(t2, t3));
			ve[t2].push_back(ii(t1, t3));
		}
		for (int i = 1; i <= K; i++) {
			int t1;
			scanf("%d", &t1);
			pq.push(jj(0, ii(t1, t1)));
			check[t1] = 1;
		}
		
		while (!pq.empty()) {
			jj temp = pq.top();
			pq.pop();
			check[temp.second.second] = 1;
			if (ans[0][temp.second.second] > temp.first) {
				ans[0][temp.second.second] = temp.first;
				ans[1][temp.second.second] = temp.second.first;
			}
			for (int i = 0; i < ve[temp.second.second].size(); i++) {
				if (check[ve[temp.second.second][i].first] == 0) {
					pq.push(jj(temp.first + ve[temp.second.second][i].second, ii(temp.second.first, ve[temp.second.second][i].first)));
				}
			}
		}
		long long int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= N; i++) {
			ans1 += ans[0][i];
			ans2 += ans[1][i];
		}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%lld\n%lld\n", ans1, ans2);
	}

	return 0;
}