#include<stdio.h>
#include<vector>

using namespace std;

vector<int> ve[10];

int main(void){
	int N;
	int a, b, temp;

	scanf("%d", &N);

	ve[0].push_back(10);
	ve[1].push_back(1);
	ve[2].push_back(2);
	ve[2].push_back(4);
	ve[2].push_back(8);
	ve[2].push_back(6);
	ve[3].push_back(3);
	ve[3].push_back(9);
	ve[3].push_back(7);
	ve[3].push_back(1);
	ve[4].push_back(4);
	ve[4].push_back(6);
	ve[5].push_back(5);
	ve[6].push_back(6);
	ve[7].push_back(7);
	ve[7].push_back(9);
	ve[7].push_back(3);
	ve[7].push_back(1);
	ve[8].push_back(8);
	ve[8].push_back(4);
	ve[8].push_back(2);
	ve[8].push_back(6);
	ve[9].push_back(9);
	ve[9].push_back(1);

	for (int i = 0; i < N; i++){
		scanf("%d %d", &a, &b);
		a %= 10;
		if (b % ve[a].size() == 0){
			temp = ve[a].size() - 1;
		}
		else{
			temp = (b%ve[a].size()) - 1;
		}
		printf("%d\n", ve[a][temp]);
	}
}