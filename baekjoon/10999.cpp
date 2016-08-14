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
typedef pair<lli, lli> ll;

int ans;

ii lor[2100000];
ll index_tree[2100000];
int N, M, K;

void make_lor(int ind, int left, int right);
void change(int ind, int left, int right, lli num);
lli value(int ind, int left, int right);

int main(void) {
	make_lor(1, 1, 1048576);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		change(1, i, i, temp);
	}
	for (int i = 1; i <= M + K; i++) {
		int t1;
		scanf("%d", &t1);
		if (t1 == 1) {
			int t2, t3;
			lli t4;
			scanf("%d %d %lld", &t2, &t3, &t4);
			change(1, t2, t3, t4);
		}
		else {
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%lld\n", value(1, t2, t3));
		}
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

void change(int ind, int left, int right, lli num) {
	if (left == lor[ind].first && right == lor[ind].second) {
		index_tree[ind].second += num;
		ind /= 2;
		while (ind != 0) {
			index_tree[ind].first += num * (right - left + 1);
			ind /= 2;
		}
		return;
	}

	int mid = (lor[ind].first + lor[ind].second) / 2;
	if (left > mid) {
		change(ind * 2 + 1, left, right, num);
	}
	else if (right <= mid) {
		change(ind * 2, left, right, num);
	}
	else {
		change(ind * 2, left, mid, num);
		change(ind * 2 + 1, mid + 1, right, num);
	}
}

lli value(int ind, int left, int right) {
	if (left == lor[ind].first && right == lor[ind].second) {
		lli ret = index_tree[ind].first + index_tree[ind].second * (right - left + 1);
		return ret;
	}

	lli ret = 0;
	
	int mid = (lor[ind].first + lor[ind].second) / 2;
	if (index_tree[ind].second != 0) {
		index_tree[ind].first += index_tree[ind].second * (lor[ind].second - lor[ind].first + 1);
		index_tree[ind * 2].second += index_tree[ind].second;
		index_tree[ind * 2 + 1].second += index_tree[ind].second;
		index_tree[ind].second = 0;
	}
	if (left > mid) {
		ret = value(ind * 2 + 1, left, right);
	}
	else if (right <= mid) {
		ret = value(ind * 2, left, right);
	}
	else {
		ret = value(ind * 2, left, mid) + value(ind * 2 + 1, mid + 1, right);
	}

	return ret;
}