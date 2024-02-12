#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int a[10][10] = {0};
	int s, d, f;
	char c;
	for (d = 0; d < 5; d++) {scanf("%d", &a[d][0]);scanf(" %c", &c);scanf("%d", &a[d][2]);}
	//입력받기
	for (s = 0; s < 5; s++) {
		a[s][4] = a[s][0];
		if (a[s][0] >= 12)
			a[s][0] -= 12;
	}//13시->1시 a[s][4]에 원래 시간 저장
	for (s = 0; s < 5; s++) {
		a[s][3] = (a[s][0] * 30 + (a[s][2] / 2)) - a[s][2] * 6;
		if (a[s][3] < 0) a[s][3] = -a[s][3];
		if (a[s][3] > 180) a[s][3] = 360 - a[s][3];
		
	}//각도 계산
	for (d = 4; d > 0; d--) {
		for (f = 0; f < d; f++) {
			if ((a[f][3] > a[f + 1][3]) || (a[f][3] == a[f + 1][3] && a[f][4] > a[f + 1][4])) {
				int tmp[30][30];
				tmp[f][3] = a[f][3];
				a[f][3] = a[f + 1][3];
				a[f + 1][3] = tmp[f][3];
				int tmpp[30][30];
				tmpp[f][4] = a[f][4];
				a[f][4] = a[f + 1][4];
				a[f + 1][4] = tmpp[f][4];
				int ttmp[30][30];
				ttmp[f][2] = a[f][2];
				a[f][2] = a[f + 1][2];
				a[f + 1][2] = ttmp[f][2];
			}
		}
	}
	if (a[2][4] < 10 && a[2][2] < 10) printf("0%d:0%d", a[2][4], a[2][2]);
	else if(a[2][4]<10)printf("0%d:%d", a[2][4], a[2][2]);
	else if (a[2][2]<10)printf("%d:0%d", a[2][4], a[2][2]);
	else printf("%d:%d", a[2][4], a[2][2]);

}