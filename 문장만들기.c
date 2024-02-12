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
	
	char a[12000] = { 0 };
	int s, d, f, e[30] = { 0 }, c = 1, t[30] = { 0 }, r=0;

	gets_s(a);
	for (d = 0; d < 26; d++) {
		for (f = 0; f < strlen(a); f++) {
			if (d + 'a' == a[f]) e[d] = c++;
		}
		c = 1;
	}//e배열에 알파벳 개수 넣기
	for (d = 0; d < 26; d++) {
		t[d] = e[d];
	}//=strcpy(t,e);

	for (d = 25; d > 0; d--) {
		for (f = 0; f < d; f++) {
			if (t[f] < t[f + 1]) {
				int tmp = t[f];
				t[f] = t[f + 1];
				t[f + 1] = tmp;
			}
		}
	}//크기순대로 정렬
	
	r = strlen(a);
	for (s = 0; s < r; s++) printf("%c", a[s]);
	printf("\n");
	for (d = 0; d < 26; d++) {
		for (s = 0; s < 26; s++) {
			if (t[d] == e[s]) {
				e[s] = 0; f = s; break;
			}
		}
		if (t[d] != 0) {
			for (s = 0; s < r; s++) {
				if (a[s] == f + 'a') a[s] = ' ';
				
			}
			for (s = 0; s < r; s++) {
				if (a[s] != ' ') { printf("%c", a[s]); c++; }
			}
		}
		if (c > 1) printf("\n");
		c = 1;
	}
}