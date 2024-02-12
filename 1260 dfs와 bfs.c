#include <stdio.h>
#include<string.h>

int a = 0, s = 0, d = 0, ar[1005][1005] = { 0 };
int n = 0, m = 0, e[1005] = { 0 },ne=1, er[1005] = { 0 },nr=0;
void dfs(int sd) {
	e[sd] = 1;
	printf("%d ", sd);
	for (int i = 1; i <= a; i++) {
		if (ar[sd][i] > 0 && e[i] == 0) {
			dfs(i);
		}
	}
}

int bfs(int sd) {
	if (nr > a) return 0;
	e[sd] = 1;
	for (int i = 1; i <= a; i++) {
		if (ar[sd][i] > 0 && e[i] == 0) { 
			er[ne++] = i;
			e[i] = 1;
		}
	}
	bfs(er[++nr]);
}

int main() {
	scanf("%d%d%d", &a, &s, &d);
	for (int i = 0; i < s; i++) {
		scanf("%d%d", &n, &m);
		ar[n][m] = ar[m][n] = 1;
	}
	dfs(d);
	memset(e, 0, sizeof(e));//memset:함수초기화
	printf("\n");
	er[0] = d;
	bfs(d);
	for (int i = 0; i < a; i++) {
		if (er[i] != 0) printf("%d ", er[i]);
	}
}v