#include<stdio.h>
#pragma warning(disable:4996)
long long int aa[200005] = { 0 }, bb[200005] = { 0 },num=0,num2=0;
void swap(long long int *x, long long int *y) {
	long long int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int main() {
	int t, f, k, d, n;
	setbuf(stdout, NULL);
	scanf("%d", &t);
	for (d = 0; d < t; d++) {
		num2 = 0;
		scanf("%d%d", &n, &k);
		for (f = 0; f < n; f++) {
			scanf("%d", &aa[f]);
		}
		for (f = 0; f < n; f++) {
			scanf("%d", &bb[f]);
		}
		for (f = n - 1; f > 0; f--) {
			for (int j = 0; j < f; j++) {
				if (aa[j] > aa[j + 1]) swap(&aa[j + 1], &aa[j]);
				if (bb[j] > bb[j + 1]) swap(&bb[j + 1], &bb[j]);
			}
		}
		for (f = 0; f < k; f++) {
			num = aa[f] + bb[k - f - 1];
			if (num > num2) num2 = num;
		}
		printf("Case #%d\n%lld\n", d + 1, num2);
	}
}