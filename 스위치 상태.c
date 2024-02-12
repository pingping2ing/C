#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s, d, f, ar[1200] = { 0 }, we[1200] = { 0 }, s1,i,j;
	scanf("%d", &s);
	for (d = 1; d <= s; d++) scanf("%d", &ar[d]);
	scanf("%d", &s1);
	for (d = 0; d < s1*2; d++) {
		scanf("%d", &we[d]);
	}
	for (d = 0; d < s1 * 2; d += 2) {
		for (f = 1; f <= s; f++) {
			if (we[d] == 1 && f%we[d + 1] == 0) {
				if (ar[f] == 1) ar[f] = 0;
				else ar[f] = 1;
			}
			else if(we[d]==2&& f==we[d+1]){
				for (i = 0; i <= s; i++) {
					if (f - i - 1 == 0 || f + i + 1 > s) break;
					if (ar[f - i - 1] != ar[f + i + 1]) break;
				}
				for (j = f - i; j <= f + i; j++) {
					if (ar[j] == 1) ar[j] = 0;
					else ar[j] = 1;
				}
			}
		}
	}
	for (d = 1; d <= s; d++) printf("%d ", ar[d]);
}