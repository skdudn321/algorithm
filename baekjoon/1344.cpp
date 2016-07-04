#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

double A[20], B[20];
double win_A, win_B, lose_A, lose_B;
double ans;

long long int facto[20];

void make(void);

int main(void) {
	int temp1, temp2;

	scanf("%d %d", &temp1, &temp2);
	win_A = (double)temp1 / 100;
	win_B = (double)temp2 / 100;
	lose_A = (double)(100 - temp1) / 100;
	lose_B = (double)(100 - temp2) / 100;
	make();

	for (int i = 0; i <= 18; i++) {
		A[i] = (double)(facto[18] / (facto[i] * facto[18 - i]));
		B[i] = (double)(facto[18] / (facto[i] * facto[18 - i]));
		for (int j = 0; j < i; j++) {
			A[i] *= win_A;
			B[i] *= win_B;
		}
		for (int j = i; j < 18; j++) {
			A[i] *= lose_A;
			B[i] *= lose_B;
		}
	}

	for (int i = 0; i <= 18; i++) {
		if (i != 2 && i != 3 && i != 5 && i != 7 && i != 11 && i != 13 && i != 17) {
			for (int j = 0; j <= 18; j++) {
				if (j != 2 && j != 3 && j != 5 && j != 7 && j != 11 && j != 13 && j != 17) {
					ans += A[i] * B[j];
				}
			}
		}
	}

	printf("%.8lf", 1 - ans);
	return 0;
}

void make(void) {
	facto[0] = 1;
	facto[1] = 1;

	for (int i = 2; i <= 18; i++) {
		facto[i] = facto[i - 1] * i;
	}
}