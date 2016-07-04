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
char num[2][11], str[11];

int main(void) {
	int N;
	char temp;

	scanf("%d\n", &N);

	num[0][0] = '9';
	num[1][0] = '0';

	for (int i = 0; i < N; i++) {
		scanf("%c ", &str[i]);
		num[0][i + 1] = '9' - i - 1;
		num[1][i + 1] = i + 1 + '0';
		for (int j = i; j >= 0; j--) {
			for (int k = 0; k <= 1; k++) {
				if (str[j] == '>') {
					if (num[k][j] < num[k][j + 1]) {
						temp = num[k][j];
						num[k][j] = num[k][j + 1];
						num[k][j + 1] = temp;
					}
				}
				else {
					if (num[k][j] > num[k][j + 1]) {
						temp = num[k][j];
						num[k][j] = num[k][j + 1];
						num[k][j + 1] = temp;
					}
				}
			}
		}
	}
	printf("%s\n%s", num[0], num[1]);
}