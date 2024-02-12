#include <stdio.h>

int main() {
	int n, grade[55][5] = { 0 }, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &grade[i][0], &grade[i][1]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else if (grade[i][0] < grade[j][0] && grade[i][1] < grade[j][1]) ans++;
		}
		printf("%d ", ans + 1);
		ans = 0;
	}
}