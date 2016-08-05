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
lli index_tree[2100000];
ii lr[2100000];
int N, M, K;

void update(int ind, lli num);
lli value(int ind, int left, int right);
void make_lr(int ind, int le, int ri);

int main(void) {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		lli temp;
		scanf("%lld", &temp);
		update(i, temp);
	}
	make_lr(1, 1, 1048576);
	
	for (int i = 1; i <= M + K; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 1) {
			update(t2, t3);
		}
		else {
			printf("%lld\n", value(1, t2, t3));
		}
	}
}

void update(int ind, lli num) {
	ind += 1048575;
	index_tree[ind] = num;

	ind /= 2;
	while (ind != 0) {
		index_tree[ind] = index_tree[ind * 2] + index_tree[ind * 2 + 1];
		ind /= 2;
	}
}

void make_lr(int ind, int le, int ri) {
	lr[ind] = ii(le, ri);
	int mid = ((ri - le) / 2) + le;
	if (le == ri) {
		return;
	}
	make_lr(ind * 2, le, mid);
	make_lr(ind * 2 + 1, mid + 1, ri);
}

lli value(int ind, int left, int right) {
	int mid = (lr[ind].second - lr[ind].first) / 2 + lr[ind].first;

	if (lr[ind].first == left && lr[ind].second == right) {
		return index_tree[ind];
	}
	lli ret;
	if (left > mid) {
		ret = value(ind * 2 + 1, left, right);
	}
	else if(right <= mid){
		ret = value(ind * 2, left, right);
	}
	else {
		ret = value(ind * 2, left, mid) + value(ind * 2 + 1, mid + 1, right);
	}

	return ret;
}