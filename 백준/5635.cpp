#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<tuple>

using namespace std;

typedef tuple<int, int, int> ii;

char str_o[1000];
char str_y[1000];
char str_t[1000];
ii yy;
ii oo;
ii tt;

int main(void){
	int T, dd, mm, yyyy;

	scanf("%d\n", &T);

	scanf("%s %d %d %d\n", str_t, &dd, &mm, &yyyy);
	strcpy(str_o, str_t);
	strcpy(str_y, str_t);
	yy = ii(dd, mm, yyyy);
	oo = ii(dd, mm, yyyy);
	for (int i = 1; i < T; i++){
		scanf("%s %d %d %d\n", str_t, &dd, &mm, &yyyy);
		if (get<2>(yy) > yyyy){
			yy = ii(dd, mm, yyyy);
			strcpy(str_y, str_t);
		}
		else if (get<2>(yy) == yyyy){
			if (get<1>(yy) > mm){
				yy = ii(dd, mm, yyyy);
				strcpy(str_y, str_t);
			}
			else if (get<1>(yy) == mm){
				if (get<0>(yy) > dd){
					yy = ii(dd, mm, yyyy);
					strcpy(str_y, str_t);
				}
			}
		}
		if (get<2>(oo) < yyyy){
			oo = ii(dd, mm, yyyy);
			strcpy(str_o, str_t);
		}
		else if (get<2>(oo) == yyyy){
			if (get<1>(oo) < mm){
				oo = ii(dd, mm, yyyy);
				strcpy(str_o, str_t);
			}
			else if (get<1>(oo) == mm){
				if (get<0>(oo) < dd){
					oo = ii(dd, mm, yyyy);
					strcpy(str_o, str_t);
				}
			}
		}
	}
	printf("%s\n%s", str_o, str_y);
}