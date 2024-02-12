#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int s, d, f;
char ar[120000], we[120000];
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	scanf("%s%s", ar, we);
	for (d = 0;; d++) {
		if (ar[d] != we[d] || s == 3) break;
		if (ar[d] == '.' || s > 0) s++;
	}
	if (s == 3) printf("일치");
	else printf("불일치");
}