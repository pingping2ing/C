#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	char a[3000] = { 0 }, e[3000] = { 0 }, w[3000] = { 0 };
	int s = 0, d = 0, f = 0, r = 0, q = 0, t = 0, g = 0, c = 0;
	scanf("%s", a);
	scanf("%s", e);
	q = strlen(a); t = strlen(e);
	if (strlen(a) < strlen(e)) {
		r++; char tmp[3000]; strcpy(tmp, a); strcpy(a, e); strcpy(e, tmp);
	}
	else if(q==t) {
		for (d = 0; d < q; d++) {
			if (a[d] != e[d]) {
				if (a[d] < e[d]) {
					r++; char tmp[3000]; strcpy(tmp, a); strcpy(a, e); strcpy(e, tmp);
				}
			}
			if (r > 0) break;
		}
	}
	//a배열이 젤 크다
	q = strlen(a); t = strlen(e);
	char tmp[3000];
	strcpy(tmp, e);
	for (d = q - t; d < q; d++)
		e[d] = tmp[g++];
	for (d = 0; d < q - t; d++) e[d] = '0';
	for (d = 0; d < q; d++) {
		a[d] -= '0';
		e[d] -= '0';
	}
	//문자-> 숫자
	for (d = q - 1; d >= 0; d--) {
		w[s] = a[d] - e[d];
		if (w[s] < 0) {
			for (f = d - 1; f >= 0; f--) {
				if (a[f] != 0) break;
				else a[f] = 9;
			}
			a[f] -= 1;
			w[s] += 10;
		}
		s++;
	}
	for (d = s - 1; d >= 0; d--) {
		if (r != 0) { printf("-"); r = 0; }
		if (d == s - 1 && w[d] == 0) {
			for (t = d; t >= 0; t--) {
				if (t == 0 && w[t] == 0) break;
				if (w[t] != 0) break;
			}
			d = t;
		}
		printf("%c", w[d] + '0');
	}
}