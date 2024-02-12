/*Jan
Feb
Mar
Apr
May
June
July
Aug
Sep
Oct
Nov
Dec

-----------Stack*/
#include<stdio.h>
#include <stdlib.h>

typedef struct {
	char mon[15];
}element;

typedef struct stack {
	element item;
	struct stack *link;
}*stack_ptr;

stack_ptr top;

void push(stack_ptr *ptop, element item) {
	stack_ptr temp = (stack_ptr)malloc(sizeof(struct stack));
	/*if (iS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}*/
	temp->item = item;
	temp->link = *ptop;
	*ptop = temp;
}

element pop(stack_ptr *ptop) {
	stack_ptr temp = *ptop;
	element item;
	/*if (IS_EMPTY(temp)) {
		fprintf(stderr, "The stack is empty\n");
		exit(1);
	}*/
	printf("%s\n",temp->item.mon);
	item = temp->item;
	*ptop = temp->link;
	free(temp);
	return item;
}

int main() {
	element ins;
	for (int i = 0; i < 12; i++) {
		scanf("%s", &ins);
		push(&top, ins);
	}
	printf("\nThe list contains\n");
	for (int i = 0; i < 12; i++) pop(&top);
}

-----------Queue
#include<stdio.h>
#include <stdlib.h>

typedef struct {
	char mon[15];
}element;

typedef struct queue {
	element item;
	struct queue *link;
}*queue_ptr;

queue_ptr front;
queue_ptr rear;

void insert(queue_ptr *pfront,queue_ptr *prear,element item){
	queue_ptr temp = (queue_ptr)malloc(sizeof(struct queue));
	/*if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}*/
	temp->item = item;
	temp->link = NULL;
	if (*pfront)
		(*prear)->link = temp;
	else *pfront = temp;
	*prear = temp;
}

element delete(queue_ptr *pfront) {
	queue_ptr temp = *pfront;
	element item;
	/*if (IS_EMPTY(*front)) {
	fprintf(stderr, "The memory is empty\n");
	exit(1);
	}*/
	printf("%s\n", temp->item.mon);
	item = temp->item;
	*pfront = temp->link;
	free(temp);
	return item;
}


int main() {
	element ins;
	for (int i = 0; i < 12; i++) {
		scanf("%s", &ins);
		insert(&front, &rear, ins);
	}
	printf("\nThe list contains\n");
	for (int i = 0; i < 12; i++) delete(&front);
}