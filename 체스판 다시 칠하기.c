#include <stdio.h>

int main() {
	int n, m, i, j, wcnt = 0, bcnt = 0, ans = 2501;
	char chess[55][55] = { 0 };

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf(" %c", &chess[i][j]);
		}
	}
	for (i = 0; i <= n - 8; i++) {
		for (j = 0; j <= m - 8; j++) {
			wcnt = 0;
			bcnt = 0;
			for (int w = i; w < i + 8; w++) {
				for (int e = j; e < j + 8; e++) {
					if ((w + e) % 2 == 0) {
						if (chess[w][e] == 'W') wcnt++;
						else bcnt++;
					}
					else {
						if (chess[w][e] == 'W') bcnt++;
						else wcnt++;
					}
				}
			}
			if (wcnt >= bcnt&&ans > bcnt) ans = bcnt;
			if (bcnt > wcnt&&ans > wcnt) ans = wcnt;
		}

	}
	printf("%d", ans);
}