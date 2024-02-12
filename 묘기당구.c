#include <stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
int s, d, f,e=3,a,b,r=0,n;
char  ar[12000];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &s, &f); a = s; b = 1;
	do {
		switch (e) {
		case 4: a++; b++; break;
		case 1: a++; b--; break;
		case 3: a--; b++; break;
		case 2: a--; b--; break;
		} 
		if ((a<1 && b<1) || (a<1 && b>f) || (a>s&&b<1) || (a>s&&b>f)) r = 1;
		else if (a < 1) {
			if (e == 3) e = 4;
			else if (e == 2) e = 1;
			a = 1;
			ar[n++] = 'E';
		}
		else if (b < 1) {
			if (e == 1) e = 4;
			else if (e == 2) e = 3;
			b = 1;
			ar[n++] = 'S';
		}
		else if (a > s) {
			if (e == 4) e = 3;
			else if (e == 1) e = 2;
			a = s;
			ar[n++] = 'W';
		}
		else if (b > f) {
			if (e == 4) e = 1;
			else if (e == 3) e = 2;
			b = f;
			ar[n++] = 'N';
		}
	} while (r==0);
	printf("%d\n", n);
	for (d = 0; d < n; d++) printf("%c ", ar[d]);
	printf("%d", e);
}