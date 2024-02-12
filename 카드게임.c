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
	
	char na[7] = { 0 };
	int s, d, f = 0, r = 0, e = 0, w = 0, c = 0, ro = 0,
		ekq = 0, rr = 0, co[7] = { 0 }, m = 0;
	for (d = 0; d < 5; d++) {
		scanf(" %c", &na[d]); scanf("%d", &co[d]);
	}
	for (d = 0; d < 4; d++) {
		if (na[d] == 'R')  f++;
		if (na[d] == 'B') r++;
		if (na[d] == 'Y') e++;
		if (na[d] == 'G') w++;
	}//같은 색 찾기
	for (d = 4; d > 0; d--) {
		for (s = 0; s < d; s++) {
			if (co[s] > co[s + 1]) {
				int tmp = co[s];
				co[s] = co[s + 1];
				co[s + 1] = tmp;
			}
		}
	}//크기순대로 나열
	for (s = 4; s > 0; s--) {
		if (co[s] - co[s - 1] != 1) c++;
		if (co[s] - co[s - 1] == 0) ro++;
		else {
			rr++; if (s == 2) m = 1;
			else m = s;
		}
	} 
	if (f == 4 || r == 4 || e == 4 || w == 4) {
		if (c == 0) ekq = co[4] + 900;
		else ekq = co[4] + 600;
	}
	else if (ro == 3 && rr == 1) ekq = co[2] * 10 + co[m] + 700;
	else if (ro == 3) ekq = co[2] + 800;
	else if (c == 0) ekq = co[4] + 500;
	else if (ro == 2) {
		for (d = 4; d > 1; d--) if (co[d] - co[d - 1] == 0 && co[d - 1] == co[d - 2]) { ekq = co[d] + 400; }
		if (ekq == 0) ekq = co[3] * 10 + co[1] + 300;
	}
	else if (ro == 1) {
		for (d = 4; d > 0; d--) if (co[d] - co[d - 1] == 0) ekq = co[d] + 200;
	}
	else if(ekq==0)ekq = co[4] + 100;
	printf("%d", ekq);
	
}