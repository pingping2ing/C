#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
int r, l, s, d, f,we[1200],e, wr[1200];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n = 1, m = 1;
	scanf("%d%d%d", &r, &l, &s); we[0] = 0; wr[0] = 0;
	for (d = 1; d <= s; d++) {
		scanf("%d", &e);
		if (e == 0) scanf("%d", &we[n++]);
		else scanf("%d", &wr[m++]);
		if (d == s) {
			we[n] = l; wr[m] = r;
		}
	} s = 0;
	std::sort(we, we + n + 1); 
	std::sort(wr, wr + m+1);
	for (d = 0; d < n; d++) {
		f = we[d+1] - we[d];
		if (e < f) e = f;
	}
	for (d = 0; d < m; d++) {
		f = wr[d + 1] - wr[d];
		if (s < f) s = f;
	}
	printf("%d", s*e);
}