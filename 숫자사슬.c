#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s, d, f, ar[12000] = { 0 }, we[12000] = { 0 }, re[12000] = {0},r;
	scanf("%d", &s);
	re[0] = s;
	for (r = 0;; r++) {
		for (d = 0; s != 0; d++) {
			ar[d] = s % 10;
			s /= 10;
		}
		std::sort(ar, ar + d);//ar을 오름차순 정렬
		for (f = 0;f<d; f++) {
			we[f] = ar[d - 1 - f];
		} 
		int c = 0;
		for (f = d - 1; f >= 0; f--) {
			re[r + 1] += (we[f] - ar[f])*pow(10, c++);
		}
		for (d = 0; d < r + 1; d++) {
			if (re[r + 1] == re[d]) s++;
		}
		if (s > 0) break;
		s = re[r + 1];
	} printf("%d", r+1);
	for (d = 0; d < r + 1; d++) {
		printf("\n%d", re[d]);
	}
}