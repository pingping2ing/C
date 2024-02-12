#include<stdio.h>
int flag = 0;
void is_leapYear(int num) {
	if (num % 400 == 0 || (num % 100 != 0) && (num % 4 == 0)) flag=1;
	else flag = 0;
}
int main() {
	/*int year, mon, date;
	scanf("%d%d%d", &year, &mon, &date);
	is_leapYear(year);
	*/
	/*date++;
	if ((mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) && date > 31) {
		mon++; date = 1;
	}
	else if (flag >0 && mon == 2 && date > 29) { mon++; date = 1; }
	else if (flag == 0 && mon == 2 && date > 28) { mon++; date = 1; }
	else if (date > 30) { mon++; date = 1; }
	if (mon > 12) { year++; mon = 1; }
	printf("다음날은 %d년 %d월 %d일 입니다\n", year, mon, date);
	*/ //예제 3-6-3

	/*for (int i = 1800; i < 2201; i++) is_leapYear(i);
	printf("%d", flag);*/ //중간고사 1.5 이거 할 때는 flag++;

	/*for (int i = 0; i < 36600; i++) {
		date--;
		if (date == 0 && (mon == 4 || mon == 6 || mon == 8 || mon == 9 || mon == 11 || mon == 1)) { mon--; date = 31; }
		else if (date == 0 && mon == 3) {
			if (flag) date = 29;
			else date = 28;
			mon--;
		}
		else if (date == 0) { mon--; date = 30; }
		if (mon == 0) { year--; mon = 12; is_leapYear(year); }
	}
	printf("36600전 날은 %d년 %d월 %d일 입니다\n", year, mon, date); //중간고사 2.6
	*/

	/*char birth[7], dash[2], gender, etc[7];
	printf("주민등록번호를 입력하시오: ");
	scanf("%[^-]%[-]%c%[^\n]", birth, dash, &gender, etc);
	
	switch (gender) {
	case '1':
	case '3': 
	case '5': 
	case '7': printf("남자"); break;
	case '2':
	case '4': 
	case '6': 
	case '8': printf("여자"); break;
	}*/ //26

	/*int v;
	scanf("%d", &v);
	if (v < 111) printf("벌금은 0원 벌점은 0원 입니다~");
	else if (v<121) printf("벌금은 30000원 벌점은 0원 입니다~");
	else if (v<141) printf("벌금은 60000원 벌점은 15원 입니다~");
	else if (v<161) printf("벌금은 90000원 벌점은 30원 입니다~");
	else printf("벌금은 120000원 벌점은 60원 입니다~");
	*/
	
	/*int sum = 0;
	for (int i = 3; i < 33334; i++) {
		if (i % 3 == 0) sum += i;
	}
	printf("%d\n", sum);
	*/ //중간고사 1.3

	/*int n = 0;
	for (int i = 12345; i <= 12345679;i++) if (i % 3 == 0 && i % 7 == 0) n++;
	printf("%d\n", n);
	*/ //중간고사 1.4

	/*int number, n = 0;
	scanf("%d", &number);
	for (int i = 1; i < number / 2; i++) if (number%i == 0) n++;
	printf("%d", n);
	*/ //약수
	
	/*int i;
	double sum=0.0, sign = -1.0;
	for (i = 1;; i++) {
		sum += sign*(double)i / (double)(i + 1);
		sign=-sign;
		if (sum > 0.3) break;
	}
	printf("%d/%d",i,i+1);*/ //분수

	
}