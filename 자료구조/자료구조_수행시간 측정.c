#include <stdio.h>
#include<stdlib.h>
#include<time.h>
double power(int x) {
	int i;
	double result = 1;
	for (i = 0; i < x; i++) {
		result *= 2;
	}
	return result;
}

int main() {
		clock_t start, finish;
		int i, num;
		double n, y=0, duration;
		scanf("%d", &num);
		start = clock();
		n = power(num);
		for (i = 0; i <= n; i++) y += 1;
		finish = clock();
		duration = (double)(finish - start);
		printf("y= %0.f duration= %.0f\n",y,duration);
}