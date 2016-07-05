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
#include<string>
#include<iostream>

using namespace std;

int ans;

string pt[101];
char file[110];
char wild[110];
int dp[102][102];
int wild_len, file_len;

int recursion(int wild_ind, int file_ind);

int main(void) {

	int T;
	scanf("%d", &T);

	for (int tt = 1; tt <= T; tt++) {
		int N;
		int pt_ind = 0;
		scanf("%s\n", wild);
		scanf("%d\n", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%s\n", file);

			for (int j = 0; j <= 101; j++) {
				for (int k = 0; k <= 101; k++) {
					dp[j][k] = -1;
				}
			}

			wild_len = strlen(wild);
			file_len = strlen(file);

			if (recursion(0, 0) == 1) {
				pt[pt_ind++] = string(file);
			}
		}
		sort(pt, pt + pt_ind);
		for (int i = 0; i < pt_ind; i++) {
			cout << pt[i] << endl;
		}
	}
}

int recursion(int wild_ind, int file_ind) {
	if (dp[wild_ind][file_ind] != -1) {
		return dp[wild_ind][file_ind];
	}

	if (wild_ind == wild_len && file_ind == file_len) {
		return 1;
	}
	else if (wild_ind == wild_len) {
		return 0;
	}
	else if (file_ind == file_len) {
		if (wild[wild_ind] == '*') {
			return recursion(wild_ind + 1, file_ind);
		}
		else {
			return 0;
		}
	}

	int ret = 0;
	if (wild[wild_ind] == '?' || wild[wild_ind] == file[file_ind]) {
		ret = recursion(wild_ind + 1, file_ind + 1);
	}
	else if (wild[wild_ind] == '*') {
		if (recursion(wild_ind + 1, file_ind + 1) == 1) {
			ret = 1;
		}
		else if (recursion(wild_ind, file_ind + 1) == 1) {
			ret = 1;
		}
		else if (recursion(wild_ind + 1, file_ind) == 1) {
			ret = 1;
		}
	}

	dp[wild_ind][file_ind] = ret;
	return ret;
}