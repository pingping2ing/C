#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int s, d, f, ar[1200000] = { 0 };
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/

	scanf("%d", &s);
	for (d = 0; d < s; d++) {
		scanf("%d", &ar[d]);
	}
	for (int k = 0; k < 3; k++) {
		for (d = 0; d < s - 1; d++) {
			for (f = d + 1; f < s; f++) {
				if ((ar[d] /(int)pow(10, k)) % 10 > (ar[f] / (int)pow(10, k)) % 10) {
					int tmp = ar[f];
					ar[f] = ar[d];
					ar[d] = tmp;
				}
				if (k > 0) {
					if ((ar[d] / (int)pow(10, k)) % 10 == (ar[f] / (int)pow(10, k)) % 10 && (ar[d] / (int)pow(10, k - 1)) % 10 > (ar[f] / (int)pow(10, k - 1)) % 10) {
						int tmp = ar[f];
						ar[f] = ar[d];
						ar[d] = tmp;
					}
				}
			}
		}
		for (d = 0; d < s; d++) { printf("%d ", ar[d]); }
		printf("\n");

	}
}