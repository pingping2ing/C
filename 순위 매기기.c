#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s, d, f,r=0, a[3200] = { 0 }, e[3200] = { 0 };
	scanf("%d", &s);
	for (d = 0; d < s; d++) {
		scanf("%d", &a[d]);
		e[d] = a[d];
	}
	for (d = s - 1; d > 0; d--) {
		for (f = 0; f < d; f++) {
			if (e[f] > e[f + 1]) {
				int tmp = e[f];
				e[f] = e[f + 1];
				e[f + 1] = tmp;
			}
		}
	}
	for (d = 0; d < s; d++) {
		printf("%d ", a[d]);
	}
	printf("\n");
	for (d = 0; d < s; d++) {
		for (f = 0; f < s; f++) {
			if (a[d] == e[f] && r == 0) {
				printf("%2d ", f + 1);
				r++;
			}
		}
		r = 0;
	}
}