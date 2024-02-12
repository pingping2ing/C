#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int s, d, f, ar[120000] = { 0 },n=0;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &s);
	for (d = 0; d < s; d++) {
		scanf("%d", &ar[d]);
	}
	for (d = 0; d < s - 1; d++) {
		if (n > 0) {
			for (f = 0; f < s; f++) {
				printf("%d ", ar[f]);
			} printf("\n"); n = 0;
		} 
		for (f = 0; f < s - 1; f++) {
			if (ar[f] > ar[f + 1]) {
				n++;
				int tmp = ar[f];
				ar[f] = ar[f + 1];
				ar[f + 1] = tmp;
			}
		}
	}
}