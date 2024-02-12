#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
int s, d, f, ar[1200] = { 0 }, arr[1200][23] = { 0 }, len[1200] = {0}, cnt;
void rr(int n, int sum, int ln) {
	if (sum == n) {
		for (int i = 0; i < ln; i++) {
			arr[cnt][i] = ar[i];
		}
		len[cnt] = ln;
		cnt++; return;
	}
	for (int i = n - 1; i > 0; i--) {
		if ((ln == 0 || ar[ln - 1] >= i) &&sum + i <= n) {
			ar[ln] = i;
			rr(n, sum + i, ln + 1);
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &s);
	rr(s, 0, 0);
	printf("%d\n", cnt);
	for (d = 0; d < cnt; d++) {
		printf("%d", arr[d][0]);
		for (f = 1; f < len[d]; f++) {
			printf("+%d", arr[d][f]);
		}
		printf("\n");
	}
}