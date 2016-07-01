#include<stdio.h>

typedef struct node {
	int parent;
	int length;
	int max;
}node;

node spot[20000];

int main(void) {
	int N;
	int i;
	int a, b, c;
	int max = 0;
	
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		spot[b].max = 0;
		spot[b].parent = a;
		spot[b].length = c;
	}

	for (i = N; i > 1; i--) {
		if (spot[spot[i].parent].max + spot[i].length + spot[i].max > max) {
			max = spot[spot[i].parent].max + spot[i].length + spot[i].max;
		}
		if (spot[spot[i].parent].max < spot[i].length + spot[i].max) {
			spot[spot[i].parent].max = spot[i].length + spot[i].max;
		}
	}

	printf("%d\n", max);
}