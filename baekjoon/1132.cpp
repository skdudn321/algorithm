#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

typedef pair<long long int, long long int> ii;

vector<ii> temp;
char pro[20];
long long int ans;

int main(void){
	int N;

	scanf("%d\n", &N);

	for (int i = 0; i < 10; i++){
		temp.push_back(ii(0, 0));
	}

	for (int i = 0; i < N; i++){
		scanf("%s\n", pro);
		int len = strlen(pro);
		long long int tt = 1;
		for (int j = len - 1; j >= 0; j--){
			temp[pro[j] - 'A'] = ii(temp[pro[j] - 'A'].first + tt, temp[pro[j] - 'A'].second);
			tt *= 10;
			if (j == 0){
				temp[pro[j] - 'A'] = ii(temp[pro[j] - 'A'].first, 1);
			}
		}
	}

	sort(temp.begin(), temp.end(), greater<ii>());
	ii tet;
	if (temp[temp.size() - 1].first == 0){
		for (vector<ii>::iterator kk = temp.end() - 1; kk >= temp.begin();){
			if ((*kk).first == 0){
				kk--;
				temp.pop_back();
			}
			else{
				break;
			}
		}
	}
	else{
		for (vector<ii>::iterator kk = temp.end() - 1; kk >= temp.begin(); kk--){
			if ((*kk).second == 0){
				tet = *kk;
				temp.erase(kk);
				break;
			}
		}
	}
	temp.push_back(tet);
	for (int i = 0; i < temp.size(); i++){
		ans += (9 - i) * temp[i].first;
	}
	
	printf("%lld", ans);
}