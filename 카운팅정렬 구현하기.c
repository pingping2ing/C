#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int s, d, f, ar[120000] = { 0 }, n = 0, we[120000] = { 0 }, wr[120000] = { 0 }, ekq[120000] = {0};
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &s);
	for (d = 0; d < s; d++) { scanf("%d", &ar[d]); 
	wr[ar[d]]++;
	if (n < ar[d]) n = ar[d]; 
	}
	for (d = 0; d <= n; d++) {
		for (f = 0; f <= d; f++) {
			we[d] += wr[f];
		}
	}
	for (d = s-1; d >= 0;d--) {
		ekq[we[ar[d]]] = ar[d]; we[ar[d]]--;
		for (f = 1; f <= s; f++)printf("%d ", ekq[f]); printf("\n");
	}

}