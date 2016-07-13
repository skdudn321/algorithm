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
int check;
bool sosu[10000001];

int main(void) {
	for (int i = 2; i <= 10000000; i++) {
		sosu[i] = true;
	}
	for (int i = 2; i <= 10000000; i++) {
		if (sosu[i]) {
			check++;
			if (check == 10001) {
				check = i;
				break;
			}
			for (int j = 2; i * j <= 10000000; j++) {
				sosu[i * j] = false;
			}
		}
	}
	printf("%d", check);
}