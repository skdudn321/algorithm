#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

#define oo 2000000000

using namespace std;

typedef pair<int, int> ii;

vector<ii> map[20001];
priority_queue<ii, vector<ii>, greater<ii> > qu;
int pr[20001];
bool check[20001];

int main(void){
	int V, E, sta;
	scanf("%d %d %d", &V, &E, &sta);

	for (int i = 1; i <= V; i++){
		map[i].push_back(ii(0, i));
		pr[i] = oo;
	}
	pr[sta] = 0;

	for (int i = 0; i < E; i++){
		int x, y, value;
		scanf("%d %d %d", &x, &y, &value);
		if (x == sta){
			pr[y] = min(pr[y], value);
		}
		map[x].push_back(ii(value, y));
	}
	
	for (int i = 1; i <= V; i++){
		if (pr[i] != oo){
			qu.push(ii(pr[i], i));
		}
	}

	for (int i = 1; i <= V; i++){
		check[i] = true;
	}
	check[sta] = false;

	while (!qu.empty()){
		if (!check[qu.top().second]){
			qu.pop();
			continue;
		}
		for (int i = 0; i < map[qu.top().second].size(); i++){
			if (pr[map[qu.top().second][i].second] > pr[qu.top().second] + map[qu.top().second][i].first){
				pr[map[qu.top().second][i].second] = pr[qu.top().second] + map[qu.top().second][i].first;
				qu.push(ii(pr[map[qu.top().second][i].second], map[qu.top().second][i].second));
			}
		}
		check[qu.top().second] = false;
		qu.pop();
	}

	for (int i = 1; i <= V; i++){
		if (pr[i] == oo){
			printf("INF\n");
		}
		else{
			printf("%d\n", pr[i]);
		}
	}
}