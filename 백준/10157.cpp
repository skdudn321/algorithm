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
int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

int main(void) {
	int N, M;
	int K;

	scanf("%d %d %d", &N, &M, &K);

	if (K > N * M) {
		printf("0");
		return 0;
	}
	if (K == 1) {
		printf("1 1");
		return 0;
	}

	int max_x = N;
	int min_x = 1;
	int max_y = M;
	int min_y = 0;
	int ind = 0;
	int x = 1, y = 2;
	K-=2;
	while (K != 0) {
		if (x == max_x && y == max_y) {
			ind = 2;
			min_x++;
		}
		else if (x == max_x && y == min_y) {
			ind = 3;
			max_y--;
		}
		else if (x == min_x && y == max_y) {
			ind = 1;
			min_y++;
		}
		else if (x == min_x && y == min_y) {
			ind = 0;
			max_x--;
		}

		x += xx[ind];
		y += yy[ind];
		K--;
	}

	printf("%d %d", x, y);
}