#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int a[500] = { 0 };
	int s, d, f;
	a[0] = 1; a[1] = 1;
	scanf("%d", &s);
	for (d = 0; d < s-2; d++) {
		a[d + 2] += a[d] + a[d + 1];
	}
	printf("%d", a[s - 1]);
 }