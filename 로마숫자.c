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
	
	int s, d, f,c=0, a[200] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	char e[13][3] = { "M", "CM", "D","CD","C","XC","L","XL","X","IX","V","IV","I" };
	scanf("%d", &s);
	for (d = 0;; d++) {
		if (s >= a[c]) {
			s -= a[c]; printf("%s", e[c]);
		}
		else c++;
		if (s == 0) break;
	}
}