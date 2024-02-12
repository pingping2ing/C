#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	 
	char a[300], e[300], w[300] = { 0 };
	unsigned long long int s = 0, f = 0, q = 0;
	int v, r, t, d, c = 0, z=0,x=0;
	scanf("%d", &v); scanf("%s", a);
	scanf("%d", &r); scanf("%s", e);
	scanf("%d", &t);

	z = strlen(a); x = strlen(e);

	for (d = 0; d < z; d++) {
		a[d] -= '0';
		if (a[d] > 10) a[d] -= 7;
	}
	for (d = 0; d < x; d++) {
		e[d] -= '0';
		if (e[d] > 10) e[d] -= 7;
	}//문자->숫자
	for (d = 0; d < z; d++) {
	}
	for (d = z - 1; d >= 0; d--) {
		s += pow(v, c)*a[d];
		c++;
		
	} c = 0;
	for (d = x - 1; d >= 0; d--) {
		f += pow(r, c)*e[d];
		c++;
	}
	q = f + s;
	for (d = 0;; d++) {
		w[d] = q%t;
		q /= t;
		if (q == 0) break;
	}
	for (t = d; t >= 0; t--) {
		if (w[t] > 9) printf("%c", w[t] + 55);
		else printf("%d", w[t]);
	}
}