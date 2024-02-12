#include <stdio.h>
int ans = 0;

int Z(int n, int a, int b) {
	if (a == 0 && b == 0) return ans;
	if (a >= n / 2) { ans += n * (n / 2);  a -= n / 2; }
	if (b >= n / 2) { ans += (n / 2) * (n / 2); b -= n / 2; }
	Z(n / 2, a, b);

}
int main() {
	int n, r, c,z=1;
	scanf("%d%d%d", &n, &r, &c);
	for (int i = 0; i < n; i++) z *= 2;
	printf("%d", Z(z, r, c));
}