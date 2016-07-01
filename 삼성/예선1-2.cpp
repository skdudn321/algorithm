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
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}