#include <stdio.h>
#include <stdlib.h>
int break_num[15] = { 0 };

int check(int k) {
	int count = 0;
	if (k == 0) {
		if (break_num[k]) return 0;
		else return 1;
	}
	while (k) {
		count++;
		if (break_num[k % 10]) return 0;
		k /= 10;
	}
	return count;
}

int main() {
	int num, n, ans;
	scanf("%d", &num);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		break_num[tmp] = 1;
	}
	if (num > 100) ans = num - 100;
	else ans = 100 - num;

	for (int i = 0; i< num*2+5; i++) {
		int tmp = check(i);
		if (tmp &&abs(num - i)+tmp < ans) ans = abs(num - i)+tmp;

	}

	printf("%d", ans);

}