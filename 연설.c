#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	char a[300] = { 0 }, stack[300] = { 0 };
	int s = 0, d, f = 0, c = 0, v;
	gets_s(a);
	for (d = 0; d < strlen(a); d++) {
		if (a[d] == '(') stack[s++] = d;
		if (a[d] == ')'&&stack[s - 1] != 0) {
			for (f = stack[--s]; f < d; f++) {
				if (a[f] <= 'Z'&&a[f] >= 'A') a[f] += 32;
				else if (a[f] <= 'z'&& a[f] >= 'a') a[f] -= 32;
			}
		}
	}
	for (d = 0; d < strlen(a); d++) {
		if (a[d] != 40 && a[d] != 41) printf("%c", a[d]);
	}
}