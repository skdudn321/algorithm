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

vector<ii> ve;
bool check[5];

int main(void){
	int N;

	scanf("%d", &N);
	
	for (int i = 0; i < 6; i++){
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (check[t1] == false){
			check[t1] = true;
			ve.push_back(ii(t1, t2));
		}
		else{
			ve.push_back(ii(t1, t2));
			check[t1] = false;
		}
	}
	
	int ind[2], j = 0;
	for (int i = 0; i < 6; i++){
		if (check[ve[i].first]){
			ind[j++] = i;
		}
	}
	int a, b, c, d;
	if (ind[0] == 0){
		if (ind[1] == 1){
			a = ve[ind[0]].second;
			b = ve[ind[1]].second;
			c = ve[ind[0]].second - ve[ind[1] + 1].second;
			d = ve[ind[1]].second - ve[5].second;
		}
		else{
			a = ve[ind[0]].second;
			b = ve[ind[1]].second;
			c = ve[ind[0]].second - ve[ind[1] - 1].second;
			d = ve[ind[1]].second - ve[ind[0] + 1].second;
		}
	}
	else if (ind[0] == 4){
		a = ve[ind[0]].second;
		b = ve[ind[1]].second;
		c = ve[ind[0]].second - ve[0].second;
		d = ve[ind[1]].second - ve[ind[0] - 1].second;
	}
	else{
		a = ve[ind[0]].second;
		b = ve[ind[1]].second;
		c = ve[ind[0]].second - ve[ind[1] + 1].second;
		d = ve[ind[1]].second - ve[ind[0] - 1].second;
	}

	printf("%d", (a*b - c*d) * N);
}