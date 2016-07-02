#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> ve;

int main(void){
	int N;
	int i;
	int temp;

	scanf("%d", &N);

	scanf("%d", &temp);
	ve.push_back(temp);
	for (i = 1; i < N; i++){
		scanf("%d", &temp);
		if (temp > ve.back()){
			ve.push_back(temp);
		}
		else{
			ve.erase(lower_bound(ve.begin(), ve.end(), temp));
			ve.insert(lower_bound(ve.begin(), ve.end(), temp), temp);
		}
	}

	printf("%d", ve.size());
}