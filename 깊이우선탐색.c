#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
int s, d, ar[30][30] = { 0 }, t, we[30][30] = { 0 }, c = 0, er[30] = {0};
char e, r, f, q[30] = { 0 };

void rr(int a, int b) {
	if (we[a][b] == 1) return;
	we[a][b] = 1; we[b][a] = 1;
	if(er[a]!=1) printf("%c", a + 65);
	er[a] = 1;
	for (d = 0; d < 26; d++) {
		if (ar[a][d] == 1) rr(d, a);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &s);
	scanf("%d", &t);
	for (d = 0; d < t; d++) {
		scanf(" %c", &e); scanf(" %c", &r);
		ar[e - 65][r - 65] = 1;
		ar[r - 65][e - 65] = 1;
	}
	scanf(" %c", &f);
	rr(f - 65, 0);
}