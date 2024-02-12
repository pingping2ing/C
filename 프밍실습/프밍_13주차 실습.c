#include <stdio.h> 

int main()
{
	int day, month, year, y1, y2, y, m, d, i=0, j=0, k, w;
	int months[12][50] = {0, };	// 각 월의 날짜를 저장한다. 초깃값으로 모두 0을 설정. 
	int dates[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 배열 0에는 저장 안함. 
	char week[][4] = {"일","월","화","수","목","금","토"};

	do { // 년도 입력하는 루프 
		printf("년도를 입력하시오 : ");
		scanf("%d", &year); 
		if (year <1583) { // 그레고리력은 1583년 이후부터 적용 
			printf("년도를 잘못 입력하였습니다.\n"); 
			continue; // 잘못된 입력이면 다시 받음 
		}
		break;
	} while (1);

	printf("\n%37d년\n\n", year); 
	for(month=1; month<13; month++) {	// 배열에 각각의 월에 해당하는 날짜 저장 
		y = year;
		m = month;
		d = 1;
		if (m < 3) {	// 1, 2월이면 전년도의 13, 14월로 계산 
			y--;		// 전년도 
			m += 12;	// 12를 더하여 13 또는 14로 계산 
		}
		y1 = y/100;	// 년도의 앞 두 자리(century) 
		y2 = y%100;	// 년도의 뒤 두 자리(year of century) 

		day = (21*y1/4) + (5*y2/4) + (26*(m+1)/10); // Zeller의 공식 
		day %= 7;		// 매월 1일의 요일 계산 

		if( month == 2 )	// 윤년일 때 2월 계산 
			if ( year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) )
				dates[2] = 29;	// 윤년이면 2월을 29로 설정 

		for(i=day; i<day+dates[month]; i++, d++)	// 한 달의 값을 저장 
			months[month-1][i] = d;		// 저장 위치에 따라 요일이 달라진다. 
			// 어떤 달의 1일이 수요일이면 {0, 0, 0, 1, 2, 3, ... }와 같이 저장된다. 
    }

    for(k=0; k<4; k++) {		// 한 단에 3달씩 4단 출력 
		for(i=1; i<4; i++)		// 월 제목 출력 
			printf("%11d월%11s", k*3+i, "");
		printf("\n\n");
		for(i=0;i<3;i++) {		// 한 줄에 세 번씩 출력 
			for(j=0;j<7;j++)	// 일, 월, 화, 수, 목, 금, 토요일 출력 
				printf("%3s", week[j]);
			printf("%3s", ""); // 다음 달의 일요일이 시작하기 전에 공백 출력 
		}
		printf("\n");
		for(w=0; w<6; w++) { 	// 각 주별로 출력, 최대 6주 
			for(i=0;i<3;i++) {	// 3개월을 한 줄에 한 주씩 출력 
				for(j=0;j<7;j++) {			// 1주일 출력 
					if(months[k*3+i][j+w*7] != 0)	// 저장된 값이 0이 아니면 
						printf("%3d", months[k*3+i][j+w*7]);
					else				// 저장된 값이 0일 때 
					    printf("%3s", "");// 날짜가 없는 곳에 빈 공백 출력 
				}
				printf("%3s", ""); // 한 단의 월과 월 사이 공백 출력 
			}
			printf("\n"); // 한 줄 출력하고 줄 바꿈 
		}
		printf("\n"); 	// 한 단 출력하고 줄 바꿈 
	}
}

//6장 연습문제 20

/*#include <stdio.h> 
int gcd(int, int);  // gcd함수의 함수 원형(prototype) 
int lcm(int, int);  // lcm함수의 함수 원형(prototype) 

main() 
{ 
	int i, j; 
	printf("최소공배수를 구할 두 수를 입력하시오.(x, y) : "); 
	scanf("%d %d", &i, &j); 
	printf("두 수의 최소 공배수는 %d이다.\n", lcm(i, j)); // lcm함수 호출 
} 

int gcd(int a, int b) // greatest common divisor 
{
	while(a != b)
		a>b ? (a-=b) : (b-=a); // 뺄셈을 이용한 유클리드 호제법 
	return a;		// 결과값(최대공약수) 반환 
}

int lcm(int x, int y) // least common multiple  
{
	return (x*y/gcd(x,y));		// gcd함수 호출 및 결과값(최소공배수) 반환 
}

*/
//8장 연습문제 2

/*#include <stdio.h> 
#include <math.h>    // sqrt() 함수를 사용하기 위한 header file 

int isprime(int);

main()
{
	int j, prime = 1 ;

	for (j=2; j<=100; j++) // 2부터 100까지 루프를 돌고 
		isprime(j) ? printf("%d는 소수이다.\n", j): printf("%d는 소수가 아니다.\n", j);
}

int isprime(int x)
{
	int prime=1, i, iteration;
	iteration = (int)sqrt(x);
	for (i=2; i<=iteration; i++) {  //i는 2부터 루트x까지 중에서 
		if (x%i == 0) {	// x를 i로 나누어서 나머지가 0 이면 소수가 아니다. 
			prime = 0;
			break;
		}
	}
	return prime;
}
*/
//8장 연습문제 3

#include <stdio.h>
int combi(int, int);

/*
main()
{
	int n=10, p=7;
	printf("%d\n", combi(n, p));
}

int combi(int n, int p)
{
	int i, np; 
int denominator = 1, numerator = 1; 
if (p < n - p) {
	np = p;
	p = n - p;
}
else
np = n - p;

for (i = n; i > p; i--) 
denominator *= i;
for (i = 1; i <= np; i++) 
numerator *= i;
return denominator / numerator;
}*/


//8장 연습문제 13

/*#include <stdio.h>
int permu(int, int);

int main() {
	int n=10, r=4;
	printf("%d\n", permu(n, r));
}

int permu(int n, int r) {
	int i;
	int denominator=1;
	for(i=n; i>n-r; i--)	// n부터 n-r+1 까지 곱셈의 값을 구한다. 
		denominator *= i;
	return denominator;
}
*/

//8장 연습문제 14

