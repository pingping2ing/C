#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int s, d, f,r, ar[120000], we[120000], n = 1, e;
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	scanf("%d %d", &s, &r); ar[0] = 0; we[0] = s; f = r / 2 - 5;
	do {
		ar[n] = (s * 10) / r;
		s = (s * 10) % r;
		we[n++] = s;
		if (we[n - 1] == 0) { e = 1; break; }
		for (d = 0; d < n - 1; d++) {
			if (we[d] == we[n - 1]) { e = 2; r = d; break; }
		}
	} while (e == 0);
	if (e == 1) printf("0");
	if (e == 2) {
		for (d = r + 1; d <= n - 1; d++) printf("%d", ar[d]);
	}
}