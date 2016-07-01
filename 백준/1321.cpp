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

int bode[1100000];
int N, real_N = 1;

int make_index_tree(int num);
void change_index_tree(int ind, int num);
void find_index_tree(int num);

int main(void) {

	scanf("%d", &N);

	while (real_N < N) {
		real_N *= 2;
	}

	for (int i = 1; i < real_N; i++) {
		bode[i] = -1;
	}
	for (int i = real_N; i < N + real_N; i++) {
		scanf("%d", &bode[i]);
	}

	make_index_tree(1);

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int tt[3];
		scanf("%d", &tt[0]);
		if (tt[0] == 1) {
			scanf("%d %d", &tt[1], &tt[2]);
			change_index_tree(real_N + tt[1] - 1, tt[2]);
		}
		else {
			scanf("%d", &tt[1]);
			find_index_tree(tt[1]);
		}
	}
}

int make_index_tree(int num) {
	if (bode[num] != -1) {
		return bode[num];
	}
	bode[num] = make_index_tree(2 * num) + make_index_tree(2 * num + 1);
	return bode[num];
}
void change_index_tree(int ind, int num) {
	while (ind > 0) {
		bode[ind] += num;
		ind /= 2;
	}
}
void find_index_tree(int num) {
	int ind = 1;
	int temp = 0;

	while (ind < real_N) {
		if (bode[ind * 2] + temp < num) {
			temp += bode[ind * 2];
			ind = ind * 2 + 1;
		}
		else {
			ind = ind * 2;
		}
	}

	printf("%d\n", ind - real_N + 1);
}