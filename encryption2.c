#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	char a[300] = { 0 }, e[100][7] = { 0 };
	int s, d, f = 0, w = 0, r = 0;
	gets_s(a);
	for (d = 0; d < strlen(a); d++) if (a[d] == '*') r = 1;
	if (strlen(a) % 6 == 0) f = strlen(a) / 6;
	else f = strlen(a) / 6 + 1;
	if (r != 1) {
		for (s = 0; s < strlen(a); s++) {
			if (a[s] == ' ') a[s] = '*';
		}
		for (s = strlen(a); s < f * 6; s++) {
			a[s] = '.';
		}
		for (s = 0; s < f; s++) {
			for (d = 0; d < 6; d++) {
				e[s][d] = a[w++];
			}
		}
		for (s = 0; s < 6; s++) {
			for (d = 0; d < f; d++) {
				printf("%c", e[d][s]);
			}
		}
	}
	else {
		for (s = 0; s < strlen(a); s++) { if (a[s] == '*') a[s] = ' '; }
		for (s = 0; s < 6; s++) {
			for (d = 0; d < strlen(a) / 6; d++) {
				e[d][s] = a[w++];
			}
		}
		for (s = 0; s < strlen(a) / 6; s++) {
			for (d = 0; d < 6; d++) {
				if (e[s][d] != '.')printf("%c", e[s][d]);
			}
		}
	}

}