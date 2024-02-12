#include <stdio.h>
int a, s, d, ar[10005] = { 0 }, er[5] = { 0 }, rr[4] = { 500,100,50,10 },f;
// freopen("input.txt", "r", stdin);

int main() {
	setbuf(stdout, NULL);
	scanf("%d", &a);
	for (d = 0; d < a; d++) {
		scanf("%d", &ar[d]);
	}
	for (d = 0; d < a; d++) {
		printf("Case #%d\n", d + 1);
		for (f = 0; f < 4; f++) {
			for (int i = 0;; i++) {
				if (ar[d] >= rr[f]) {
					ar[d] -= rr[f];
				}
				else { er[3 - f] = i; break; }
			}
		}
			for (f = 0; f < 4; f++) {
				printf("%d ", er[f]);
			}
			printf("\n");
		}

	}