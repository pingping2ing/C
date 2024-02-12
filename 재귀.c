#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)

int ar[5];

void p(int x) {
	if (x == 3) return;
	p(x + 1);
}

void r(int a, int b) {
	for (int i = 0; i < b; i++) {
		if (a == 0 || ar[a - 1] < i) {
			ar[a] = i;
			for (int j = 0; j <= a; j++) printf("%c ", ar[j] + 'a');
			printf("\n");
			r(a + 1, b);
		}
	}
}

int main() {
	p(0);
	r(0, 3);
	return 0;
}