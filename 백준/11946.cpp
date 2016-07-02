#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<tuple>

using namespace std;

typedef tuple<int, int, int> ii;

bool cor[101][20];
int score[101][20];
ii num[101];
bool comp(ii a, ii b);

int main(void){
	int N, M, Q;

	scanf("%d %d %d", &N, &M, &Q);

	for (int i = 0; i < Q; i++){
		int t1, t2, t3;
		char str[5];
		scanf("%d %d %d %s", &t1, &t2, &t3, str);
		if (strcmp(str, "AC") == 0){
			if (cor[t2][t3] == false){
				cor[t2][t3] = true;
				score[t2][t3] += t1;
			}
		}
		else{
			if (cor[t2][t3] == false){
				score[t2][t3] += 20;
			}
		}
	}

	for (int i = 1; i <= N; i++){
		int all_cor = 0, all_time = 0;
		for (int j = 1; j <= M; j++){
			if (cor[i][j]){
				all_cor++;
				all_time += score[i][j];
			}
		}
		num[i] = ii(all_cor, all_time, i);
	}

	sort(num + 1, num + N + 1, comp);
	
	for (int i = 1; i <= N; i++){
		printf("%d %d %d\n", get<2>(num[i]), get<0>(num[i]), get<1>(num[i]));
	}
}

bool comp(ii a, ii b){
	if (get<0>(a) > get<0>(b)){
		return true;
	}
	else if (get<0>(a) < get<0>(b)){
		return false;
	}
	else{
		if (get<1>(a) > get<1>(b)){
			return false;
		}
		else if (get<1>(a) < get<1>(b)){
			return true;
		}
		else{
			return get<2>(a) < get<2>(b);
		}
	}
}