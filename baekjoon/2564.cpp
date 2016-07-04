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
ii map[101];
ii me;

int main(void){
	int N, M, T;
	int i, j, k;
	int sum = 0;

	scanf("%d %d", &N, &M);
	scanf("%d", &T);
	for (i = 0; i < T; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		map[i] = ii(a, b);
	}
	scanf("%d %d", &i, &j);
	me = ii(i, j);

	for (i = 0; i < T; i++){
		if (me.first == 1){
			if (map[i].first == 1){
				sum += max(me.second - map[i].second, map[i].second - me.second);
			}
			else if (map[i].first == 2){
				sum += M + min(me.second + map[i].second, N + N - me.second - map[i].second);
			}
			else if (map[i].first == 3){
				sum += me.second + map[i].second;
			}
			else if (map[i].first == 4){
				sum += map[i].second + N - me.second;
			}
		}
		else if (me.first == 2){
			if (map[i].first == 1){
				sum += M + min(me.second + map[i].second, N + N - me.second - map[i].second);
			}
			else if (map[i].first == 2){
				sum += max(me.second - map[i].second, map[i].second - me.second);
			}
			else if (map[i].first == 3){
				sum += me.second + M - map[i].second;
			}
			else if (map[i].first == 4){
				sum += M - map[i].second + N - me.second;
			}
		}
		else if (me.first == 3){
			if (map[i].first == 1){
				sum += me.second + map[i].second;
			}
			else if (map[i].first == 2){
				sum += M - me.second + map[i].second;
			}
			else if (map[i].first == 3){
				sum += max(me.second - map[i].second, map[i].second - me.second);
			}
			else if (map[i].first == 4){
				sum += N + min(me.second + map[i].second, M + M - me.second - map[i].second);
			}
		}
		else if (me.first == 4){
			if (map[i].first == 1){
				sum += me.second + N - map[i].second;
			}
			else if (map[i].first == 2){
				sum += M - me.second + N - map[i].second;
			}
			else if (map[i].first == 3){
				sum += N + min(me.second + map[i].second, M + M - me.second - map[i].second);
			}
			else if (map[i].first == 4){
				sum += max(me.second - map[i].second, map[i].second - me.second);
			}
		}
	}
	printf("%d", sum);
}