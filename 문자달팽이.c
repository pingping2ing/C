#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s, d = 1, f = 1, m = 0, e=0,r=0, n = 0;
	char ar[120][120] = { 0 }, q, w;

	scanf("%d", &s); scanf(" %c", &q); scanf(" %c", &w);
	r = w; e = w;
	if (q == 'L') {
		ar[0][s] = ar[s][s + 1] = ar[s + 1][1] = 1;
		do {
			if (e > 'Z') e = 'A';
			ar[d][f] = e++; n++;
			switch (m) {
			case 0: d++; if (ar[d + 1][f] > 0) m = 1; break;
			case 1: f++; if (ar[d][f + 1] > 0) m = 2; break;
			case 2: d--; if (ar[d - 1][f] > 0) m = 3; break;
			case 3: f--; if (ar[d][f - 1] > 0) m = 0; break;
			}
		} while (n< s*s);
	}
	else {
		ar[1][s + 1] = ar[s + 1][s] = ar[s][0] = 1;
		do {
			if (e > 'Z') e = 'A';
			ar[d][f] = e++; n++;
			switch (m) {
			case 0: f++; if (ar[d][f + 1] > 0) m = 1; break;
			case 1: d++; if (ar[d + 1][f] > 0) m = 2; break;
			case 2: f--; if (ar[d][f - 1] > 0) m = 3; break;
			case 3: d--; if (ar[d - 1][f] > 0) m = 0; break;
			}
		} while (n < s*s);
	}
	for (d = 1; d <= s; d++) {
		for (f = 1; f <= s; f++) {
			if (r >= 'A')printf("%2c ", ar[d][f]);
			else printf("%2d ", ar[d][f] - 48);
		}
		printf("\n");
	}
}