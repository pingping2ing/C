#include<stdio.h>
#include<string.h>

int main() {
	float height = 0, weight = 0;
	int num;
	printf("Enter your feet: ");
	scanf("%d", &num);
	height += 12*num; num = 0;
	printf("Enter your inch: ");
	scanf("%d", &num);
	height += num;
	height *= (0.3048/12); num = 0;
	printf("Enter your weight(lb): ");
	scanf("%d", &num);
	weight = num*0.45359;
	weight = weight / ((height)*(height));
	printf("Your BMI is %.1f", weight);
}