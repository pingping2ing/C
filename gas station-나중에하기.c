#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	int s, d, f = 0;
	char ar[1200] = { 0 };
	scanf("%s", ar);
	for (d = 0; d < strlen(ar); d++) {
		if (ar[d] == '6') { ar[d] = '9'; f++; }
		if (ar[d] == '2') { ar[d] = '5'; f++; }
	}
	if (f == 0) {
		for (d = 0; d < strlen(ar) - 1; d++) {
			if (ar[d] == '.') break;
			if (ar[d + 1] != '.') {
				if (ar[d] >= ar[d + 1]) continue;
				else f++;
			}
		}
	}
	if (f == 0) printf("The price cannot be raised.");
	else {
		std::sort(ar, ar + strlen(ar));
		strrev(ar);
		for (d = 0; d < strlen(ar); d++) {
			if (ar[d] != '.') {
				printf("%c", ar[d]);
			}
			if (d == strlen(ar) - 3) printf(".");
		}
	}
}