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

typedef struct list {
	int num;
	int index;
	struct list * next;
	struct list * back;
}list;

int ans;
list li[1001];

int main(void) {
	int N;
	list * st;
	
	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		li[i].next = &li[i + 1];
	}
	for (int i = N; i > 1; i--) {
		li[i].back = &li[i - 1];
	}
	li[N].next = &li[1];
	li[1].back = &li[N];

	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		li[i].num = temp;
		li[i].index = i;
	}

	st = &li[1];

	for (int i = 1; i <= N; i++) {
		st->next->back = st->back;
		st->back->next = st->next;
		printf("%d ", st->index);
		int num = st->num;
		if (num > 0) {
			for (int j = 1; j <= num; j++) {
				st = st->next;
			}
		}
		else {
			num = -num;
			for (int j = 1; j <= num; j++) {
				st = st->back;
			}
		}
	}
}