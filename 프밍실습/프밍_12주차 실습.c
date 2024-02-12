#include <stdio.h> 

int gcd(int a, int b)
{
	int z = 1;
	while (z != 0) {
		z = a % b;
		a = b;
		b = z;
	}
	return a;
}

/*
int main()
{
	int i, j;
	printf("최대공약수를 구할 두 수를 입력하시오. ");
	scanf("%d%*c%d", &i, &j);
	printf("두 수의 최대 공약수는 %d이다.\n", gcd(i, j));
	printf("48과 56의 최대 공약수는 %d이다.\n", gcd(48, 56));
}*/

//예제 8-1-3
/*int main()
{
	int i, j;
	for(i=1; i<1000; i++)
		for(j=i+1; j<1000; j++)
			if(is_friendly_no(i,j))
				printf("%d, %d는 친화수이다.\n", i, j); 
} 

int sum_of_exact_divisor(int x)
{
	int i, sum=0;
	for(i=1; i<=x/2; i++)
		if(x % i == 0)
			sum += i;
	return sum;
}

int is_friendly_no(int x, int y)
{
	int sum1, sum2;
	sum1 = sum_of_exact_divisor(x);
	sum2 = sum_of_exact_divisor(y);
	if( sum1 == y && sum2 == x)
		return 1;
	else 
		return 0;
}
*/ 
//예제 8-1-4 



double triangle_area(int x, int y, int z) {
	double s;
	s = (x + y + z) / 2.0;
	return sqrt(s * (s - x) * (s - y) * (s - z));
}

int is_triangle(int i, int j, int k) {
	if (i <= 0 || j <= 0 || k <= 0) 
		return 0;
	if (i + j < k || i + k < j || j + k < i)
		return 0;		
	else
		return 1;		
}/*
int main()
{
	int i, j, k;
	printf("첫 번째 수를 입력하시오 : ");
	scanf("%d", &i);
	printf("두 번째 수를 입력하시오 : ");
	scanf("%d", &j);
	printf("세 번째 수를 입력하시오 : ");
	scanf("%d", &k);
	if (is_triangle(i, j, k))
		printf("삼각형의 면적은 %f이다.\n", triangle_area(i, j, k));
}
*/
//예제 8-1-5 가장 큰 변의 길이가 나머지 두 변의 길이보다 커야하는데 같아도 넓이를 구해준다



char day[][4] = { "일", "월", "화", "수", "목", "금", "토" };
int zeller(int y,int m,int d) {
	/*if (m == 1 || m == 2) { 	
		m += 12;
		y -= 1;
	}
	return (21 * (y / 100)) / 4 + (5 * (y % 100)) / 4 + (26 * (m + 1)) / 10 + d - 1;
	*/

	/*int y1, y2,day;
	y1 = y / 100;
	y2 = y % 100;
	day = y1 / 4 - 2 * y1 + y2 + y2 / 4 + (26 * (m + 1) / 10) + d - 1;
	while (day < 0) day += 7;
	return day;*/
}
void gregorian(int y, int m, int d) { 
	int weekday;
	
	weekday = zeller(y, m, d);
	printf("%d년 %d월 %d일은 %s요일입니다.\n\n", y, m, d, day[weekday % 7]);
	return;
	
}


void one_month_cal(int y, int m) {
	int i, j = 0, weekday, lastday;
	
	weekday = zeller(y, m, 1);
	weekday %= 7; 
	printf("%14d년 %d월\n\n", y, m);

	for (i = 0; i < 7; i++)
		printf("%4s", day[i]);
	printf("\n");

	for (i = 0; i < weekday; i++, j++)
		printf("%4s", "");

	lastday = last_day(y, m);
	for (i = 1; i <= lastday; i++) {
		j++;
		printf("%4d", i);
		if (j == 7) {
			printf("\n");
			j = 0;
		}
	}
	printf("\n");
}

int last_day(int y, int m) 
{
	int dates_per_month[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (m == 2 && (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)))
		m = 0;
	return(dates_per_month[m]);
}

int valid_date(int y, int m, int d)
{
	if (m < 1 || m > 12 || d < 1 || d > 31)
		return(0);
	if (m == 2) {
		if ((y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) && d <= 29)
			return(1);
		else if (!(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) && d <= 28)
			return(1);
		else
			return(0);
	}
	else {
		if ((m == 4 || m == 6 || m == 9 || m == 11) && d <= 30)
			return(1);
		else if ((m == 1 || m == 3 || m == 5 || m == 7 ||
			m == 8 || m == 10 || m == 12) && d <= 31)
			return(1);
		else
			return(0);
	}
}
/*
int main()
{
	int year, month, date;
	printf("그레고리력은 1582년 10월 15일 이후부터 계산이 가능합니다.\n");

	while (1) {
		printf("\n연도를 입력하시오(0:exit) : ");
		scanf("%d", &year);

		if (year <= 0) {		
			printf("Bye...\n");
			break;
		}
		printf("월을 입력하시오 : ");
		scanf("%d", &month);
		printf("일을 입력하시오 : ");
		scanf("%d", &date);

		if (!valid_date(year, month, date)) {
			printf("날자가 잘못 입력되었으므로 다시 ");
			printf("입력하여주시기 바랍니다.\n");
			continue;
		}
		printf("\n\n");

		if (year > 1582 || (year == 1582 && month > 10) ||
			(year == 1582 && month == 10 && date >= 15))
			gregorian(year, month, date);
		else if (year < 1582 || (year == 1582 && month < 10)
			|| (year == 1582 && month == 10 && date < 15)) {
			printf("이 날자는 그레고리력에는 없는 날입니다.\n");
			continue;
		}
		one_month_cal(year, month);
	}
}*/
//예제 8-1-6

int isperfect_no(int x)
{
	int sum = 0, j;	
	for (j = 1; j <= x / 2; j++)	
		if (x % j == 0) sum += j;
	return ((x == sum) ? 1 : 0);	
}
/*
int main()
{
	int i;		 
	for (i = 2; i <= 40000000; i++) {
		if (isperfect_no(i))	
			printf("%d은(는) 완전수이다.\n\n", i);
	}
}*/
//유제 8-1-2

double average(int array[], int x)
{
	int i, sum = 0;
	for (i = 0; i < x; i++)
		sum += array[i];
	sum -= (findMaxNum(array, 7) + findMinNum(array, 7));
	return ((double)sum / (double)(x - 2));
}

int findMaxNum(int number[], int elements) 
{
	int largest_value, i;
	largest_value = number[0];
	for (i = 0; i < elements; i++)
		if (number[i] > largest_value)
			largest_value = number[i];
	return largest_value;
}

int findMinNum(int number[], int elements)
{
	int i, smallest_value;
	smallest_value = number[0];	
	for (i = 1; i < elements; i++)
		if (smallest_value > number[i])
			smallest_value = number[i];
	return smallest_value;
}

/*int main()
{
	int num[7] = { 9, 8, 9, 7, 9, 10, 6}, i;
	printf("심판들의 점수 ");
	for(i=0; i<7; i++)
		printf(" %d  ", num[i]);
	printf("\n 이 선수의 점수 : %f\n", average(num, 7));
}
*/
//예제 8-3-2



