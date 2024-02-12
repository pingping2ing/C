#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node *left_child, *right_child;
}*tree_ptr;

tree_ptr modified_search(tree_ptr root, int key) {
	tree_ptr pre_node = NULL;
	while (root) {
		if (key == root->data) return NULL;
		pre_node = root;
		if (key < root->data) root = root->left_child;
		else root = root->right_child;
	}
	return pre_node;
}

void insert_node(tree_ptr* node, int num) {
	tree_ptr newnode = NULL, temp = NULL;
	temp = modified_search(*node, num);
	if (temp || !(*node)) {
		newnode = (tree_ptr)malloc(sizeof(struct node));
		if (newnode == NULL) {
			fprintf(stderr, "The memory is full\n");
			exit(1);

		}
		newnode->data = num;
		newnode->left_child = newnode->right_child = NULL;
		if (*node) {
			if (num < temp->data) temp->left_child = newnode;
			else temp->right_child = newnode;
		}
		else *node = newnode;
	}
}

tree_ptr iter_search2(tree_ptr root, tree_ptr* prevPtr, int key) {
	*prevPtr = NULL;
	while (root) {
		if (key == root->data) return root;
		*prevPtr = root;
		if (key < root->data) root = root->left_child;
		else root = root->right_child;
	}
	return NULL;
}

void delete_node(tree_ptr* root, int num) {
	tree_ptr prevNode = NULL;
	tree_ptr dnode = iter_search2(*root, &prevNode, num);
	if (!dnode) return;
	if ((dnode->left_child == NULL) && (dnode->right_child == NULL)) {
		if (prevNode == NULL) {
			free(*root);
			*root = NULL;
		}
		else {
			if (prevNode->right_child == dnode) prevNode->right_child = NULL;
			else prevNode->left_child = NULL;
			free(dnode);
		}
	}

	else if ((dnode->left_child != NULL) && (dnode->right_child != NULL)) {
		tree_ptr prev_node = NULL, temp = NULL;
		prev_node = dnode;
		temp = dnode->left_child;
		if (temp->right_child == NULL) {
			prev_node->data = temp->data;
			prev_node->left_child = temp->left_child;
		}
		else {
			while (temp->right_child) {
				prev_node = temp;
				temp = temp->right_child;
			}
			dnode->data = temp->data;
			prev_node->right_child = temp->left_child;
		}
		free(temp);
	}
	else {
		tree_ptr prev_node = NULL, temp = NULL;
		prev_node = dnode;
		if (prev_node->left_child) temp = prev_node->left_child;
		else temp = prev_node->right_child;
		prev_node->data = temp->data;
		prev_node->left_child = temp->left_child;
		prev_node->right_child = temp->right_child;
		free(temp);
	}
}

void inorder(tree_ptr ptr) {
	if (ptr) {
		inorder(ptr->left_child);
		printf("%d ", ptr->data);
		inorder(ptr->right_child);
	}
}​;

int main() {
	char num[10] = { 1,9,2,8,3,7,4,6,5 };
	tree_ptr ptr = NULL;
	printf("숫자 삽입: ");
	for (int i = 0; i < 9; i++) insert_node(&ptr, num[i]);
	inorder(ptr);
	printf("\n숫자 삭제: ");
	for (int i = 1; i < 6; i++) delete_node(&ptr, i);
	inorder(ptr);
}