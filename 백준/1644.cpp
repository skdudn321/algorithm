#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;

vector<int> sosu;
bool che[4000001];

void make_sosu(void);

int main(void) {
	int N;
	int num = 0;
	int index1 = 0, index2 = 1;

	make_sosu();

	scanf("%d", &N);

	num = sosu[0];

	while (index1 < index2 && index2 != sosu.size()) {
		if (num < N) {
			num += sosu[index2++];
		}
		else if (num > N) {
			num -= sosu[index1++];
		}
		else {
			ans++;
			num += sosu[index2++];
		}
	}

	printf("%d", ans);
}

void make_sosu(void) {
	for (int i = 2; i <= 4000000; i++) {
		if (!che[i]) {
			sosu.push_back(i);
			for (int j = 2; i * j <= 4000000; j++ ) {
				che[i * j] = 1;
			}
		}
	}
}