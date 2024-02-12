#include <stdio.h>
#include <string.h>
int main() {
	char name[25][10] = { 0 };
	int score[25][5] = { 0 }, sum[25] = { 0 }, rank[25] = { 0 }, i, j;
	float avg[25] = { 0 };
	FILE* input = fopen("hw12_data.txt", "rt");
	for (i = 0; i < 21; i++) {
			fscanf(input, "%6s", name[i]);
		fscanf(input, ", %d, %d, %d, %d", &score[i][0], &score[i][1], &score[i][2], &score[i][3]);
	}
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 4; j++) sum[i] += score[i][j];
		avg[i] = (float)sum[i] / 4;
		avg[i] += 0.005;
	}
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 21; j++) {
			if (sum[i] <= sum[j]) rank[i]++;
		}
	}
	for (i = 0; i < 21; i++) {
		if (strstr(name[i], "권태완"))
			printf("1) %s %d등 %d, %d, %d, %d 합계: %d 평균: %.1f\n", name[i], rank[i], score[i][0], score[i][1], score[i][2], score[i][3], sum[i], avg[i]);
	}
	printf("2)\n");
	for (i = 0; i < 3; i++) {
		int n = 1;
		if (i == 1) n = 2;
		if (i == 2) n = 10;
		for (j = 0; j < 21; j++) {
			if (rank[j] == n) printf("%2d등: %s 점수:%3d,%3d,%3d,%3d 합계:%d 평균:%.1f\n", rank[j], name[j], score[j][0], score[j][1], score[j][2], score[j][3], sum[j], avg[j]);
		}
	}
	printf("3)\n");
	for (i = 0; i < 21; i++) {
		printf("%s 점수:%3d,%3d,%3d,%3d 합계:%d 평균:%.1f\n", name[i], score[i][0], score[i][1], score[i][2], score[i][3], sum[i], avg[i]);
	}
}