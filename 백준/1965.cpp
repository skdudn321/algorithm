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

int ans;
vector<int> ve;

int main(void) {
	int T;
	int temp;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d", &temp);
		vector<int>::iterator temp2 = lower_bound(ve.begin(), ve.end(), temp);
		if (temp2 != ve.end()) {
			ve.erase(temp2);
		}
		ve.insert(temp2, temp);
	}

	printf("%d", ve.size());
}