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
	
	int a, e, s, d, f = 0;
	char v;
	scanf("%d%c%d%d", &a, &v, &e, &s);
	//a=시, e=분, s=게임한 시간
	s += e;
	for (d = 0;; d++) {
		if (a > 23) a -= 24;
		if (((a >= 22 && a < 24) || (a >= 0 && a < 3)) && (s > 300)) {
			f += 5000;
			if (a >= 22) a -= 24;
			s -= (8 - a) * 60;
			a = 8;
		}
		else {
			f += 1000;
			s -= 60;
			a += 1;
		}
		if (s<=0) break;
	}
	printf("%d\n", f);
	
}