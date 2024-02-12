#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
int s, d, t, ar[30][30] = { 0 }, c = 0, we[26] = { 0 };
char f, e;
void rr(int a) {
	if (we[a] == 1) return;
	we[a] = 1;
	printf("%c", a + 65);
	for (d = 0; d < 26; d++) {
		if (ar[a][d] == 1)  rr(d);
	}
}

int main() {
	/*freopen("input.txt", "r", stdin);
	   freopen("output.txt", "w", stdout);
   */
	for (d = 0; d < 26; d++) {
		for (f = 0; f < 26; f++) {
			ar[d][f] = -1;
		}
	}
	scanf("%d", &s); scanf("%d", &t);
	for (d = 0; d < t; d++) {
		scanf(" %c", &f);
		scanf(" %c", &e);
		ar[f - 65][e - 65] = 1;
		ar[e - 65][f - 65] = 1;
	}
	
	scanf(" %c", &f);
	rr(f - 65); printf("\n");
	for (d = 0; d < 26; d++) {
		for (f = 0; f < 26; f++) {
			printf("%3d", ar[d][f]);
		}
		printf("\n");
	}
}