#include <stdio.h>
int a, d, ar[1000005] = { 0 },s,r;
void mm(int n) {
	if (n == 1) ar[n] = 0;
	else if (n % 2 == 0) ar[n] = ar[n / 2] + 1;
	else ar[n] = ar[(n + 1) / 2] + 2;
}
int main() {
	ar[0] = 0;
	ar[1] = 0;
	setbuf(stdout, NULL);
	
	for (d = 1; d <= 1000000; d++) {
		mm(d);
	}
	for (d = 2; d <= 1000000; d++) {
		ar[d] += ar[d - 1];
	}
	scanf("%d", &a);
	for (d = 1; d <= a; d++) {
		scanf("%d%d", &s, &r);
		printf("Case #%d\n%d\n", d,ar[r]-ar[s-1]);
	}

}