#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)

int white, blue;
int s, d, f, a[202][202] = { 0 };

void solve(int y, int x, int n) {
	int i, j;
	for (i = y; i < y + n; i++) {
		for (j = x; j < x + n; j++) {
			if (a[y][x] != a[i][j]) break;
		}
		if (j < x + n) break;
	}
	if (i < y + n) {
		solve(y, x, n / 2);
		solve(y + n / 2, x, n / 2);
		solve(y, x + n / 2, n / 2);
		solve(y + n / 2, x + n / 2, n / 2);
	}
	else {
		if (a[y][x] == 0) white++;
		else blue++;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &s);
	for (d = 0; d < s; d++) {
		for (f = 0; f < s; f++) {
			scanf("%d", &a[d][f]);
		}
	}
	solve(0, 0, s);
	printf("%d\n%d", white, blue);
}