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
	
	int s, d;
	scanf("%d", &s);
	for (d = 0;; d++) {
		if (pow(4, d) < s&&s <= pow(4, d + 1)) break;
	}
	printf("%d", d+1);
}