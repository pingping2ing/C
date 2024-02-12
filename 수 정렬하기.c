#include <stdio.h>

int main() {
	int n, ar[1005] = { 0 }, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &ar[i]);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (ar[j] > ar[j + 1]) {
				int tmp;
				tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++) printf("%d\n", ar[i]);
}