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

	int ar[150] = { 0 }, s, d, f, c = 0, n[150] = { 0 }, r=0, rr = 0;
	scanf("%d", &s);
	for (d = 0; d < s; d++) { scanf("%d", &ar[d]); n[d] = d+1; }
	do {
		rr = 0; r = 0;
		for (d = 0; d < s; d++) {
			c = 0;
			for (f = 0; f < s; f++) {
				if ((n[d] > 0) && (n[d] == ar[f])) c++;
			}
			if (c == 0) {
				n[d] = 0; ar[d] = 0;
			}
			else if (n[d] > 0) rr++;
		}
		for (d = 0; d < s; d++) {
			c = 0;
			for (f = 0; f < s; f++) {
				if ((n[d] > 0) && (n[d] == ar[f])) c++;
			}
			if (c > 0) r++;
	}
	} while (rr != r);
	printf("%d\n", rr);
	for (d = 0; d < s; d++) if (n[d] > 0) printf("%d\n", n[d]);
}