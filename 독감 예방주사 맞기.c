#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int a[1200] = { 0 }, e[1200] = { 0 },
		s, d, f = 1, r, v;
	scanf("%d", &s);
	for (d = 0; d < s; d++) {
		scanf("%d", &a[d]);
	}
	for (d = 0; d < s; d++) {
		if (e[a[d]] > 0) {
			for (r = a[d];; r++) if (e[r] == 0) break;
			for (v = r; v > a[d]; v--) {
				e[v] = e[v - 1];
			}
		}
		e[a[d]] = f++;
	}
	for (d = s-1 ; d >= 0; d--) {
		printf("%d ", e[d]);
	}
}