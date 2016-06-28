#include<stdio.h>
#include<algorithm>

using namespace std;

int num[30];
int answer;
int N, K;

void recursion(int index, int sum);

int main(void) {
	int i;

	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	}

	sort(num + 1, num + N + 1);
	recursion(1, 0);

	printf("%d\n", answer);
}

void recursion(int index, int sum) {
	if (index > N) {
		return;
	}

	if (sum + num[index] == K) {
		answer++;
	}
	
	recursion(index + 1, sum + num[index]);
	recursion(index + 1, sum);
}