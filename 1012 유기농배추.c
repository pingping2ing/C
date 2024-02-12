#include <stdio.h>
int cabbage[55][55] = { 0 }, w, h;

void cabbage_visit(int a, int b) {
	if (!cabbage[a][b] || a >= h || a < 0 || b >= w || b < 0) return;
	cabbage[a][b] = 0;
	cabbage_visit(a + 1, b);
	cabbage_visit(a - 1, b);
	cabbage_visit(a, b + 1);
	cabbage_visit(a, b - 1);
}
int main() {
	int i, j,k, case_num = 0, cabbage_num;

	scanf("%d", &case_num);
	for (k = 0; k < case_num; k++) {
		int num = 0;
		scanf("%d%d%d", &w, &h, &cabbage_num);
		for (i = 0; i < cabbage_num; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			cabbage[b][a] = 1;
		}
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (cabbage[i][j]) { cabbage_visit(i, j); num++; }
			}
		}
		printf("%d\n", num);
	}
}