#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;
typedef pair<int, int> ii;

ii tree[300000];
ii range[300000];

void range_init(int ind, int st, int la);
void tree_init(int num);
void change(int ind, int num);
ii check(int st, int la, int ind);

int main(void){
	int T;

	range_init(1, 1, 131072);

	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int N, M;
		scanf("%d %d", &N, &M);

		tree_init(N);
		for (int j = 0; j < M; j++){
			int tt[3];
			scanf("%d %d %d", &tt[0], &tt[1], &tt[2]);
			if (tt[0] == 1){
				ii ch_temp = check(tt[1] + 1, tt[2] + 1, 1);
				if (ch_temp.first == tt[1] + 1 && ch_temp.second == tt[2] + 1){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
			}
			else{
				int temp = tree[tt[1] + 131072].first;
				change(tt[1] + 131072, tree[tt[2] + 131072].first);
				change(tt[2] + 131072, temp);
			}
		}
	}
}

void range_init(int ind, int st, int la){
	range[ind] = ii(st, la);
	if (st == la){
		return;
	}
	range_init(ind * 2, st, ((la - st + 1) / 2) + st - 1);
	range_init(ind * 2 + 1, ((la - st + 1) / 2) + st, la);
}
void tree_init(int num){
	for (int i = 1; i <= num; i++){
		change(i + 131071, i);
	}
}
void change(int ind, int num){
	tree[ind] = ii(num, num);
	ind /= 2;
	while (ind >= 1){
		int temp1, temp2;
		if (tree[ind * 2].first == 0 && tree[ind * 2 + 1].first == 0){
			temp1 = 0;
		}
		else if (tree[ind * 2].first == 0){
			temp1 = tree[ind * 2 + 1].first;
		}
		else if (tree[ind * 2 + 1].first == 0){
			temp1 = tree[ind * 2].first;
		}
		else{
			temp1 = min(tree[ind * 2].first, tree[ind * 2 + 1].first);
		}

		if (tree[ind * 2].second == 0 && tree[ind * 2 + 1].second == 0){
			temp2 = 0;
		}
		else if (tree[ind * 2].second == 0){
			temp2 = tree[ind * 2 + 1].second;
		}
		else if (tree[ind * 2 + 1].second == 0){
			temp2 = tree[ind * 2].second;
		}
		else{
			temp2 = max(tree[ind * 2].second, tree[ind * 2 + 1].second);
		}

		tree[ind] = ii(temp1, temp2);
		ind /= 2;
	}
}
ii check(int st, int la, int ind){
	int temp1 = range[ind].first;
	int temp2 = range[ind].second;

	if (temp1 == st && temp2 == la){
		return tree[ind];
	}
	
	if (st <= range[ind * 2].second){
		if (la >= range[ind * 2 + 1].first){
			ii r_temp1 = check(st, range[ind * 2].second, ind * 2);
			ii r_temp2 = check(range[ind * 2 + 1].first, la, ind * 2 + 1);
			return ii(min(r_temp1.first, r_temp2.first), max(r_temp1.second, r_temp2.second));
		}
		else{
			return check(st, la, ind * 2);
		}
	}
	else{
		return check(st, la, ind * 2 + 1);
	}
}