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
typedef pair<ii, ii> jj; // ���۽ð�, �߿䵵, �����½ð�, �����ð�
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
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", flag);
	}

	return 0;
}