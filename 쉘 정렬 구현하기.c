#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	int s, d, f, ar[120] = { 0 }, n[120] = { 0 }, c = 0;
	scanf("%d", &s);
	for (d = 0; d < s; d++) {
		scanf("%d", &ar[d]);
	}
	for (d = 0;; d++) {
		if (s < 1 + ((pow(3, d + 1) - 3) / 2)) break;
		n[d] = 1 + (pow(3, d + 1) - 3) / 2;
	} c = d - 1;
	
	for (int k = c; k >= 0; k--) {
		if (k == 0) {
				std::sort(ar, ar + s);
				for (int i = 0; i < s; i++)
					printf("%d ", ar[i]);
				break;
		}
		for (d = 0; d < n[c]; d++) {
			for (f = 0; f < s; f++) {
				printf("%d ", ar[f]);
			} printf("\n");
			for (f = 0; f < s; f++) {
				if (f + n[c] >= s) break;
				if (ar[f] > ar[f + n[c]] && f%n[c] == d) {
					int tmp = ar[f];
					ar[f] = ar[f + n[c]];
					ar[f + n[c]] = tmp;
				}
			}
		}
	}
}