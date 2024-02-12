#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* input = NULL, * output = NULL;

typedef struct item {
	int num;
	char name[40];
	int stock;
	int reorder;
	struct item* left_child;
	struct item* right_child;
}*tree_ptr;

tree_ptr ptr;

tree_ptr modified_search(tree_ptr root, int key) {//부모 node찾기
	tree_ptr pre_node = NULL;
	while (root) {
		if (key == root->num) return NULL;
		pre_node = root;
		if (key < root->num) root = root->left_child;
		else root = root->right_child;
	}
	return pre_node;
}

tree_ptr search(tree_ptr root, int key) {//자기자신 찾기
	while (root) {
		if (key == root->num) return root;
		if (key < root->num) root = root->left_child;
		else root = root->right_child;
	}
	return NULL;
}

tree_ptr search2(tree_ptr root, tree_ptr* pre_ptr, int key) {//pre_ptr의 값을 바꾸며 자기자신 찾기
	*pre_ptr = NULL;
	while (root) {
		if (key == root->num) return root;
		*pre_ptr = root;
		if (key < root->num) root = root->left_child;
		else root = root->right_child;
	}
	return NULL;
}

void insert_node(tree_ptr* node, int num, char name[], int stock, int reorder) {
	tree_ptr new_node, temp = modified_search(*node, num);
	if (temp || !(*node)) {
		new_node = (tree_ptr)malloc(sizeof(struct item));
		if (new_node == NULL) {
			printf("The memory is full\n");
			exit(1);
		}

		new_node->num = num;
		strcpy(new_node->name, name);
		new_node->stock = stock;
		new_node->reorder = reorder;
		new_node->left_child = NULL;
		new_node->right_child = NULL;
		if (*node) {
			if (num < temp->num) temp->left_child = new_node;
			else temp->right_child = new_node;
		}
		else *node = new_node;
	}
}

void delete_node(tree_ptr* root, int num) {
	tree_ptr pre_node = NULL;
	tree_ptr dnode = search2(*root, &pre_node, num);
	if (!dnode) return;
	if ((dnode->left_child == NULL) && (dnode->right_child == NULL)) {
		if (pre_node == NULL) { //자식 없는 root일 때
			free(*root);
			*root = NULL;
		}
		else { //부모 있고 자식 없는 node
			if (pre_node->right_child == dnode) pre_node->right_child = NULL;
			else pre_node->left_child = NULL;
			free(dnode);
		}
	}
	else if ((dnode->left_child != NULL) && (dnode->right_child != NULL)) { //자식이 둘 다 있을 때
		tree_ptr temp = NULL;
		pre_node = NULL;
		pre_node = dnode;
		temp = dnode->left_child;
		if (temp->right_child == NULL) { //pre_node의 왼쪽 child중 가장 가까이 있는 child가 가장 클 때
			pre_node->num = temp->num;
			strcpy(pre_node->name, temp->name);
			pre_node->stock = temp->stock;
			pre_node->reorder = temp->reorder;
			pre_node->left_child = temp->left_child;
		}
		else {
			while (temp->right_child) {//왼쪽 child에서 가장 오른쪽에 있는 node 찾기
				pre_node = temp;
				temp = temp->right_child;
			}
			dnode->num = temp->num;
			strcpy(dnode->name, temp->name);
			dnode->stock = temp->stock;
			dnode->reorder = temp->reorder;
			pre_node->right_child = temp->left_child;
		}
		free(temp);
	}
	else { //자식이 하나일 때
		tree_ptr temp = NULL;
		if (dnode->left_child == NULL) {
			temp = dnode->right_child;
			dnode->right_child = temp->right_child;
		}
		else {
			temp = dnode->left_child;
			dnode->left_child = temp->left_child;
		}

		dnode->num = temp->num;
		strcpy(dnode->name, temp->name);
		dnode->stock = temp->stock;
		dnode->reorder = temp->reorder;
		free(temp);
	}
}

