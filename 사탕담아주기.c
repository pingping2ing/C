#include <stdlib.h>
#include <math.h>
#include<functional>
#include <algorithm>
#pragma warning(disable:4996)
int a[150][4] = { 0 };
bool compare(double a, double b) {
	return a < b;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int s, d, f, w;
	double e = 0, r[150] = {0};
	scanf("%d", &s); scanf("%d", &w);
	for (d = 0; d < s; d++) {
		for (f = 0; f < 3; f++) {
			scanf("%d", &a[d][f]);
		}
	}
	for (d = 0; d < s; d++) {
		r[d] = (double)a[d][0] / a[d][1];
	}
	std::sort(r, r + s, compare);
	for (d = 0; d < s; d++) {
		for (f = 0; f < s; f++) {
			if (r[d] == (double)a[f][0] / a[f][1]) {
				if (a[f][2] * a[f][1] >= w) { e += r[d] * w; w = 0;}
				else { e += a[f][0]*a[f][2];  w -= a[f][1] * a[f][2]; }
				break;
			}
		}
		if (w == 0) break;
	}
	printf("%.0lf", ceil(e));
	
}