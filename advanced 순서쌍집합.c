#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int s, d, f, ar[12000][5], we[1200],e, wr[1200],n,mm[1200][120],m,k,nn,ll,j=9999, aqkdwl[1200];

void rr(int a) {
	if (aqkdwl[a] == 1) return;
	aqkdwl[a] = 1;
	mm[n][m++] = a;
	for (int i = 0; i < s; i++) {
		for (int ii = 0; ii < 2; ii++) {
			if (ar[i][ii] == a) {
				if (ii == 0) rr(ar[i][1]);
				else rr(ar[i][0]);
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	for (d = 0;; d++) {
		scanf("%d%d", &ar[d][0], &ar[d][1]);
		if (ar[d][0] == 100 || ar[d][1] == 100) break;
		if (e < ar[d][0]) e = ar[d][0];
	    if (e < ar[d][1]) e = ar[d][1];
	} s = d;
	for (d = 0; d < s; d++) {
		for (f = 0; f < 2; f++) {
			we[ar[d][f]]++;
		} 
	} 
	for (d = 0; d <= e; d++) {
		if (we[d] > 0) { 
		rr(d);
		if (k < m) { k = m; nn = n; }
		if (j > m&&m!=0) { j = m; ll = n; }
		n++;  m = 0;}
	}
	for (d = 0; d < k; d++) {
		wr[d] = mm[nn][d];
	}
	for (d = 0; d <j; d++) {
		wr[d + k] = mm[ll][d];
	}
	std::sort(wr, wr + k + j);
	for (d = 0; d < k + j; d++) printf("%d ", wr[d]);
}