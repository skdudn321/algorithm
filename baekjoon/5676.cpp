#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

int ans;

int index_tree[300000];
ii lor[300000];

int N, K;

void make_lor(int ind, int left, int right);
void change(int ind, int value);
int value(int ind, int left, int right);

int main(void) {
	freopen("test.txt", "r", stdin);
	make_lor(1, 1, 131072);
	while ( scanf("%d %d", &N, &K) != EOF ) {
		/*
		for (int i = 0; i < 300000; i++) {
			index_tree[i] = 0;
		}
		*/
		for (int i = 1; i <= N; i++) {
			int temp;
			scanf("%d", &temp);
			if (temp > 0) {
				temp = 1;
			}
			else if (temp == 0) {
				temp = 0;
			}
			else {
				temp = -1;
			}
			change(i, temp);
		}
		getchar();
		for (int i = 1; i <= K; i++) {
			char t1;
			int t2, t3;
			scanf("%c %d %d\n", &t1, &t2, &t3);
			if (t1 == 'P') {
				int ret = value(1, t2, t3);
				if (ret == 1) {
					printf("+");
				}
				else if (ret == 0) {
					printf("0");
				}
				else {
					printf("-");
				}
			}
			else {
				if (t3 > 0) {
					t3 = 1;
				}
				else if (t3 == 0) {
					t3 = 0;
				}
				else {
					t3 = -1;
				}
				change(t2, t3);
			}
		}
		printf("\n");
	}
}

void make_lor(int ind, int left, int right) {
	lor[ind] = ii(left, right);

	if (left == right) {
		return;
	}
	int mid = (left + right) / 2;

	make_lor(ind * 2, left, mid);
	make_lor(ind * 2 + 1, mid + 1, right);
}

void change(int ind, int value) {
	ind += 131071;
	if (index_tree[ind] == value) {
		return;
	}
	index_tree[ind] = value;
	ind /= 2;
	while (ind != 0) {
		index_tree[ind] = index_tree[ind * 2] * index_tree[ind * 2 + 1];
		ind /= 2;
	}
}

int value(int ind, int left, int right) {
	if (lor[ind].first == left && lor[ind].second == right) {
		return index_tree[ind];
	}

	int ret;
	int mid = (lor[ind].first + lor[ind].second) / 2;
	if (left > mid) {
		ret = value(ind * 2 + 1, left, right);
	}
	else if (right <= mid) {
		ret = value(ind * 2, left, right);
	}
	else {
		ret = value(ind * 2, left, mid) * value(ind * 2 + 1, mid + 1, right);
	}
	return ret;
}