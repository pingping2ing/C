#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	char a[300] = {0};
	int s, d, f;
	scanf("%d", &s); scanf("%d", &f);
	for (d = 0; d < 22; d++) {
		a[d] = s / f;
		if (d == 21&&a[d]>=5) {
			for (int t = d;t>0;t--) {
				a[t-1] += 1;
				if (a[t - 1] > 9) a[t - 1] = 0;
				else {
					break;
				}
			}
		}
		s = s%f * 10;
	}
	for (d = 0; d < 21; d++) {
		if (d == 0) printf("%d.", a[d]);
		else printf("%d", a[d]);
	}
}