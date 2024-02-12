#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s, d, f, ar[150][150] = { 0 }, c = 0, r[150][150] = { 0 };
	char path[99999] = { 0 };
	scanf("%d", &s);
	for (d = 1; d <= s; d++) {
		for (f = 1; f <= s; f++) {
			scanf("%d", &ar[d][f]);
		}
	}
	for (d = 1; d <= s; d++) {
		for (f = 1; f <= s; f++) {
			if (r[d - 1][f] > r[d][f - 1]) {
				r[d][f] = r[d - 1][f];

			}
			else {
				r[d][f] = r[d][f - 1];
			}
			r[d][f] += ar[d][f];
		}
	} d = 1; f = 1;
	do {
		if (r[d + 1][f] > r[d][f + 1]) {
			path[c] = 'D';
			d = d + 1;
		}
		else {
			path[c] = 'R';
			f = f + 1;
		}
		c++;
	} while (d != s);
	printf("%d\n", r[s][s]);
	for (d = 0; d < strlen(path); d++) { printf("%c\n", path[d]); }
}