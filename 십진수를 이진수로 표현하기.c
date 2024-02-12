#include <stdio.h>

int main() {
	int num, i, j;
	int bin[200] = { 0 };
	scanf("%d", &num);
	for (i = 0;; i++) {
		if (num == 0) break;
		bin[i] = num % 2;
		num /= 2;
	}
	for (j = i - 1; j >= 0; j--) printf("%d", bin[j]);
}