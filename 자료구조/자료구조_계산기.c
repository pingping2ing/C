#include<stdio.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
int count = 0;
typedef enum { lparen, rparen, plus, minus, times, divide, mod, end, operand, eos }precedence;
int stack[MAX_STACK_SIZE];
int expr[MAX_EXPR_SIZE];

precedence to_stack[MAX_STACK_SIZE];//infix to postfix 때 쓸 stack
static int isp[] = { 0,19,12,12,13,13,13,0 };
static int icp[] = { 20,19,12,12,13,13,13,0 };
typedef int element;

int eval();
precedence get_token(int* psymbol, int* pn);
void infix_to_postfix(void);
void push(int* ptop, element item);
element pop(int* ptop);
void to_push(int* ptop, precedence item);
precedence to_pop(int* ptop);
void print_token(precedence item);

int eval() {
	precedence token;
	int symbol;
	int op1, op2;
	int n = 0;
	int top = -1;
	token = get_token(&symbol, &n);
	while (token != end) {
		if (token == operand)
			push(&top, symbol - '0');
		else {
			op2 = pop(&top);
			op1 = pop(&top);
			switch (token) {
			case plus: push(&top, op1 + op2); break;
			case minus: push(&top, op1 - op2); break;
			case times: push(&top, op1 * op2); break;
			case divide: push(&top, op1 / op2); break;
			case mod: push(&top, op1 % op2); break;
			}
		}
		token = get_token(&symbol, &n);
	}
	return pop(&top);
}

precedence get_token(int* psymbol, int* pn) {
	*psymbol = expr[(*pn)++];
	switch (*psymbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '*': return times;
	case '/': return divide;
	case '%': return mod;
	case '$':return end;
	case NULL:return eos;
	default: return operand;
	}
}

void infix_to_postfix(void) {
	int symbol;
	precedence token;
	int n = 0;
	int top = 0;
	to_stack[0] = end;
	for (token = get_token(&symbol, &n); token != end; token = get_token(&symbol, &n)) {
		if (token == eos) continue;
		if (token == operand) { printf("%d ", symbol - '0'); expr[count++] = symbol; }
		else if (token == rparen) {
			while (to_stack[top] != lparen) print_token(to_pop(&top));
			to_pop(&top);
		}
		else {
			while (isp[to_stack[top]] >= icp[token]) print_token(to_pop(&top));
			to_push(&top, token);
		}
	}
	while ((token = to_pop(&top)) != end) print_token(token);
	printf("\n");
}

void push(int* ptop, element item) {
	stack[++ * ptop] = item;
}

element pop(int* ptop) {
	return stack[(*ptop)--];
}

void to_push(int* ptop, precedence item) {
	to_stack[++ * ptop] = item;
}

precedence to_pop(int* ptop) {
	return to_stack[(*ptop)--];
}

void print_token(precedence item) {
	switch (item) {
	case 2: printf("+ "); expr[count++] = '+'; break;
	case 3: printf("- "); expr[count++] = '-'; break;
	case 4: printf("* "); expr[count++] = '*'; break;
	case 5: printf("/ "); expr[count++] = '/'; break;
	case 6: printf("%% "); expr[count++] = '%'; break;
	}
}

int main() {
	int  i, j;
	char tmp[65] = { 0 };
	for (;;) {
		for (i = 0;; i++) {
			scanf("%s", tmp);
			if (tmp[0] != 'E') printf("입력스트링: %s\n", tmp);
			break;
		}
		if (tmp[0] == 'E') { printf("END-OF-OUT"); break; }
		count = 0;
		for (i = 0; ; i++) {
			if (tmp[i] >= '0') {
				int num = tmp[i] - '0';
				for (j = i + 1; tmp[j] >= '0'; j++) {
					num = num * 10 + (tmp[j] - '0');
					tmp[j] = NULL;
				}
				expr[count++] = num + '0';
			}
			else expr[count++] = tmp[i];
			if (tmp[i] == '$') break;
		}
		count = 0;
		printf("Postfix 형태: ");
		infix_to_postfix();
		expr[count] = '$';
		printf("계산 결과: %d\n\n", eval());
	}
}
