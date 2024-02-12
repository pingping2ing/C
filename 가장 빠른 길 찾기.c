#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
int s, d, we[12000][2], cost[120][120],r, right,left,a,b;
char ar[120][120];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &s, &r);
	for (d = 1; d <= s; d++) {
		scanf("%s", &ar[d][1]);
	}
	int x[] = { 1,-1,0,0 };
	int y[] = { 0,0,1,-1 };
	cost[s][1] = 1;
	we[right][0] = s;
	we[right++][1] = 1;
	while (left < right) {
		a = we[left][0];
		b = we[left++][1];
		for (d = 0; d < 4; d++) {
			if (a + x[d]<1 || a + x[d]>s || b + y[d] > r || b + y[d] < 1) continue;
			if (ar[a + x[d]][b + y[d]] == '0'&&cost[a + x[d]][b + y[d]] == 0) {
				cost[a + x[d]][b + y[d]] = cost[a][b] + 1;
				we[right][0] = a + x[d];
				we[right++][1] = b + y[d];
			}
		}
	}
	if (s == 1 && r == 1) {
		if (ar[s][r] == '0') printf("1");
		else printf("-1");
	}
	else if (cost[1][r] > 0)printf("%d", cost[1][r]);
	else printf("-1");
}

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<functional>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

queue<pair<int, int> >que;
char board[105][105];
int ans[105][105];

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &board[i][1]);
	}
	que.push({ n,1 });
	ans[n][1] = 1;
	int X[] = { -1,1,0,0 }, Y[] = { 0,0,-1,1 };
	while (que.size()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			if (x + X[i] < 1 || n < x + X[i] || y + Y[i] < 1 || m < y + Y[i]) continue;
			if(board[x+X[i]][y+Y[i]])
		}
	}
}