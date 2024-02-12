#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int s, d, f,r,e,n; 
int main() {
	scanf("%d%d", &s, &f);
	for (d = s; d <= f; d++) {
		e = d;
		for (int k = 0;; k++) {
			r = e % 10;
			if (r % 3 == 0&& r!=0) { printf("r= %d\n", r); n++; }
			e /= 10;
			if (e == 0) break;
		}
	}
	printf("%d", n);
}