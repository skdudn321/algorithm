#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<tuple>
#include<functional>

using namespace std;

typedef tuple<int, int, int> ii;

int sum;
int cur;
int cur_sum;
int temp_color;

ii ball[200001];
int color[200001];
int out[200001];

int main(void){
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		ball[i] = ii(b, a, i);
	}

	sort(ball, ball + N);

	for (int i = 0; i < N; i++){
		if (cur != get<0>(ball[i])){
			out[get<2>(ball[i])] = sum - color[get<1>(ball[i])];
			cur = get<0>(ball[i]);
			cur_sum = sum;
			temp_color = 0;
		}
		else{
			if (get<1>(ball[i - 1]) != get<1>(ball[i])){
				temp_color = 0;
			}
			out[get<2>(ball[i])] = cur_sum - color[get<1>(ball[i])] + temp_color;
		}
		sum += get<0>(ball[i]);
		color[get<1>(ball[i])] += get<0>(ball[i]);
		temp_color += get<0>(ball[i]);
	}

	for (int i = 0; i < N; i++){
		printf("%d\n", out[i]);
	}
}