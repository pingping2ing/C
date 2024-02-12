#include <stdio.h>

int main() {
	int n, m, card[105] = { 0 },i,j,k,ans=0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)scanf("%d", &card[i]);
	for (i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (card[j] > card[j + 1]) {
				ans = card[j];
				card[j] = card[j + 1];
				card[j + 1] = ans;
			}
		}
	}
	ans = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++) {
				if (card[i] + card[j] + card[k] > m) continue;
				else if (m - (card[i] + card[j] + card[k]) < m - ans)
					ans = card[i] + card[j] + card[k];
			}
		}
	}
	printf("%d", ans);

}