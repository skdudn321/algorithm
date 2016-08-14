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
int L, C;
vector<char> ve;
char print[20];

void recursion(int num, int ind, int mo, int ja);

int main(void) {
	scanf("%d %d\n", &L, &C);
	print[L + 1] = 0;
	for (int i = 1; i <= C; i++) {
		char temp;
		temp = getchar();
		ve.push_back(temp);
		getchar();
	}
	sort(ve.begin(), ve.end());
	recursion(1, 1, 1, 2);
}

void recursion(int num, int ind, int mo, int ja) {
	if (ind == L + 1) {
		printf("%s\n", &print[1]);
		return;
	}
	if (num >= C + 1) {
		return;
	}

	char cur = ve[num - 1];

	int moj;
	if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u') {
		moj = 1;
	}
	else {
		moj = 0;
	}
	int left = L + 1 - ind;

	if (left == mo) {
		if (moj == 1) {
			print[ind] = cur;
			recursion(num + 1, ind + 1, mo - 1, ja);
		}
		recursion(num + 1, ind, mo, ja);
	}
	else if (left == ja) {
		if (moj == 0) {
			print[ind] = cur;
			recursion(num + 1, ind + 1, mo, ja - 1);
		}
		recursion(num + 1, ind, mo, ja);
	}
	else {
		print[ind] = cur;
		if (moj == 1) {
			recursion(num + 1, ind + 1, mo - 1, ja);
		}
		else {
			recursion(num + 1, ind + 1, mo, ja - 1);
		}
		recursion(num + 1, ind, mo, ja);
	}
}