/*#include <stdio.h>

int WhatTriangle(int a, int b, int c);
char* TriangleSort[] = { "삼각형이 아님", "정삼각형", "이등변삼각형",
		"직각삼각형", "일반삼각형" };

int main()
{
	printf("%s\n", TriangleSort[WhatTriangle(5, 4, 3)]);
}

int WhatTriangle(int a, int b, int c)
{
	if (a + b < c || a + c < b || b + c < a)
		return 0;
	else if (a == b && b == c)
		return 1;
	else if (a == b || a == c || b == c)
		return 2;
	else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
		return 3;
	else
		return 4;
}
*/
// 8장 연습문제 33

#include <stdio.h>
#include <time.h> 

int HowManyDays(int, int, int);

int main()
{
	int day1, mon1, year1;
	int days;

	printf("생년월일 입력(년, 월 일): ");
	scanf("%d%*c%d%*c%d", &year1, &mon1, &day1);

	days = HowManyDays(year1, mon1, day1);
	printf("오늘까지 일 수는 %d일\n", days);
}

int HowManyDays(int year1, int mon1, int day1){
	int dd1, dd2, i, year2, mon2, day2;
	int month_day[] = {0, 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dates[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	time_t now;
	struct tm *today;

	now = time(0);
	today = localtime(&now);
	
	year2 = today->tm_year + 1900;
	mon2 = today->tm_mon + 1;
	day2 = today->tm_mday;
	printf("오늘은 %d년 %d월 %d일\n", year2, mon2, day2);

	// 태어난 해의 일 수 계산 
	dd1 = 365 - dates[mon1] - day1 + 1;
	if( year1 % 400 == 0 || (year1 % 100 != 0 && year1 % 4 == 0 ) ) {
		if(mon1 == 1 || ( mon1 == 2 && day1 < 29) )	// 생년이 윤년이고 2월 이전이면 
			dd1 += 1;		// 1일 더함 
	}

	// 태어난 다음 해부터 작년 12월 31일까지 계산 
	if(year2 - year1 > 1)
		dd1 = dd1 + (year2 - year1 - 1) * 365;
	// 해마다 윤년을 찾아 하루씩 더함 
	for(i=year1+1; i<year2; i++) {
		if( i % 400 == 0 || (i % 100 != 0 && i % 4 == 0 ) ){
			dd1++;
		}
	}

	// 올해의 오늘까지 계산 
	dd2 = dates[mon2] + day2;
	if( year2 % 400 == 0 || (year2 % 100 != 0 && year2 % 4 == 0 ) ) {
		if( mon2 > 2) 	// 올해가 윤년이고 2월 이후면 1을 더함. 
			dd2 ++;
	}

	return (dd1+dd2);
}

// 8장 연습문제 44

/*#include <stdio.h>

// 점수 계산을 쉽게 계산하기 위해서 0과 1번째 프레임을 0으로 둠
// 실제 점수의 저장은 2번째부터 저장됨.
int score[14][2] = {0,};
int frame_no, total[14]={0,};

void print_score(int, int);
int strike(int);
int not_strike(int);

void main(void)
{
	int i=1;
	while(i<13) { 
	// 보너스 2 프레임까지 계속한다.
	// 보너스 프레임까지 갈 필요가 없을 때는 중간에서 빠져나오는 부분이 있음.
		i++;
		printf("%d frame의 1구에서 쓰러진 핀의 개수를 입력하시오 = ", i-1);
		// 점수가 2부터 저장되므로 프레임 번호를 나타내기 위해 i-1을 사용함.
		scanf("%d", &score[i][0]);
		printf("\n");

		if(score[i][0] > 10 || score[i][0] < 0) {
			printf("잘못 입력되었습니다.\n\n");
			i--;  // 잘못된 경우 프레임 번호 유지하기 위함.
			continue;
		}
		else if(score[i][0] == 10) { // strike 인 경우
			if(!strike(i)) break;
		} else { // strike가 아닌 경우
			if(!not_strike(i)) break;
		}
	}
}

void print_score(int x, int y) { //x는 프레임 번호, y는 투구 번호
	int i;
	for(i=2; i<=11; i++)	// frame 번호 출력
		printf("%4dF ", i-1);
	printf("  B1F   B2F\n"); // 보너스 프레임 출력

	for(i=2; i<=x; i++) {	// 현재까지의 투구한 점수 출력
		if(score[i][0] == 10) // 스트라이크인 경우 S/-출력
			printf("  S/- ");
		else if(y == 0 && i == x) // 첫번째 투구만 이루어 졌을 경우
			printf(" %2d/- ", score[i][0]);
		else // 두번째 투구도 이루어진 경우.
			printf(" %2d/%1d ", score[i][0], score[i][1]);
	}

	for(i=x+1; i<=13; i++) // 투구하지 않은 프레임은 -/-로 출력
		printf("  -/- ");

	printf("\n");

	if(x > 11) x = 11; // 전체 점수는 10 프레임까지만 인쇄하면 됨.
	for(i=2; i<=x; i++) // 현재 프레임까지의 토털점수 출력
		printf("%5d ", total[i]);

	for( i=x+1; i<=11; i++) // 현재 프레임 이후 10프레임까지는 ---로 출력
		printf("  --- ");

	printf("  ---   --- "); // 보너스 프레임인 경우 ---로 출력.

	printf("\n\n");
}

// 스트라이크인 경우의 점수 계산
int strike(int i) // i : 프레임 번호
{
	if(score[i-2][0] == 10 && score[i-1][0] == 10) // 전에 더블인 경우
		total[i-2] = total[i-3] + 30;
	else if(score[i-1][0] != 10 && score[i-1][0] + score[i-1][1] == 10)
		// 전에 스페어 처리된 경우
		total[i-1] = total[i-2] + 20;

	print_score(i, 0);

	if(i == 12) {
		// 10번째 프레임이 스페어 처리된 경우,
		// 즉 보너스 투구 한번만 주어지는 경우 종료.
		if(score[i-1][0] != 10 && score[i-1][0] + score[i-1][1] == 10 ) return 0;
	}
	return 1; // 계속 투구하기 위함. return 0은 게임 종료.
}

// 스트라이크가 아닌 경우 두 번째 투구 후 점수 계산.
int not_strike(int i) // i : 프레임 번호
{
	if(score[i-2][0] == 10 && score[i-1][0] == 10) { // 전에 double한 경우
		total[i-2] = total[i-3] + 20 + score[i][0];
	} else if(score[i-1][0] != 10 && score[i-1][0] + score[i-1][1] == 10) {
		// 전에 spare처리 한 경우
		total[i-1] = total[i-2] + 10 + score[i][0];
	}

	print_score(i, 0); // 1구까지의 점수 출력

	if(i == 12) { 
	// 10번째 프레임이 스페어 처리된 경우, 즉 보너스 투구 한번만 주어지는 경우 종료.
		if(score[i-1][0] != 10 && score[i-1][0] + score[i-1][1] == 10 )
			return 0;
	} else if(i == 13) return 0; // 2번째 보너스 프레임인 경우는 무조건 끝냄.

	do { // 두 번째 투구.
		printf("%d frame의 2구에서 쓰러진 핀의 개수를 입력하시오 = ", i-1);
		scanf("%d", &score[i][1]);
		printf("\n");

		if(score[i][0] + score[i][1] > 10 || score[i][1] < 0) {
			printf("잘못 입력되었습니다.\n\n");
			continue;
		}

		if(score[i-1][0] == 10) { // 직전에 single인 경우
			if(score[i][0] + score[i][1] == 10) // 현재 spare처리한 경우
				total[i-1] = total[i-2] + 20;
			else { // 현재 미스한 경우
				total[i-1] = total[i-2]+10+score[i][0] + score[i][1];
				total[i] = total[i-1] + score[i][0] + score[i][1];
			}
		} else if(score[i][0] + score[i][1] < 10 )
			// 전에 스트라이크가 아니고 현재 미스인 경우
			total[i] = total[i-1] + score[i][0] + score[i][1];

		break;
	} while(1); // 잘못 입력되는 경우를 고려 do~while을 사용

	print_score(i, 1); // 2구를 던진 후의 점수 출력

	if(i == 12 && score[i-1][0] == 10)
	// 첫 번째 보너스 프레임이며,
	// 10번째 프레임에 스트라이크인 경우, 보너스 투구 2번으로 끝냄.
		return 0;
	else if(i == 11 && score[i][0] + score[i][1] < 10 )
	// 마지막 프레임에서 미스인 경우 끝냄.
		return 0;
	else
		return 1; // 계속 투구하기 위함. return 0은 게임 종료.
}
*/
// 8장 연습문제 43
