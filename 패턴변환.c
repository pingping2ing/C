#include<stdio.h>
#pragma warning(disable:4996)


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s, d, f, c[10] = { 0 }, rr=0;
	char ar[12][12] = { 0 }, we[12][12] = { 0 };
	scanf("%d", &s);
	for (d = 0; d < s; d++) {
		for (f = 0; f < s; f++) {
			scanf(" %c", &ar[d][f]);
		}
	}
	for (d = 0; d < s; d++) {
		for (f = 0; f < s; f++) {
			scanf(" %c", &we[d][f]);
		}
	}
	for (d = 0; d < s; d++) {
		for (f = 0; f < s; f++) {
			if (ar[d][f] == we[f][s-d-1]) c[1]++;
			if (ar[d][f] == we[s - d - 1][s - f - 1])c[2]++;
			if (ar[d][f] == we[s - f - 1][d]) c[3]++;
			if (ar[d][f] == we[d][s - f - 1]) c[4]++;
			if (ar[d][f] == we[s - f - 1][s - d - 1]) c[5]++;
			if (ar[d][f] == we[s - d - 1][f]) c[6]++;
			if (ar[d][f] == we[f][d]) c[7]++;

		}
	}
	for (d = 0; d < 10; d++) {
		if (c[d] == s*s) {
			if (d >= 5) printf("5");
			else printf("%d", d);
			break;
		}
		if (d > 7) {
			for (f = 0; f < s; f++) {
				for (int t = 0; t < s; t++) {
					if (ar[f][t] == we[f][t]) rr++;
				}
			}
			if (rr == s*s) { printf("6"); break; }
		}
	}
	if (d == 10) printf("7");
}