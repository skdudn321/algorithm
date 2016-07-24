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

#define O 2
#define X 1
#define none 0

typedef struct state {
	int map[4][4];
}state;

int check_winner(state cur_map);
int cur_win(state cur_map);
int change_map(state cur_map);

int dp[60000];

int main(void) {
	freopen("test.txt", "r", stdin);
	for (int i = 0; i < 60000; i++) {
		dp[i] = -100;
	}

	int T;
	scanf("%d\n", &T);
	for (int i = 1; i <= T; i++) {
		char temp;
		state start_map;
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				temp = getchar();
				if (temp == '.') {
					start_map.map[j][k] = none;
				}
				else if (temp == 'x') {
					start_map.map[j][k] = X;
				}
				else {
					start_map.map[j][k] = O;
				}
			}
			getchar();
		}
		if (cur_win(start_map) == 1) {
			printf("o\n");
		}
		else if (cur_win(start_map) == -1) {
			printf("x\n");
		}
		else {
			printf("TIE\n");
		}
	}
}

int cur_win(state cur_map) {
	int code = change_map(cur_map);
	if (dp[code] != -100) {
		return dp[code];
	}
	int winner = check_winner(cur_map);
	if (winner != 0) {
		dp[code] = winner;
		return winner;
	}

	int cou_x = 0, cou_o = 0, cou_none = 0;
	int cur_turn;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (cur_map.map[i][j] == O) {
				cou_o++;
			}
			if (cur_map.map[i][j] == X) {
				cou_x++;
			}
			if (cur_map.map[i][j] == none) {
				cou_none++;
			}
		}
	}

	if (cou_none == 0) {
		dp[code] = winner;
		return winner;
	}
	if (cou_x == cou_o) {
		cur_turn = X;
	}
	else {
		cur_turn = O;
	}

	int win_x = 100;
	int win_o = -100;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (cur_map.map[i][j] == none) {
				cur_map.map[i][j] = cur_turn;
				win_x = min(cur_win(cur_map), win_x);
				win_o = max(cur_win(cur_map), win_o);
				cur_map.map[i][j] = none;
			}
		}
	}

	if (cur_turn == X) {
		dp[code] = win_x;
	}
	else {
		dp[code] = win_o;
	}

	return dp[code];
}
int check_winner(state cur_map) {
	int cou;
	for (int i = 1; i <= 3; i++) {
		cou = 0;
		for (int j = 1; j <= 3; j++) {
			if (cur_map.map[i][j] == O) {
				cou++;
			}
		}
		if (cou == 3) {
			return 1;
		}
		cou = 0;
		for (int j = 1; j <= 3; j++) {
			if (cur_map.map[j][i] == O) {
				cou++;
			}
		}
		if (cou == 3) {
			return 1;
		}
	}
	cou = 0;
	for (int i = 1; i <= 3; i++) {
		if (cur_map.map[i][i] == O) {
			cou++;
		}
	}
	if (cou == 3) {
		return 1;
	}
	cou = 0;
	for (int i = 1; i <= 3; i++) {
		if (cur_map.map[i][4 - i] == O) {
			cou++;
		}
	}
	if (cou == 3) {
		return 1;
	}

	for (int i = 1; i <= 3; i++) {
		cou = 0;
		for (int j = 1; j <= 3; j++) {
			if (cur_map.map[i][j] == X) {
				cou++;
			}
		}
		if (cou == 3) {
			return -1;
		}
		cou = 0;
		for (int j = 1; j <= 3; j++) {
			if (cur_map.map[j][i] == X) {
				cou++;
			}
		}
		if (cou == 3) {
			return -1;
		}
	}
	cou = 0;
	for (int i = 1; i <= 3; i++) {
		if (cur_map.map[i][i] == X) {
			cou++;
		}
	}
	if (cou == 3) {
		return -1;
	}
	cou = 0;
	for (int i = 1; i <= 3; i++) {
		if (cur_map.map[i][4 - i] == X) {
			cou++;
		}
	}
	if (cou == 3) {
		return -1;
	}

	return 0;
}
int change_map(state cur_map) {
	int ret = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			ret *= 3;
			if (cur_map.map[i][j] == none) {
				ret += none;
			}
			else if (cur_map.map[i][j] == X) {
				ret += X;
			}
			else {
				ret += O;
			}
		}
	}

	return ret;
}