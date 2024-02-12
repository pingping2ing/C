#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s, d, f, w[6][5] = { 0 },g=1,c=0 ;
	char a[100][6], e[6];
	scanf("%d", &s);
	for (d = 0; d < s; d++) { scanf("%s", a[d]); }
	scanf("%s", e);
	for (d = 0; d < 6; d++) {
		for (f = 0; f < 5; f++) {
			w[d][f] = 11;
		}
	}
	for(d=1;d<4;d++){
		for (f = 1; f < 4; f++) {
			w[d][f] = g++;
		}
	}
	w[4][2] = 0; g = 0;
	for (d = 0; d < s; d++) {
		for (f = 0; f < 5; f++) {
			if (a[d][f] != e[f]) {
				for (int r = 1; r < 5; r++) {
					for (int t = 1; t < 4; t++) {
						if (w[r][t]+48 == e[f]) {
							if (w[r - 1][t] + 48 == a[d][f] || w[r + 1][t] + 48 == a[d][f] ||
								w[r][t + 1] + 48 == a[d][f] || w[r][t - 1] + 48 == a[d][f]) g++;
						}
					}
				}
			}
			else c++;
		}
		if (g < 2 && g + c == 5) { printf("OPEN"); break; }
		else if (d == s - 1) printf("CLOSE");
		c = 0; g = 0;
	}
}