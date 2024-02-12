#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	long long int ar[1200] = { 0 }, s, d, f, r = 0;
	scanf("%lld", &s);
	for (d = 0; d < s; d++) scanf("%lld", &ar[d]);
	for (f = 0; f < s - 1; f++) {
		if (ar[f] > ar[f + 1])  r = ar[f + 1];
		else r = ar[f];
		for (d = r; d > 0; d--) {
			if (ar[f] % d == 0 && ar[f + 1] % d == 0)break;
		}
		ar[f + 1] = (ar[f] * ar[f + 1]) / d; 
	}
	printf("%lld", ar[s - 1]); 
}