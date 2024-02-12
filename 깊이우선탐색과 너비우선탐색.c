#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int s, f, ar[30][30], we[30], er[1200];
char s1, s2;
void rr(int a) {
	int d;
	printf("%c", a + 'A');
	we[a] = 1;
	for (d = 0; d < s; d++) {
		if (ar[a][d] == 1 && we[d] == 0) rr(d);
	}
}
void bps(int a) {
	int head=0, tail=1,d;
	we[a] = 1;
	er[head] = a;
	do {
		for (d = 0; d < s; d++) {
			if (ar[a][d] == 1 && we[d] == 0) {
				er[tail++] = d;
				we[d] = 1;
			}
		}
		head++;
		a = er[head];
	} while (head < tail);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int d;
	scanf("%d%d", &s, &f);
	for (d = 0; d < f; d++) {
		scanf(" %c %c", &s1, &s2);
		ar[s1-65][s2-65] = ar[s2-65][s1-65] = 1;
	}
	scanf(" %c", &s1);
	rr(s1 - 'A'); printf("\n");
	memset(we, 0, sizeof(we));
	bps(s1 - 'A');
	for (d = 0; d < s; d++) printf("%c", er[d] + 'A');
}