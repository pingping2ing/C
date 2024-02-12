#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char ar[120][120] = { 0 };
	int s, d, f, t, we[120] = { 0 }, c = 0, e = 0;
	scanf("%d", &s);
	scanf("%d", &t);
	for (d = 0; d < s; d++) {
		scanf("%s", &ar[d]);
	}
	for (d = 0; d < t; d++) {
		for (f = 0; f < s; f++) {
			if (ar[f][d] == '1') c++;
		}
		if (e > c||d==0)e = c;
		we[d] = c;
		c = 0;
	}
	for (d = 0; d < t; d++) {
		for (f = 0; f < s; f++) {
			ar[f][d] = '0';
			if (f >= s - we[d]) ar[f][d] = '1';
		}
	}
	for (d = 0; d < s; d++) {
		for (f = 0; f < t; f++) {
			printf("%c", ar[d][f]);
		}
		printf("\n");
	}
}