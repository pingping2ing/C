#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	unsigned long long int r ,f = 0, g = 0;
	int s, d, c = 0;
	char  w[300] = { 0 }, a[300], e[300];
	scanf("%s", a); scanf(" %s", e); scanf("%d", &s);
	for (d = strlen(a) - 1; d >= 0; d--) {
		a[d] -= '0';
		if (a[d] > 9) a[d] -= 7;
		f += pow(16, c)*a[d];
		c++;
	} c = 0;
	for (d = strlen(e) - 1; d >= 0; d--) {
		e[d] -= '0';
		if (e[d] > 9) e[d] -= 7;
		g += pow(16, c)*e[d];
		c++;
	}
	r = f*g;
	for (d = 0;; d++) {
		w[d] = r%s;
		r /= s;
		if (r == 0) break;
	}
	for (s = d; s >= 0; s--) {
		if (w[s] > 9) printf("%c", w[s] + 55);
		else printf("%d", w[s]);
	}
}