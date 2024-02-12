#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main() {
	/*int a=10, b=10, c=10, abbc=0,count=0;
	for (int i = 1; i < a; i++) {
		for (int j = 1; j < b; j++) {
			for (int k = 0; k < c; k++) {
				abbc = i * 1000 + j * 110 + k;
				if (abbc % 9 == 0) {
					printf("%d\n", abbc);
					count++;
				}
			}
		}
	}
	printf("%d\n", count);*/ //연습문제 19

	/*int money = 240000, home = 0,year=0;
	do {
		home += money*0.15;
		home += home*0.005;
		money *= 1.045;
		year++;
	} while (home < 1000000);
	printf("%d", year);
	*/ //연습문제 21

	/*int a, b, sum = 0;
	scanf("%d%d", &a, &b);
	if (b < a) {
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	while (a < b - 1) {
		a += 1;
		sum += a;
	}
	printf("%d", sum);*/ //연습문제 25

	/*int n, r,a,b=1,ans=1;
	printf("n과 r을 입력하세요: ");
	scanf("%d%d", &n, &r);
	a = n - r + 1;
	while (a != n + 1) {
		ans *= a;
		a++;
	}
	while (b != r + 1) {
		ans /= b;
		b++;
	}
	printf("%d", ans);*/ //연습문제 26

	/*int n = 2147483641, flag = 0;
	for (int i = 2; i <= sqrt(i); i++) {
		if (n%i == 0) { printf("O"); flag++; }
	}
	if (flag == 0) printf("X");*/ //2018 중간고사 IV. 6

	/*int count = 0, i, j;
	for (i = 2030102030; i <= 2030119999; i++) {
		for (j = 2; j <= sqrt(i); j++)
			if (i%j == 0) { count++; break; }
		if (count == 50) printf("50번째 소수: %d\n", i);
	}
	printf("소수의 개수: %d",count);
	*/ //2018 중간고사 IV. 7

	/*int i, ans = 0;
	for (i = 60;; i++) {
		ans = i*(i + 2)*(i + 4);
		if (ans / 100000 == 4 && ans % 10 == 2)
		{ printf("%d %d %d", i, i + 2, i + 4); break; }
	}*/

	/*int i;
	for (i = 13;; i += 13) {
		int num = 0;
		num = i*(i + 13)*(i + 26);
		if ((num % 100) / 10 == 6 && (num % 1000000) / 100000 == 6 &&
			(num % 100000000) / 10000000 == 6) {
			printf("%d %d %d", i, i + 13, i + 26);
			break;
		}
	}*/ //2018 중간고사 II. 5


	/*int i;
	double pi=0;
	for (i = 1; i <= 1000000; i++) {
		pi += 4 * pow(-1, i + 1)*((double)1/(double)(2 * i - 1));
	}
	printf("%f\n", pi);
	printf("실제 pi값과의 차이= %f", PI - pi);
	*/ //연습문제 39

	/*int i;
	for (i = 500; i < 1001; i++) {
		if (i % 2 == 0 && i % 3 != 0 && i % 7 == 6) {
			int number = 0, sum = 0;
			number = i;
			while (number >= 10) {
				sum += number % 10;
				number /= 10;
			}
			sum += number;
			if (sum % 10 == 2) printf("%d", i);
		}
	}*/ //2018 중간고사 II. 2

	/*int i, a, p;
	for (i = 5; i < 10; i += 2) {
		a = i*i;
		p = 4 * i;
		if (p % 12 == 0 && a / 10 + a % 10 == p / 10 + p % 10)
			if (a == sqrt(a)*sqrt(a) && p == sqrt(p)*sqrt(p)) printf("%d\n", i);
	}*/ //연습문제 42

}