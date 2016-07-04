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

int table[1000000];
int num = 3;
int ind = 4;
int all = 5;

int main(void) {
	int N;
	scanf("%d", &N);
	table[1] = 1;
	table[2] = 2;
	table[3] = 2;

	if (N == 1) {
		printf("1");
	}
	else if (N <= 3) {
		printf("2");
	}
	else if (N <= 5) {
		printf("3");
	}
	else {
		while (true) {
			for (int i = 1; i <= table[num]; i++) {
				table[ind] = num;
				all += num;
				if (all >= N) {
					break;
				}
				ind++;
			}
			if (all >= N) {
				break;
			}
			num++;
		}
		printf("%d", ind);
	}
}