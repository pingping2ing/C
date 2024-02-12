#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	int s=0, d = 0, f, q, w, e, r = 0, c = 0, t = 1, ra[1200] = {0};
	scanf("%d%d%d", &q, &w, &e); 
	for (d = q ; d < w+1; d++) {
		c = d; t = 1; //c=679
		for (f = 0;; f++) {
			for (r = 0;; r++) {
				t *= (c % 10); 
				c /= 10;
				if (c == 0) break;
			}
			if (t < 10 || t == 0) { break; }
			else { c = t; t = 1; }
		}
		if (f+1 == e) ra[s++] = d;
	} printf("%d", s);
	for (d = 0; d < s; d++) {
		printf("\n%d", ra[d]);
	}
}