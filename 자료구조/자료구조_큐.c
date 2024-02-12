#include <stdio.h>
#define MAX_QUEUE_SIZE 20
typedef int element;
element queue[MAX_QUEUE_SIZE];
int key;
char data[15];
int rear = 0;
int front = 0;

void addq(int front, int*prear, element item) {
	*prear = (*prear + 1) % MAX_QUEUE_SIZE;
	if (front == *prear) {
		queue_full();
		return;
	}
	queue[*prear] = item;
}
void queue_full() {
	rear--;
	printf("FULL");
}
element deleteq(int *pfront, int rear) {
	element item;
	if (*pfront == rear) { return; queue_empty(); }
	*pfront = (*pfront + 1) % MAX_QUEUE_SIZE;
	return queue[*pfront];
}

void queue_empty() {
	printf("EMPTY");
	return;
}

int main() {

}