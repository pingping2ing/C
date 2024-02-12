#include <stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
#define M_PI 3.14159265358979323846
int t, r, start, end, jj, jstart, jend, jh,d,f;
double answer=0,a=0, e = 0;
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &t);
	for (d = 0; d < t; d++) {
		scanf("%d%d%d", &r, &start, &end);
		e = start;
		scanf("%d", &jj);
		for (f = 0; f < jj; f++) {
			scanf("%d%d%d", &jstart, &jend, &jh);
			if (jh < r) {
				a = (double)(r - jh) / r;
				answer += jend - e - sqrt(r*r - pow(r - jh, 2)) + (double)r*M_PI - 2 * r*asin(a);
				e = jend + sqrt(r*r - pow(r - jh, 2));
			}
			else {
				answer += jend - e + 2 * jh - 3 * r + (double)r*M_PI;
				e = jend + r;
			}
		}
		answer += end - e;
		printf("Case #%d\n%f\n", d + 1, answer);
		answer = 0;
	}
}