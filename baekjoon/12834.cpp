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

typedef pair<int, int> ii;

int map[1001][1001];
int check[1001];
vector<int> ve;

priority_queue<ii, vector<ii>, greater<ii> > pq;

int main(void) {

	int N, V, E;
	int A, B;
	scanf("%d %d %d %d %d", &N, &V, &E, &A, &B);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		ve.push_back(temp);
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 2000000000;
			}
		}
	}

	for (int i = 1; i <= E; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		map[t1][t2] = t3;
		map[t2][t1] = t3;
	}

	for (int i = 1; i <= V; i++) {
		if (map[A][i] != 2000000000) {
			pq.push(ii(map[A][i], i));
		}
	}
	check[A] = 1;

	while (!pq.empty()) {
		ii temp_i = pq.top();
		pq.pop();
		int index = temp_i.second;
		if (check[index] == 1) {
			continue;
		}
		check[index] = 1;
		for (int i = 1; i <= V; i++) {
			if (map[A][i] > map[A][index] + map[index][i]) {
				map[A][i] = map[A][index] + map[index][i];
				pq.push(ii(map[A][i], i));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		check[i] = 0;
	}
	check[B] = 1;

	for (int i = 1; i <= V; i++) {
		if (map[B][i] != 2000000000) {
			pq.push(ii(map[B][i], i));
		}
	}

	while (!pq.empty()) {
		ii temp_i = pq.top();
		pq.pop();
		int index = temp_i.second;
		if (check[index] == 1) {
			continue;
		}
		check[index] = 1;
		for (int i = 1; i <= V; i++) {
			if (map[B][i] > map[B][index] + map[index][i]) {
				map[B][i] = map[B][index] + map[index][i];
				pq.push(ii(map[B][i], i));
			}
		}
	}

	for (int i = 0; i < ve.size(); i++) {
		if (map[A][ve[i]] == 2000000000) {
			ans -= 1;
		}
		else {
			ans += map[A][ve[i]];
		}
		if (map[B][ve[i]] == 2000000000) {
			ans -= 1;
		}
		else {
			ans += map[B][ve[i]];
		}
	}

	printf("%d", ans);
}