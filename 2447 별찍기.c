#include <stdio.h>
#include <string.h>
#include <math.h>
int a = 0, s = 1,r=0,i,j,flag=0;
char ar[6600][6600] = { 0 };
void star(int n, int m) {
	if (n == m) return;
	for (i = n; i < m;) {
		r++;
		s = n;
		for (j = 0; j < m; j++) {
			if (flag == n) {
				flag = 0;
				s += n * 3;
			}
			if (s == j || flag > 0) {
				flag++;
				ar[i][j] = ' ';
			}

		}
		if (r >= n) {
			r = 0;
			i += n*3;
			i -= n - 1;
		}
		else i++;
	}
	star(n * 3, m);
}
int main() {
	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		for (j = 0; j < a; j++) {
			ar[i][j] = '*';
		}
	}
	star(1,a);
	for (i = 0; i < a; i++) {
		for (j = 0; j < a; j++) {
			printf("%c", ar[i][j]);
		}
		printf("\n");
	}
}
	