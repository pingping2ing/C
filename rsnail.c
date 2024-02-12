
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int a[30][30] = { 0 };
	int s, d=1, f=1,n=1,r=0;
	scanf("%d", &s);
	a[s + 1][1] = 1;
	a[s][s + 1] = 1;
	a[0][s] = 1;
	do {
		a[d][f] = n++;
		switch (r) {
		case 0: d++; if (a[d + 1][f] > 0) r = 1; break;
		case 1: f++; if (a[d][f + 1] > 0) r = 2; break;
		case 2: d--; if (a[d - 1][f] > 0) r = 3; break;
		case 3: f--; if (a[d][f - 1] > 0) r = 0; break;
		}
	} while (n <= s*s);
	for (d = 1; d <= s; d++) {
		for (f = 1; f <= s; f++) {
			printf("%d ", a[d][f]);
		}
		printf("\n");
	}
}