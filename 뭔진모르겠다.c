#include <algorithm>
int s, d, f, e,arr,wee;
char ar[120000], we[12000000];
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/

	scanf("%d", &s);
	for (int k = 1;; k++) {
		e = k;
		for (d = 0;; d++) {
			ar[d] = e%s;
			e /= s;
			if (e == 0) break;
		}
		strcpy(we, ar);
		strrev(we);
		we[d] = we[0]; strrev(we);
		for (f = 0; f < d; f++) {
			
		}
	}
	printf("%d\n", d);
	for (f = 0; f < d; f++) {
		printf("%d ", ar[f]);
	}

}