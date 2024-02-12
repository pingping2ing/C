#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int main() {
	while (1) {
		int s, d, i = 0, r = 0;
		char w;
		scanf("%d%c%d", &s, &w, &d);
		r = d;
		printf("gcd(%d,%d)", s, d);
		while (d != 0) {
			r = s;
			s = d;
			d = r%d;
			printf("=>gcd(%d,%d)", s, d);
		}
		printf("\n");
	}
}