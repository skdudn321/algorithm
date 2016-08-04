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
	int N, F;
	scanf("%d %d", &N, &F);

	int temp = (((N / 100) * 100) % F);
	
	printf("%02d", (F - temp) % F);
}