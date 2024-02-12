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
	
	char ar[1200] = { 0 }, we[1200] = { 0 };
	int s, d, f, wr[1200] = { 0 }, c = 0, n = 0;
	scanf(" %s", &ar); scanf(" %s", &we);
	for (d = strlen(ar) - 1; d >= 0; d--) {
		for (f = strlen(we) - 1; f >= 0; f--) {
			c = strlen(ar) - d + strlen(we) - f - 2;
			wr[c] += (ar[d] - '0') * (we[f] - '0');
			if (wr[c] > 9) {
				wr[c + 1] += wr[c] / 10;
				wr[c] %= 10;
			}
			if (d == 0 && f == 0 && wr[c + 1]) n++;
		}
	}
		if (n > 0) {
			for (d = c + 1; d >= 0; d--) {
				printf("%d", wr[d]);
			}
		}
		else for (d = c; d >= 0; d--) printf("%d", wr[d]);

}