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

int table[101][101];
int check[101];
int K, L, N, M;

int main(int argc, char** argv) {
	
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				table[i][j] = 0;
			}
			check[i] = 0;
		}
		scanf("%d %d %d %d", &K, &L, &N, &M);
		for (int i = 1; i <= M; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			table[t1][t2] = 1;
			table[t2][t1] = 1;
			table[t1][0]++;
			table[t2][0]++;
		}

		bool flag = true;
		int temp_N = N;
		while (flag) {
			flag = false;
			for (int i = 1; i <= N; i++) {
				if (check[i] == 0 && temp_N - (table[i][0] + 1) < L) {
					flag = true;
					check[i] = 1;
					for (int j = 1; j <= N; j++) {
						if (table[i][j] == 1) {
							table[j][i] = 0;
							table[j][0]--;
						}
					}
					temp_N--;
				}
			}
			for (int i = 1; i <= N; i++) {
				if (check[i] == 0 && table[i][0] < K) {
					flag = true;
					check[i] = 1;
					for (int j = 1; j <= N; j++) {
						if (table[i][j] == 1) {
							table[j][i] = 0;
							table[j][0]--;
						}
					}
					temp_N--;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (check[i] == 1) {
				ans += i;
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;
}