#include <stdio.h>
int record[45][3] = { 0 };


void fibonacci(int n) {
	if (record[n][0] > 0 || record[n][1] > 0) return;
	else {
		fibonacci(n - 1); fibonacci(n - 2);
		record[n][0] = record[n - 1][0] + record[n - 2][0];
		record[n][1] = record[n - 1][1] + record[n - 2][1];
	}
}
int main() {
	int n, ar[105] = { 0 },i;
	record[0][0] = 1;
	record[0][1] = 0;
	record[1][0] = 0;
	record[1][1] = 1;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
		fibonacci(ar[i]);
		printf("%d %d\n", record[ar[i]][0],record[ar[i]][1]);
	}
}