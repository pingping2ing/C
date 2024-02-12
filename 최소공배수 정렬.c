#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int a[101], e[101], s, d, f;
	scanf("%d", &s);scanf("%d", &f);
	for (d = 0; d < s; d++) scanf("%d", &a[d]);
	for (d = 0; d < s; d++) {
		int w = a[d], q = f, r = 0;
		do {
			r = w%q;
			w = q;
			q = r;
		} while (q != 0);
		e[d] = (a[d] * f) / w;
	}
	for (d = s - 1; d > 0; d--) {
		for (int t = 0; t < d; t++) {
			if (e[t] > e[t + 1]) {
				int tmp = e[t];
				e[t] = e[t + 1];
				e[t + 1] = tmp;
			}
		}
	}
	for (d = 0; d < s; d++) {
		printf("%d ", e[d]);
	}
	
}