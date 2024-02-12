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
	
	int s, d, f, rr[12000] = { 0 }, c = 0, e = 0, count = 0, ar[5000] = {0};
	int we[30] = { 2,3,  5 ,  7 , 11 ,  13 ,  17 ,  19 , 23 ,  29 , 31  , 37 , 41 ,
		 43 ,  47 , 53  , 59 , 61 ,  67 , 71 ,  73  , 79 , 83  , 89 , 97 };
	scanf("%d", &s);
	for (d = 2; d < 10000;d++) rr[d] = d;
	for (d = 0; d < 25; d++) {
		for (f = 2; f <= s; f++) {
			if (f%we[d] == 0 && f != we[d]) rr[f] = 0;
		}
	}
	for (d = 2; d <= s ; d++) { if (rr[d] > 0) ar[c++] = d; }
	for (d = 0; d <c; d++) {
		e = 0;
		for (f = d; f <c; f++) {
			e += ar[f];
			if (e == s) { count++; break; }
			if (e > s) break;
		}
	}
	printf("%d", count);

}