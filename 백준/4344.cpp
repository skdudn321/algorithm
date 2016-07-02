#include<stdio.h>

int grade[1000];

int main(void){
	int N;
	int student, high, sum;
	double ha;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &student);
		sum = 0;
		for (int j = 0; j < student; j++){
			scanf("%d", &grade[j]);
			sum += grade[j];
		}
		ha = ((double)sum) / student;
		high = 0;
		for (int j = 0; j < student; j++){
			if (grade[j] > ha){
				high++;
			}
		}
		printf("%.3lf%%\n", (double)high / student * 100);
	}
}