void add_stock(tree_ptr root, int num, int stock_num) {
	tree_ptr node = search(root, num);
	node->stock += stock_num;
}
int remove_stock(tree_ptr root, int num, int stock_num) {
	tree_ptr node = search(root, num);
	if (node->stock < stock_num) return 1; //node가 nullptr이라고 뜸
	else node->stock -= stock_num;
	return 0;
}

void print_node(tree_ptr root) {
	if (root) {
		print_node(root->left_child);
		fprintf(output, "%d\t\t", root->num);
		for (int i = 0; i < 20; i++) {
			fprintf(output, "%c", root->name[i]);
		}
		fprintf(output, " \t %2d\t\t%d", root->stock, root->reorder);
		if (root->stock < root->reorder) fprintf(output, "\t*재주문 필요*");
		fprintf(output, "\n");
		print_node(root->right_child);
	}
}

int main() {
	char component[50] = { 0 }, component_name[30] = { 0 }, command;
	int com_num = 0, stock = 0, reorder = 0, stock_num = 0, i;

	fopen_s(&input, "data_input.txt", "rt");
	fopen_s(&output, "data_output.txt", "wt");

	if (input == NULL || output == NULL) {
		printf("Error opening file\n");
		exit(1);
	}
	while (fscanf(input, "%s", component) != EOF) {

		com_num = stock = reorder = stock_num = 0;
		command = component[0];
		if (command != 'X') {
			if (command == 'P') {
				fprintf(output, "\n컴포넌트 번호\t설명\t\t\t현재 재고량\t재주문 수준\n");
				print_node(ptr);
				continue;
			}
			fscanf(input, "%s", component);
			for (i = 0; i < 5; i++) {
				com_num += component[i] - '0';
				com_num *= 10;
			}
			com_num += component[i] - '0';
			if (com_num < 100001 || com_num>1000000) {
				fprintf(output, "%c\t%d\t컨포넌트 번호 에러\n", command, com_num);
				fgets(component, sizeof(component), input);//에러가 났으므로 이 줄 건너뛰기
				continue;
			}
			if (command == 'N') {
				if (search(ptr, com_num) != NULL) {
					fprintf(output, "%c\t%d\t컨포넌트 번호 중복\n", command, com_num);
					fgets(component, sizeof(component), input); //에러가 났으므로 이 줄 건너뛰기
					continue;
				}
				else {
					fgets(component, 22, input);
					strcpy(component_name, component);
					fscanf(input, "%s", component);
					for (i = 0; i < strlen(component) - 1; i++) {
						stock += component[i] - '0';
						stock *= 10;
					}
					stock += component[strlen(component) - 1] - '0';
					fscanf(input, "%s", component);
					for (i = 0; i < strlen(component) - 1; i++) {
						reorder += component[i] - '0';
						reorder *= 10;
					}
					reorder += component[i] - '0';
					insert_node(&ptr, com_num, component_name, stock, reorder);
				}
			}
			else if (command == 'D') {
				if (search(ptr, com_num) != NULL) delete_node(&ptr, com_num);
			}
			else if (command == 'A') {
				fscanf(input, "%s", component);
				for (i = 0; i < strlen(component) - 1; i++) {
					stock_num += component[i] - '0';
					stock_num *= 10;
				}
				stock_num += component[i] - '0';
				if (search(ptr, com_num) != NULL) add_stock(ptr, com_num, stock_num);
				else fprintf(output, "%c\t%d\t그러한 컨포넌트 없음\n", command, com_num);
			}
			else if (command == 'R') {
				fscanf(input, "%s", component);
				for (i = 0; i < strlen(component) - 1; i++) {
					stock_num += component[i] - '0';
					stock_num *= 10;
				}
				stock_num += component[i] - '0';
				if (search(ptr, com_num)) {
					if (remove_stock(ptr, com_num, stock_num)) fprintf(output, "%c\t%d\t재고량이 충분하지 않음\n", command, com_num);
				}
				else fprintf(output, "%c\t%d\t그러한 컨포넌트 없음\n", command, com_num);
			}
		}
	}
	fclose(input);
	fclose(output);
}