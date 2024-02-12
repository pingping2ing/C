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
	
	int s, d = 0, f = 0, n = 0, e = 0, ar[120][120] = { 0 };
	scanf("%d", &s); n = s*s; d = s; f = s;
	if (s % 2 == 0) {
		 ar[0][s] = 1; ar[1][0] = 1; ar[s+1][1] = 1; 
		do {
			ar[d][f] = n--;
			switch(e){
			case 0: d--; if (ar[d-1][f] > 0) e = 1; break;
			case 1: f--; if (ar[d][f-1] > 0) e = 2; break;
			case 2: d++; if (ar[d+1][f] > 0) e = 3; break;
			case 3: f++; if (ar[d][f+1] > 0) e = 0; break;
			}
		} while (n >0);
	}
	else {
		ar[s][0] = 1; ar[0][1] = 1; ar[1][s+1] = 1;
		do {
			ar[d][f] = n--;
			switch (e) {
			case 0: f--; if (ar[d][f - 1] > 0) e = 1; break;
			case 1: d--; if (ar[d - 1][f] > 0) e = 2; break;
			case 2: f++; if (ar[d][f + 1] > 0) e = 3; break;
			case 3: d++; if (ar[d + 1][f] > 0) e = 0; break;
			}
		} while (n > 0);
	}
	for (d = 1; d <= s; d++) {
		for (f = 1; f <= s; f++) {
			printf("%2d ", ar[d][f]);
		}
		printf("\n");
	}
}