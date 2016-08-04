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
bool check[50];

int main(void) {
	int num;
	for (int i = 1; i <= 10; i++) {
		scanf("%d", &num);
		num %= 42;
		if (!check[num]) {
			check[num] = true;
			ans++;
		}
	}

	printf("%d", ans);
}