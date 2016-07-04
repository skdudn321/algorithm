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
char pr[1001000];

int main(void) {

	int temp;
	int ind = 0;
	while (scanf("%1d", &temp) != EOF) {
		pr[ind++] = temp / 4 + '0';
		temp %= 4;
		pr[ind++] = temp / 2 + '0';
		temp %= 2;
		pr[ind++] = temp + '0';
	}
	
	ind = 0;
	while (pr[ind] == '0') {
		ind++;
	}
	if (pr[ind] == 0) {
		printf("0");
	}
	else {
		printf("%s", &pr[ind]);
	}
}