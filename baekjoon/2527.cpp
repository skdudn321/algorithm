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

char ans;

int main(void) {
	int squ[2][4], temp;
	
	while (scanf("%d %d %d %d %d %d %d %d", &squ[0][0], &squ[0][1], &squ[0][2], &squ[0][3], &squ[1][0], &squ[1][1], &squ[1][2], &squ[1][3]) != EOF) {
		if (squ[0][0] > squ[1][0]) {
			for (int j = 0; j < 4; j++) {
				temp = squ[0][j];
				squ[0][j] = squ[1][j];
				squ[1][j] = temp;
			}
		}

		if (squ[0][2] < squ[1][0]) {
			printf("d\n");
		}
		else if (squ[0][2] == squ[1][0]) {
			if (squ[0][1] > squ[1][3]) {
				printf("d\n");
			}
			else if (squ[0][1] == squ[1][3]) {
				printf("c\n");
			}
			else if (squ[0][3] < squ[1][1]) {
				printf("d\n");
			}
			else if (squ[0][3] == squ[1][1]) {
				printf("c\n");
			}
			else {
				printf("b\n");
			}
		}
		else {
			if (squ[0][1] > squ[1][3]) {
				printf("d\n");
			}
			else if (squ[0][1] == squ[1][3]) {
				printf("b\n");
			}
			else if (squ[0][3] < squ[1][1]) {
				printf("d\n");
			}
			else if (squ[0][3] == squ[1][1]) {
				printf("b\n");
			}
			else {
				printf("a\n");
			}
		}
	}
}