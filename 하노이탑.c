#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
int s, d, f,  e[120] = { 0 }, n=0,c=0;
char ar[30][3999999] = { 0 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &s);
	e[0] = 1;
	for (d = 1; d < s; d++) {
		e[d] = 2 * e[d - 1] + 1;
	}
	printf("%d\n", e[s - 1]);
	ar[0][0] = 'A'; ar[0][1] = 'C';
	for (d = 1; d < s; d++) {
		for (f = 0; f < 2 * e[d - 1]; f++) {
			if (ar[d - 1][f] == 'C') ar[d][f] = 'B';
			else if (ar[d - 1][f] == 'B') ar[d][f] = 'C';
			else ar[d][f] = ar[d - 1][f];
		} ar[d][f] = 'A'; ar[d][f + 1] = 'C'; c = 0;
		for (f = 2 * e[d - 1] + 2; f < 2 * e[d]; f++) {
			if (ar[d - 1][c] == 'A') ar[d][f] = 'B';
			else if (ar[d - 1][c] == 'B') ar[d][f] = 'A';
			else ar[d][f] = ar[d - 1][c];
			c++;
		}
	}
	for (d = 0; d < 2 * e[s - 1]; d++) {
		n++; printf("%c ", ar[s - 1][d]);
		if (n == 2) {
			printf("\n"); n = 0;
		}
	}
}