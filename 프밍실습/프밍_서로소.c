#include <stdio.h>
#include <math.h>
int main() {
	int i, j, k, count = 0, A = 0, B = 0, flag;

	for (i = 1030502030; i < 1030503030; i++) {
		for (j = i + 1; j <= 1030503030; j++) {
			for (k = 2; k <= sqrt(i); k++) {
				flag = 1;
				if (i%k == 0 && j%k == 0) { flag=0; break; }
			}
			if (flag) {
				count++;
				if (j - i > B - A) {
					A = i;
					B = j;
				}
			}
		}
	}
	printf("서로 소가 되는 쌍의 개수:%d\n",count);
	printf("쌍을 이루는 두 수의 차가 가장 큰 것: (%d,%d)\n", A, B);
}