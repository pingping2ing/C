#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
int s, d, f, r, ar[1200][1200] = {0},t;
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	scanf("%d%d%d", &t,&s,&r);
	for (d = 1; d <= s; d++) {
		for (f = 1; f <= s; f++) {
			if (d == f) continue;
			ar[d][f] = 1e9;
		}
	} int t1; t = 0;
	for (d = 1; d <= r; d++) {
			scanf("%d%d", &t, &t1);
			ar[t][t1] = 1; ar[t1][t] = 1;
	}
	for (int k = 1; k <= s; k++) {
		for (d = 1; d <= s; d++) {
			for (f = 1; f <= s; f++) {
				if (ar[d][f] > ar[d][k] + ar[k][f])
					ar[d][f] = ar[d][k] + ar[k][f];
			}
		}
	} r = 0;
	for (d = 1; d <= s; d++) {
		r += ar[1][d] + ar[d][1];
	}
	printf("%d", r);
}