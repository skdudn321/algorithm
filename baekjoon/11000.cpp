#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

typedef struct lesson {
	int start;
	int end;
}lesson;

lesson bae[200000];
priority_queue<int, vector<int>, greater<int>> group;

int compare(const void * a, const void * b);

int main(void) {
	int N, i;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &(bae[i].start), &(bae[i].end));
	}

	qsort(bae, N, sizeof(lesson), compare);
	group.push(bae[0].end);

	for (i = 1; i < N; i++) {
		if (group.top() <= bae[i].start) {
			group.pop();
			group.push(bae[i].end);
		}
		else{
			group.push(bae[i].end);
		}
	}

	printf("%d", group.size());
}

int compare(const void * a, const void * b) {
	if (((lesson *)a)->start > ((lesson *)b)->start) {
		return 1;
	}
	else if (((lesson *)a)->start < ((lesson *)b)->start) {
		return -1;
	}
	else {
		return 0;
	}
}