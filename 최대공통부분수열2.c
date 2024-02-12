#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
char ar[1200] = { 0 }, ae[1200] = { 0 }, we[1200] = { 0 }, arr[1200] = {0};
int aw[1200][1200] = { 0 };
int s, t, d, c = 0;

int rr(int a, int b) {

	if (a == -1 || b == -1) return 0;
	if (aw[a][b] != -1) return aw[a][b];
	if (ar[a] == ae[b]) { 
		arr[c++] = ar[a]; 
		aw[a][b] = rr(a - 1, b - 1) + 1;
		printf("%c", ar[a]);
		return aw[a][b];
	}
	int x = 0, y = 0;
	x = rr(a - 1, b); y = (a, b - 1);
	if (x > y) {
		arr[c++] = x;
		aw[a - 1][b] = arr[c - 1];
		return arr[c - 1];
	}
	else {
		arr[c++] = y;
		aw[a][b - 1] = arr[c - 1];
		return arr[c - 1];
	}
}

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	int f;
	for (d = 0; d < 1200; d++) {
		for (f = 0; f < 1200; f++) {
			aw[d][f] = -1;
		}
	}
	scanf("%d", &s); scanf(" %s", ar); scanf("%d", &t); scanf(" %s", ae);
	for (d = 0; d < c; d++) {
		printf("%c\n", arr[d]);
	}
	printf("%d\n", rr(s-1, t-1));
	for (d = 0; d < 5; d++) {
		for (f = 0; f < 5; f++) {
			printf("%d ", aw[d][f]);
		}
		printf("\n");
	}
}