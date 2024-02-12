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
	
	char ha[20][7] = { "pop", "no", "zip", "zotz", "tzec", "xul",  "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" },
		ta[21][9] = { "imix", "ik", "akbal", "kan", "chicchan","cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
	int s=0, d, f, r,t,c=0;
	char a[10] = { 0 };
	scanf("%d%s%d", &r, a, &t);
	s = 365 * t;
	for (d = 0; d < 19; d++) {
		for (f = 0; f < 7; f++) {
			if (ha[d][f] != a[f]) c++;
		}
		if (c == 0) break;
		c = 0;
	} c = 1; f = 0;
	s += 20 * d + r; //s=모든 날의 수
	for (d = 0; d < s % 260; d++) {
			if (c > 13) c = 1;
			if (f > 20) f = 1;
			c++; f++;
	}
	printf("%d %s %d", c, ta[f], s/260);
}