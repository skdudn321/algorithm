#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;

int table[1000][1000];

int main(void) {
	int N, M;
	int ind = 0;
	int ans_x, ans_y;
	
	scanf("%d %d", &N, &M);

	int num = N * N;
	int x = 0, y = 1;
	int fin = N;
	while (fin != 1) {
		x++;
		for (int i = 0; i < fin; i++) {
			table[x][y] = num - ind;
			if (num - ind == M) {
				ans_x = x;
				ans_y = y;
			}
			ind++;
			x++;
		}
		x--;
		fin--;
		y++;
		for (int i = 0; i < fin; i++) {
			table[x][y] = num - ind;
			if (num - ind == M) {
				ans_x = x;
				ans_y = y;
			}
			ind++;
			y++;
		}
		y--;
		x--;
		for (int i = 0; i < fin; i++) {
			table[x][y] = num - ind;
			if (num - ind == M) {
				ans_x = x;
				ans_y = y;
			}
			ind++;
			x--;
		}
		x++;
		fin--;
		y--;
		for (int i = 0; i < fin; i++) {
			table[x][y] = num - ind;
			if (num - ind == M) {
				ans_x = x;
				ans_y = y;
			}
			ind++;
			y--;
		}
		y++;
	}
	table[x + 1][y] = 1;
	if (M == 1) {
		ans_x = x + 1;
		ans_y = y;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", ans_x, ans_y);
}