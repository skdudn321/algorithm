#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

int ans;

int main(void) {
	for (int i = 1; i <= 8; i++) {
		int temp;
		scanf("%d", &temp);
		ans = ans * 10 + temp;
	}
	if (ans == 12345678) {
		printf("ascending");
	}
	else if (ans == 87654321) {
		printf("descending");
	}
	else {
		printf("mixed");
	}
}