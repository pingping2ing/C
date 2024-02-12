#include <stdio.h>
#include <stdlib.h>

typedef struct enroll_s {
	int id_num;
	int course_num;
	struct enroll_s* left;
	struct enroll_s* right;
} *enroll_sp;

enroll_sp courses[35];
enroll_sp students[500];

int search(int student_id, int course_id) { // 중복 or 미등록 찾기

	if (courses[course_id - 100] == NULL || students[student_id - 2000] == NULL) return 0; 
	enroll_sp temp=students[student_id-2000];
	if (temp->course_num == course_id && temp->id_num == student_id) return 1;
	for (; temp->left; temp = temp->left) {
		if (temp->course_num == course_id && temp->id_num == student_id) return 1;
	}
	return 0;
}

void insert(enroll_sp *s_before, enroll_sp *c_before, int student_id, int course_id) {

	enroll_sp s_temp = *s_before, c_temp = *c_before;
	enroll_sp new_node = (enroll_sp)malloc(sizeof(struct enroll_s));

	new_node->left = NULL;
	new_node->right = NULL;
	if (*s_before == NULL) *s_before = new_node;
	else {
		if (s_temp->course_num < course_id) {
			for (; s_temp->left; s_temp = s_temp->left)
				if ((s_temp->left->course_num) > course_id) break;
		
		new_node->left = s_temp->left;
		s_temp->left = new_node;
		}
		else {
			new_node->left = s_temp;
			*s_before = new_node;
		}
	}
	if (*c_before == NULL) *c_before = new_node; 
	else {
		if (c_temp->id_num < student_id) {
			for (; c_temp->right; c_temp = c_temp->right)
				if ((c_temp->right->id_num) > student_id) break;

			new_node->right = c_temp->right;
			c_temp->right = new_node;
		}
		else {
			new_node->right = c_temp;
			*c_before = new_node;
		}
	}
	if (new_node != NULL) {
		new_node->id_num = student_id;
		new_node->course_num = course_id;
	}
}
// head 연결 할 때 s_before->left==students[student_id-2000]

void ddelete(enroll_sp* s_before, enroll_sp* c_before, int student_id, int course_id) {
	enroll_sp s_removed = *s_before;
	enroll_sp c_removed = *c_before;
	enroll_sp removed;
	if (s_removed == NULL || c_removed == NULL) fprintf(stderr, "The linked-list in empty\n");
	if (s_removed->course_num == course_id) {
		*s_before = s_removed->left;
		
	}
	else {
		for (; s_removed->left; s_removed = s_removed->left) if (s_removed->left->course_num == course_id) break;
		removed = s_removed->left;
		s_removed->left = removed->left;
	}
	if (c_removed->id_num == student_id) {
		*c_before = c_removed->right;
		removed = c_removed;
	}
	else {

		for (; c_removed->right; c_removed = c_removed->right) if (c_removed->right->id_num == student_id) break;
		removed = c_removed->right;
		c_removed->right = removed->right;
	}
	free(removed);
}

int main() {
	char num[10];
	int student_id = 0, course_id = 0, n = 0, card = 0, regis = 0, cancel = 0, error = 0;

	FILE* input = NULL, * output = NULL;
	fopen_s(&input,"data_input.txt", "rt");
	fopen_s(&output,"data_output.txt", "wt");

	if (input == NULL || output == NULL) {
		printf("Error opening file\n");
		exit(1);
	}

	while (fscanf(input, "%s", num) != EOF) {
		if (n >= 3) {n = 0; student_id = course_id = 0; }
		if (n == 0) {
			for (int i = 0; i < 3; i++) {
				student_id += num[i] - '0';
				student_id *= 10;
			}
			student_id += num[3] - '0';
		}
		else if (n == 1) course_id = (num[0] - '0') * 100 + (num[1] - '0') * 10 + num[2] - '0';
		else {
			card++;
			if (student_id >= 2500 || student_id < 2000) {
				fprintf(output, "  %d  %d  %c    **유효하지 않는 학생 ID**\n", student_id, course_id, num[0]);
				error++;
				n++;
				continue;
			}
			else if (course_id >= 135 || course_id < 100) {
				fprintf(output, "  %d  %d  %c    **유효하지 않는 코스 ID**\n", student_id, course_id, num[0]);
				error++;
				n++;
				continue;
			}

			else if (num[0] == 'A') {
				if (search(student_id, course_id)) {

					fprintf(output, "  %d  %d  %c    ** 중복 등록 **\n", student_id, course_id, num[0]);
					error++;
					n++;
					continue;
				}

				else {
					regis++;
					insert(&students[student_id - 2000], &courses[course_id - 100], student_id, course_id);
				}
			}
			else if (num[0] == 'D') {
				if (search(student_id, course_id)) {
					ddelete(&students[student_id - 2000], &courses[course_id - 100], student_id, course_id);
					cancel++;
				}
				else {
					fprintf(output, "  %d  %d  %c    ** 미등록 **\n", student_id, course_id, num[0]);
					error++;
				}
			}
			else {
				fprintf(output, "  %d  %d  %c    **'A'혹은 'D'가 아님**\n", student_id, course_id, num[0]);
				error++;
			}
		}
		n++;
	}
	if (error == 0) fprintf(output, "에러가 없습니다.\n");
	for (int i = 0; i < 35; i++) {
		if (courses[i] == NULL) continue;
		enroll_sp  temp;
		temp = courses[i];
		fprintf(output,"%d:   ",i+100);
		for (;; temp = temp->right) {
			fprintf(output,"%d   ", temp->id_num);
			if (temp->right == NULL) break;
		}
		fprintf(output, "\n");
	}
	fprintf(output, "\n[입력 보고]   읽은 카드 수: %d  유효 등록: %d  취소: %d", card, regis, cancel);
	fclose(input);
	fclose(output);
}