#include <stdio.h>
int number(int a) {
	int b,j,tmp=0;
	while (a > 10) {
		tmp = a;
		b = 0;
		if (tmp % 10 == 6) {
			for (j = 0; j < 3; j++) {
				if (tmp% 10 == 6) b++;
				tmp /= 10;
			}
			if (b == 3) return 1;
		}
		a /= 10;
	}
	return 0;
}
int main() {
	int i, n,ans=0,count=0;
	scanf("%d", &n);
	for (i = 0;; i++) {
		count += number(i);
		if (count == n) {
			printf("%d", i);
			break;
		}
	}
}