#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

int ans;

int main(void) {
	for(int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (i * i + j * j == (1000 - i - j) * (1000 - i - j)) {
				printf("%d", i * j * (1000 - i - j));
				return 0;
			}
		}
	}
}