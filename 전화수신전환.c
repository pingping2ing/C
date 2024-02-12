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
	
	int s, d, ar[10000] = { 0 }, a, b, c = 0;

	scanf("%d", &s);
	while (scanf("%d %d", &a, &b) != EOF) {
		ar[a] = b;
	}
	for (d = 0; d < 10000; d++) {
		if (ar[s] == 0) { c = 3; break; }
		if (ar[s] != 2) {
			c= s;
			s = ar[s];
			ar[c] = 2;
		}
		else { c=1; break; }
	}
	if (c == 1) printf("0000");
	if (c == 3) {
		if (s < 10) printf("000%d", s);
		if (s < 100) printf("00%d", s);
		if (s < 1000) printf("0%d", s);
		else printf("%d", s);
	}
}