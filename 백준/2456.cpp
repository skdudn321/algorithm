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

typedef struct aa {
	int score;
	int result[4];
}aa;

aa king[4];

int main(void) {

	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= 3; j++) {
			int temp;
			scanf("%d", &temp);
			king[j].score += temp;
			king[j].result[temp]++;
		}
	}

	if (king[1].score > king[2].score) {
		if (king[1].score > king[3].score) {
			printf("1 %d", king[1].score);
		}
		else if (king[1].score < king[3].score) {
			printf("3 %d", king[3].score);
		}
		else {
			if (king[1].result[3] > king[3].result[3]) {
				printf("1 %d", king[1].score);
			}
			else if (king[1].result[3] < king[3].result[3]) {
				printf("3 %d", king[3].score);
			}
			else {
				printf("0 %d", king[3].score);
			}
		}
	}
	else if (king[1].score < king[2].score) {
		if (king[2].score > king[3].score) {
			printf("2 %d", king[2].score);
		}
		else if (king[2].score < king[3].score) {
			printf("3 %d", king[3].score);
		}
		else {
			if (king[2].result[3] > king[3].result[3]) {
				printf("2 %d", king[2].score);
			}
			else if (king[2].result[3] < king[3].result[3]) {
				printf("3 %d", king[3].score);
			}
			else {
				printf("0 %d", king[3].score);
			}
		}
	}
	else {
		if (king[1].score > king[3].score) {
			if (king[1].score > king[2].score) {
				printf("1 %d", king[1].score);
			}
			else if (king[1].score < king[2].score) {
				printf("2 %d", king[2].score);
			}
			else {
				if (king[1].result[3] > king[2].result[3]) {
					printf("1 %d", king[1].score);
				}
				else if (king[1].result[3] < king[2].result[3]) {
					printf("2 %d", king[2].score);
				}
				else {
					printf("0 %d", king[2].score);
				}
			}
		}
		else if (king[1].score < king[3].score) {
			printf("3 %d", king[3].score);
		}
		else {
			printf("0 %d", king[1].score);
		}
	}
}