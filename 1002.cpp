#include<stdio.h>
#include<math.h>

int main(void){
	int N;
	int x1, y1, r1, x2, y2, r2;
	double length;

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		length = sqrt((double)((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));

		if (x1 == x2 && y1 == y2){
			if (r1 == r2){
				printf("-1\n");
			}
			else{
				printf("0\n");
			}
		}
		else{
			if ( (r1 + r2) > length){
				if ( r1 > (r2 + length) ){
					printf("0\n");
				}
				else if ( r2 > (r1+length) ){
					printf("0\n");
				}
				else if (r1 == (r2 + length)){
					printf("1\n");
				}
				else if (r2 == (r1 + length)){
					printf("1\n");
				}
				else{
					printf("2\n");
				}
			}
			else if ((r1 + r2) < length){
				printf("0\n");
			}
			else{
				printf("1\n");
			}
		}
	}
}