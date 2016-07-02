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

int N;

int main(void) {
	int ha;

	while (scanf("%d", &N) != EOF) {
		vector<int> ve;
		for (int i = 0; i < N; i++) {
			scanf("%d", &ha);
			vector<int>::iterator temp;
			temp = lower_bound(ve.begin(), ve.end(), ha);
			if (temp == ve.end()) {
				ve.push_back(ha);
			}
			else {
				*temp = ha;
			}
		}
		printf("%d\n", ve.size());
	}
}