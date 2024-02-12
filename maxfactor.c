#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
int ar[1200] = { 0 };
bool we[1000000] = { 0 };

bool des(int a, int b) {
	return a > b;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s, d, f, w = 0, e = 0;
	scanf("%d", &s);
	for (d = 0; d < s; d++) {
		scanf("%d", &ar[d]);
		if (w < ar[d]) w = ar[d];//가장 큰 수 찾기
	}
	std::sort(ar, ar + s, des);
	for (d = 2; d <= sqrt(w); d++) {
		if (we[d] == 1) continue;
		for (f = d + d; f <= w; f += d) {
			we[f] = 1;
		}
	}
	for (d = 0; d < s; d++) {
		for (f = 2; f <= w; f++) {
			if (we[f] == 0 && ar[d] % f == 0) {
				if (e < f) e = f;
			}
		}
		if (e > ar[d + 1]) break;
	}
	for (d = 0; d < s; d++) {
		if (ar[d] % e == 0) printf("%d", ar[d]);
	}
}