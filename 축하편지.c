#include <time.h>
#include <stdio.h>
#include <Windows.h>

int main() {
	char name[10] = { 0 }, birth[10] = {0};
	printf("누구를 위한 편지인가요?: ");
	scanf("%s", name);
	printf("생일을 입력해주세용: ");
	for (int i = 0;i<9; i++) {
		scanf("%c", &birth[i]);
	}
	printf("오늘 생일이시군요!!\n\n");
	Sleep(1000);
	printf("~~~~%s을 위한 축하편지~~~~~\n",name);
	for (int i = 0; i < 9; i++) printf("%c", birth[i]);
	printf("인 오늘 생일인 %s을 위해 노래 부르겠습니다~",  name);
	Sleep(1000);
	printf("\n생일 축하합니다~\n");
	Sleep(1000);
	printf("생일 축하합니다~\n");
	Sleep(1000);
	printf("사랑하는 %s~~~~\n", name);
	Sleep(1000);
	printf("생일 축하합니다~~~~><\n");
	Sleep(1000);
	for (int i = 0; i < 100; i++) {
		printf("와아아아아아ㅏㅏ~~~~~~\b");
	}
}