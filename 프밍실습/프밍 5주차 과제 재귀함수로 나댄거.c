#include <stdio.h>
void reverse_it(int num) {
	if (num == 0) return;
	else if (num % 10 == 0) printf("%d", num);
	printf("%d", num % 10);
	reverse_it(num / 10);
}

int main() {
	int number;
	scanf("%d", &number);
	reverse_it(number);
}