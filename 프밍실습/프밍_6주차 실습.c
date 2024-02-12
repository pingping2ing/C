#include<stdio.h>
#include <math.h>

int isprime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num%i == 0) return 1;
	}
	return 0;
}

int main() {
	/*
	int a, b, c, d, e,abcde=0,edcba=0;
	for (a = 1; a < 10; a++) {
		for (b = 0; b < 10; b++) {
			if (a == b) continue;
			for (c = 0; c < 10; c++) {
				if (a == c || b == c) continue;
				for (d = 0; d < 10; d++) {
					if (a == d || b == d || c == d) continue;
					for (e = 1; e < 10; e++) {
						if (a == e || b == e || c == e || d == e) continue;
						abcde = a * 10000 + b * 1000 + c * 100 + d * 10 + e;
						edcba = e * 10000 + d * 1000 + c * 100 + b * 10 + a;
						if (abcde * 4 == edcba) printf("%d*4=%d", abcde, edcba);
					}
				}
			}
		}
	}*/ //연습문제 43

	/*int c, r, y, b, a,cry,baby, ar[10] = { 0 };
	for (c = 1; c < 10; c++) {
		if (c == 4) continue;
		ar[c] = 1;
		for (r = 0; r < 10; r++) {
			if (ar[r]) continue;
			ar[r] = 1;
			for (y = 0; y < 10; y++) {
				if (ar[y]) continue;
				ar[y] = 1;
				for (b = 1; b < 10; b++) {
					if (ar[b]||b==2)continue;
					ar[b] = 1;
					for (a = 0; a < 10; a++) {
						if (ar[a]) continue;
						cry = c * 100 + r * 10 + y;
						baby = b * 1010 + a * 100 + y;
						if (3 * cry == baby) printf("cry= %d baby= %d\n", cry, baby);
						else {
							ar[c] = ar[r] = ar[y] = ar[b] = ar[a] = 0;
						}
					}
				}
			}
		}
	}*/ //2017 중간고사 V. (1)

	/*for (int i = 0; i < 10; i++) {
		if ((4102 + 10 * i) % 3 == 0 && (4102 + 10 * i) % 4 == 0) printf("%d", i);
	}*/ //연습문제 44

	/*for (int i = 10; i < 100; i++) {
		if ((4005 + i * 10 )% 35 == 0) printf("%d\n", 4005 + i * 10);
	}*/ //2016 중간고사 II. 3

	/*int a, b,ababa=0;
	for (a = 0; a < 10; a++) {
		for (b = 0; b < 10; b++) {
			if (a == b) continue;
			ababa = 3 * 100000 + a * 10101 + b * 1010;
			if (ababa % 6 == 0) printf("%d\n", ababa);
		}
	}*/ //연습문제 57


	/*int num[105] = { 0 }, i, j, count = 0;
	for (i = 2; i < 101; i++) {
		for (j = 2; j < 11; j++) {
			if (i%j == 0 && i != j) {
				num[i] = 1;
				break;
			}
		}
		if (num[i] == 0) { printf("%d ", i); count++; }
	}
	printf("\n개수: %d", count);
	*/ //연습문제 58

	/*if (isprime(2147483641)) printf("0");
	else printf("x");
	*/ //2018 중간고사 IV. 6

	/*int count[25] = { 0 },big=0,n=0;
	for (int i = 0; i < 20; i++) {
		for (int j = 1020301001 + i * 1000; j < 1020301001 + i * 1000 + 1000; j++) {
			if (isprime(j)) count[i]++;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (big < count[i]) {
			big = count[i];
			n = i;
		}
	}
	printf("%d~%d 에서 %d개", 1020301001 + n * 1000, 1020301001 + n * 1000 + 1000-1, count[n]);
	*/ //2018 중간고사 IV. 8


	/*int ar[1005] = { 0 }, i, j;
	for (i = 2; i < 1001; i++) {
		for (j = 2; j <= 500; j++) {
			if (i%j == 0 && i != j) ar[i] += j;
		}
	}
	for (i = 2; i < 1001; i++) {
		for (j = i + 1; j < 1001; j++) {
			if (ar[i] == j&&ar[j] == i) printf("%d %d\n", i, j);
		}
	}*/ //연습문제 59

	/*int sum = 1;
	for (int i = 2; i <= 123450600 / 2; i++) {
		if (123450600 % i == 0) sum += i;
	}
	printf("%d", sum);*/ //2018 중간고사 IV. 2

	/*int a, b;
	for (a = 1; a < 37; a++) {
		for (b = 1; b < 10; b++) {
			if (a*b*b == 36) printf("%d %d %d\n", a, b, b);
		}
	}*/ //연습문제 60

	/*int w, x, y, z, temp;
	for (w = 10; w < 100; w++) {
		for (x = 10; x < 100; x++) {
			if ((300 + w)*(x % 10) / 100 == 33 && (300 + w)*(x % 10) % 10 == 3) {
				if ((300 + w)*x % 1000 / 100 == 3 && (300 + w)*x % 10 == 3) {
					y = (300 + w)*(x % 10);
					z = (300 + w)*(x / 10);
					temp = (300 + w)*x;
					printf("w=%d x=%d y=%d z=%d temp=%d\n", 300 + w, x, y, z, temp);
				}
			}
		}
	}*/ //연습문제 61

	/*int s = 9, e, n, d = 7, m, o, r = 8, y = 2, send = 0, more = 0, money = 0;
	int ar[10] = { 0 };
	ar[9] = 1; ar[7] = 1; ar[8] = 1; ar[2] = 1;
	for (e = 0; e < 10; e++) {
		if (ar[e]) continue;
		ar[e] = 1;
		for (n = 0; n < 10; n++) {
			if (ar[n]) continue;
			ar[n] = 1;
			for (m = 1; m < 10; m++) {
				if (ar[m]) continue;
				ar[m] = 1;
				for (o = 0; o < 10; o++) {
					if (ar[o]) continue;
					send = s * 1000 + e * 100 + n * 10 + d;
					more = m * 1000 + o * 100 + r * 10 + e;
					money = m * 10000 + o * 1000 + n * 100 + e * 10 + y;
					if (send + more == money) printf("%d+%d=%d\n", send, more, money);
					else {
						ar[e] = 0; ar[n] = 0; ar[m] = 0;
					}
				}
			}
		}
	}*/ //연습문제 63

	/*int a, b, c;
	for (a = 1; a < 10; a++) {
		for (b = 1; b < 10; b++) {
			for (c = 2; c < 10; c += 2) {
				if (a + b + c == 6 && a*b*c == 6 && (100 * a + 10 * b + c) % 11 == 0) printf("%d%d%d호", a, b, c);
			}
		}
	}*/ //연습문제 64

	/*int a, b, c, d;
	for (a = 1; a < 10; a++) {
		for (b = 0; b < 10; b++) {
			for (c = 0; c < 10; c++) {
				for (d = 0; d < 10; d++) {
					if (a + b + c + d == 19 && a*b*c*d == 168 && (1000*a+100*b+10*c+d) % 13 == 0) printf("%d%d%d%d\n", a, b, c, d);
				}
			}
		}
	}*/ //2018 중간고사 II. 1
}