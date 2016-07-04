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
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (C % 2 == 0) {
		printf("%d", A);
	}
	else {
		printf("%d", (A & ~(B)) | (~A & B));
	}
}