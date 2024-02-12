#include<stdio.h>
#include<string.h>

int main() {
	int num = 0, n = 0, tmp = 3, i, j,len=0;
	char ar[505] = { 0 }, jinsu[505] = { 0 };
	scanf("%s", &ar);
	len = strlen(ar);
	strrev(ar);
	for (i = len-1; i >=0; i--) {
		ar[i] -= '0';
		num *= 2;
		num += ar[i];
	} printf("10진수: %d\n", num);

	for (i = 0; i < 2; i++) {
		for (j = 0; j <len; j += tmp) {
			jinsu[n] = ar[j] + ar[j+1] * 2 + ar[j+2] * 4;
			if (i) jinsu[n] += ar[j+ 3] * 8;
			n++;
		}
		if (i == 0) printf("8진수는: ");
		else printf("16진수는: ");
		for (j = n - 1; j >= 0; j--) {
			if (jinsu[j] > 9) jinsu[j] += 55;
			else jinsu[j] += '0';
			printf("%c", jinsu[j]);
			jinsu[j] = 0;
		}
		printf("\n");
		tmp++;
		n = 0;
	}
}