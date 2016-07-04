#include<stdio.h>
#include<math.h>

int main(void){
	int a, b, c;
	double num1;

	scanf("%d %d %d", &a, &b, &c);

	num1 = sqrt((double)((b*b) + (c*c)));
	b *= a;
	c *= a;
	b /= num1;
	c /= num1;

	printf("%d %d", b, c);
}