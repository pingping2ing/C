#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m,ans=0,i;
char board[12][12] = { 0 };

void road(int h, int w, int before) { //위에서 오면 0 왼쪽->1 아래->2 오른쪽->3
	int a = 1;
	ans++;
	if (before % 2 == 0) {
		if (before == 2) a = -1;
		if (board[h + a][w] == '#' && board[h][w + 1] == '#' && board[h][w - 1] == '#') return ans--;
	}
	else {
		if (before == 3) a = -1;
		if (board[h + 1][w] == '#' && board[h - 1][w] == '#' && board[h][w + a] == '#') return ans--;
	}
	//위
	for (i = h; i < n; i++) { 
		if (board[i][w] == 'O') return ans;
		if (board[i + 1] == '#') road(i, w, 0); 
	}
	//왼쪽
	for (i = w; i < m; i++) { 
		if (board[h][i] == 'O') return ans;
		if (board[i + 1] == '#') road(h, i, 1); 
	}
	//아래
	for (i = h; i >= 0; i--) {
		if (board[i][w] == 'O') return ans;
		if (board[i - 1] == '#') road(i, w, 2);
	}
	//오른쪽
	for (i = w; i >= 0; i--) {
		if (board[h][i] == 'O') return ans;
		if (board[h][i - 1] == '#') road(h, i, 3);
	}
}
int main() {

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) { scanf("%s", board[i]);
	
	}




}