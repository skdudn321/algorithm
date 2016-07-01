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
ii check[500000];
int real[500001];
int runner[1100000];

int find(int ind);
void change(int ind, int num);

int main(void){

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		int temp;
		scanf("%d", &temp);
		check[i] = ii(temp, i);
	}
	
	sort(check, check + N, greater<ii>());
	for (int i = 0; i < N; i++){
		real[check[i].second] = i;
	}

	for (int i = 0; i < N; i++){
		printf("%d\n", find(real[i]) + 1);
		change(real[i] + 524288, 1);
	}
}

int find(int ind){
	if (ind == 0){
		return 0;
	}
	int r_value = 0;
	int first = 262144;
	int temp = first / 2;
	int cur = 1;
	while (true){
		if (ind < first){
			cur *= 2;
			first -= temp;
			temp /= 2;
		}
		else if (ind > first){
			r_value += runner[cur * 2];
			cur = cur * 2 + 1;
			first += temp;
			temp /= 2;
		}
		else{
			r_value += runner[cur * 2];
			break;
		}
	}

	return r_value;
}
void change(int ind, int num){
	while (ind >= 1){
		runner[ind] += num;
		ind /= 2;
	}
}