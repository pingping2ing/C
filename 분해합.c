#include <stdio.h>
int n, sum = 0;
int make(int N) {
	sum = 0;
	if (N < 10) return N;
	else {
		while (N >= 10) {
			sum += N % 10;
			N /= 10;
			if (N < 10) sum += N;
		}
		return sum;
	}
}
int main() {
	int i,flag = 0;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		if (i + make(i) == n) { flag++; break;}
	}
	if (flag) printf("%d", i);
	else printf("0");
}