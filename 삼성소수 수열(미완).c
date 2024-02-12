#include <stdio.h>
int a, s, d, w, e, f, c = 0, cc = 0, an1 = 0, an2 = 0, wr[30005] = { 0 };
char ar[30005] = { 0 },er[30005] = { 0 };
//itoa 정수->배열 atoi 배열->정수
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &a);
	for (d = 2; d <= 30000; d++) wr[d] = d;
	for (d = 2; d <= 174; d++) {
		for (f = 2; f <= 3000; f++) {
			if (wr[f] % d == 0 && wr[f] / d != 1) wr[f] = 0;
		}
	}//에라토스테네스의 체로 소수 wr배열에 넣기
	for (d = 0; d < a; d++) {
		scanf("%d%d", &w, &e);
		if (wr[w] == 0 && wr[e] == 0) printf("Case #%d\n3\n", d + 1);
		else if (wr[w] == 0) printf("Case #%d\n2\n", d + 1);
		else if (wr[e] == 0) printf("Case #%d\n1\n", d + 1);
		//합성수 거르기
		else {
			for (f = 0; f < 6; f++) {
				c = w;
				cc = e;
				for (s = 0;; s++) {
					if (c == 0 && cc == 0)break;
					ar[s] = c % 10;
					c /= 10;
					er[s] = cc % 10;
					cc /= 10;
				}
				ar[f] = er[f] = 0;
				for (s = 5; s >=0; s--) {
					if (ar[s] != 0) {
						c *= 10;
						c += ar[s] - '0';
					}
					if (er[s] != 0) {
						cc *= 10;
						cc += ar[s] - '0';
					}
				}
				if (wr[c] != 0) an1++;
				if (wr[cc] != 0) an2++;
			}
			if (an1 > an2) printf("Case #%d\n1\n", d + 1);
			else if(an1!=an2) printf("Case #%d\n2\n", d + 1);
			else printf("Case #%d\n3\n", d + 1);
			an1 = an2 = 0;
		}
	}
}
