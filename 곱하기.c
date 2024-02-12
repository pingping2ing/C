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
	
	__int64 a[200] = { 0 }, e[200] = { 0 }, s = 0, f = 0, g = 0;
	char w[200] = { 0 }, r[200] = { 0 }, t[200] = { 0 };
	int wl = 0, rl = 0, tl = 0, q, d = 0, c = 0, v = 0;

	scanf("%s", w); scanf("%s", r); scanf("%s", t);
	wl = strlen(w); rl = strlen(r); tl = strlen(t);

	for (d = 0; d < wl; d++) {
		if (w[d] >= 'A') w[d] = w[d] - 'A' + ':';
		w[d] -= '0';
	}
	for (d = 0; d < rl; d++) {
		if (r[d] >= 'A') r[d] = r[d] - 'A' + ':';
		r[d] -= '0';
	}
	for (d = 0; d < tl; d++) {
		if (t[d] >= 'A') t[d] = t[d] - 'A' + ':';
		t[d] -= '0';
	}
	for (q = 2; q < 17; q++) {
		s = 0; f = 0; g = 0;
		for (d = 0; d < 150; d++) {
			if (q <= w[d] || q <= r[d] || q <= t[d]) c++;
		}
		if (c == 0) {
			for (d = wl - 1; d >= 0; d--) {
				s += pow(q, wl - d - 1)*w[d];
			}
			for (d = rl - 1; d >= 0; d--) {
				f += pow(q, rl - d - 1)*r[d];
			}
			for (d = tl - 1; d >= 0; d--) {
				g += pow(q, tl - d - 1)*t[d];
			}
			if (s*f == g) { printf("%d", q); v++; break; }
		} c = 0;
	}
	if (v == 0) printf("0");
}