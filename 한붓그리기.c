#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
int s, d, f, r1, r2, r3, ar[120][120], arr[1200],n,cnt,status;
void rr(int a, int b) {
	if (cnt == 0) {
		status = 1;
		return;
	}
	arr[n++] = a;
	for (d = 1; d <= s; d++) {
		if (ar[a][d] == 1) {
			ar[a][d] = 0;
			ar[d][a] = 0;
			rr(d, cnt-1);
			if (status) return;
			ar[a][d] = ar[d][a] = 1;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &s, &r1);
	for (d = 0; d < r1; d++) {
		scanf("%d%d", &r2, &r3);
		ar[r2][r3] = 1;
		ar[r3][r2] = 1;
	} r1 = 0; r2 = 0; r3 = 1;
	for (d = 1; d <= s; d++) {
		for (f = 1; f <= s; f++) {
			if (ar[d][f] == 1) r1++,cnt++;
		}
		if (r1 % 2 != 0) { r2++; r3 = d; }
		r1 = 0;
	} 
	if (r2 != 2 && r2 > 0) printf("0");
	else {
		rr(r3, cnt/2);
		for (d = 0; d < n; d++) printf("%d ", arr[d]);
	}
}