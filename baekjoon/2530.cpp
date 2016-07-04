#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

int main(void){
	int t, m, s;
	int h;
	scanf("%d %d %d %d", &t, &m, &s, &h);
	t += h / 3600;
	h %= 3600;
	m += h / 60;
	s += h % 60;
	while (s >= 60){
		s -= 60;
		m++;
	}
	while (m >= 60){
		m -= 60;
		t++;
	}
	while (t >= 24){
		t -= 24;
	}
	printf("%d %d %d", t, m, s);
}