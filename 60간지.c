#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	char day[7][10] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	int s = 0, d, w, r = 0, da = 0, a = 0;
	scanf("%d", &w);
		for (d = 1; d < w; d++) if ((d % 4 == 0 && d % 100 != 0) || (d % 400 == 0))s++;
		da = ((w-1) * 365 + s)%7;
		printf("%d\n", s);
		if (w % 10 > 3) r = w % 10 - 11;
		else r = w % 10 - 1;
		if (w % 12 > 3) a = w % 12 - 13;
		else a = w % 12 - 1;
		printf("%c%c %s", r + 'H', a + 'j', day[da]);
}