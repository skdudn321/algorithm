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

int dp[101][50001];
bool check[50001];

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		int N, K, L;
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 50000; j++) {
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i <= 50000; i++) {
			check[i] = true;
		}

		scanf("%d %d %d", &N, &K, &L);

		for (int i = 1; i <= L; i++) {
			int t;
			scanf("%d", &t);
			check[t] = false;
		}

		for (int i = 0; i <= K; i++) {
			dp[i][0] = 1;
		}
		for (int i = 1; i < K; i++) {
			if (check[i] == false) {
				continue;
			}
			int all = 0;
			for (int j = 1; j <= i; j++) {
				dp[j][i] = dp[j][i - j];
				all = (all + dp[j][i]) % 1000000009;
			}
			for (int j = 1; j <= K; j++) {
				dp[j][i] = all - dp[j][i];
				if (dp[j][i] < 0) {
					dp[j][i] += 1000000009;
				}
			}
		}

		for (int i = K; i <= N; i++) {
			if (check[i] == false) {
				continue;
			}
			int all = 0;
			for (int j = 1; j <= K; j++) {
				dp[j][i] = dp[j][i - j];
				all = (all + dp[j][i]) % 1000000009;
			}
			if (i == N) {
				break;
			}
			for (int j = 1; j <= K; j++) {
				dp[j][i] = all - dp[j][i];
				if (dp[j][i] < 0) {
					dp[j][i] += 1000000009;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= K; i++) {
			ans = (ans + dp[i][N]) % 1000000009;
		}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}