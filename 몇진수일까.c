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
	
	int s = 0, d, f, a = 0, b = 0, r = 0, c = 0, t, end = 0, arl = 0, wrl = 0;
	char ar[1200] = { 0 }, wr[1200] = { 0 };
	scanf(" %s", ar); scanf(" %s", wr);
	arl = strlen(ar); wrl = strlen(wr);
	for (d = 0; d < arl; d++) {
		if (ar[d] >= 'A') ar[d] -= 7;
		ar[d] -= '0';
		if (a < ar[d]) a = ar[d];
	}
	for (d = 0; d < wrl; d++) {
		if (wr[d] >= 'A') wr[d] -= 7;
		wr[d] -= '0';
		if (b < wr[d]) b = wr[d];
	}
	for (d = a + 1; d < 37; d++) {
		c = 0; s = 0;
		for (f = arl - 1; f >= 0; f--) {
			s += ar[f] * pow(d, c++);
		}
		for (f = b + 1; f < 37; f++) {
			r = 0; c = 0;
			for (t = wrl - 1; t >= 0; t--) {
				r += wr[t] * pow(f, c++);
			}
			if (s == r) { end++; break; }
		} 
		if (end > 0) break;
	}
	if (end > 0) printf("%d %d", d, f);
	else printf("0 0");
}