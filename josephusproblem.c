#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)

int ar[1200000] = { 0 }, ew[1200000] = { 0 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s, d=0, f = 0, q, w, r, rr = 0, c=1, n=0;
	scanf("%d%d%d", &s, &q, &w); 
	for (d = 0; d < s; d++) ar[d] = d + 1;
	ar[q - 1] = 0; ew[0] = q;
	for (d = q - 1;; d++) {
		 d %= s;
		if (ar[d] > 0) f++;
		if (f == w) {
			f = 0; rr++;
			ar[d] = 0; ew[c++] = d+1;
		}
		if (rr == s-2) break; 
	}
	for (f = 0; f < s-1; f++) printf("%d ", ew[f]);
	for(f=0;f<s-1;f++)
	if(ar[f]>0) printf("\n%d", ar[f]);
}