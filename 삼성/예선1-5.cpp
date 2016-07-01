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
typedef pair<ii, ii> jj; // 시작시간, 중요도, 끝나는시간, 남은시간
int N, K;
priority_queue< jj, vector<jj>, greater<jj> > pq;
int check[201];
int flag;

int main(int argc, char** argv) {

	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		scanf("%d %d", &N, &K);
		while (!pq.empty()) {
			pq.pop();
		}
		for (int i = 0; i <= 200; i++) {
			check[i] = 0;
		}
		flag = 1;
		
		for (int i = 1; i <= N; i++) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			pq.push(jj(ii(t1, (t2 - t1) - t3), ii(t2, t3)));
		}

		for (int i = 1; i <= K; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			for (int i = t1; i < t2; i++) {
				check[i]++;
			}
		}

		while (!pq.empty()) {
			jj temp = pq.top();
			pq.pop();
			if (check[temp.first.first] == 0) {
				if (temp.first.second == 0) {
					flag = 0;
					break;
				}
				pq.push(jj(ii(temp.first.first + 1, temp.first.second - 1), temp.second));
			}
			else {
				check[temp.first.first]--;
				if (temp.second.second != 1) {
					pq.push(jj(ii(temp.first.first + 1, temp.first.second), ii(temp.second.first, temp.second.second - 1)));
				}
			}
		}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n", flag);
	}

	return 0;
}