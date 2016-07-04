#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

int check[1001];
int connect[1001][1001];
int first;
queue <int> qu;

void recursion(int num);
void BFS(int num);

int main(void) {
	int V, E;
	int i, temp1, temp2;

	scanf("%d %d %d", &V, &E, &first);
	for (i = 0; i < E; i++) {
		scanf("%d %d", &temp1, &temp2);
		connect[temp1][++connect[temp1][0]] = temp2;
		connect[temp2][++connect[temp2][0]] = temp1;
	}
	for (i = 1; i <= V; i++) {
		if (connect[i][0] > 0) {
			sort(connect[i] + 1, connect[i] + connect[i][0] + 1);
		}
	}

	recursion(first);
	printf("\n");

	for (i = 0; i < 1001; i++) {
		check[i] = 0;
	}

	qu.push(first);
	while (!qu.empty()) {
		BFS(qu.front());
		qu.pop();
	}
}

void recursion(int num) {
	int i;

	if (check[num]) {
		return;
	}

	if (num != first) {
		printf(" ");
	}
	check[num] = 1;
	printf("%d", num);

	for (i = 1; i <= connect[num][0]; i++) {
		recursion(connect[num][i]);
	}
}

void BFS(int num) {
	int i;

	if (check[num]) {
		return;
	}

	if (num != first) {
		printf(" ");
	}
	check[num] = 1;
	printf("%d", num);

	for (i = 1; i <= connect[num][0]; i++) {
		qu.push(connect[num][i]);
	}
}
