#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
int s, d, f, ar[30], n, k, we[12000];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &f);
	for (d = 0; d < f; d++) scanf("%d", &ar[d]); 
	scanf("%d", &s);
	we[0] = 1;
	for (int i = 0; i < f; i++) {
		for (int j = ar[i]; j <= s; j++) we[j] += we[j - ar[i]];
	}
	printf("%d", we[s]);
}