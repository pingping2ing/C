#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*int* get_p() {
	int *p;
	p = (int*)malloc(sizeof(int));
	if (p != NULL) *p = 20;
	return p;
}*/ //setset
int main() {
	/*char arr[120] = "watermelon", str[10] = "apple";
	strcpy(arr, str);
	for (int i = 0; i < 20; i++) printf("%c", arr[i]);
	*/
	/*int num;
	int *p = &num;
	*p = 3;
	printf("%d %d", num, *p);
	*/
	/*int *ptr;
	ptr = get_p();
	printf("%d", *ptr);
	free(ptr);
	ptr=NULL;
	return 0;
	*/ //setset
	/*int *p = (int*)malloc(sizeof(int));
	int *q = (int*)malloc(sizeof(int));
	*p = 10; *q = 20;
	q = p;
	printf("%d", *q);*/// 결과 10 
	//여기서 20은 낙동강 오리알신세 이렇게 프로그램 짜지마!
	/*int i;
	char *name = arg[1];
	int age = atoi(arg[2]);

	printf("ar==%d\n", ar);
	printf("%s is %d years old\n", name, age);

	for (i = 1; i < ar; i++) printf("%s ", arg[i]);
	printf("\n");
	return 0;*/
	/*int ch;
	for (;;) {
		ch = getchar();
		if (ch == EOF)break;
		else putchar(ch);
	}*/
	/*int ch, state;
	state = 0;
	for (ch = getchar(); ch != '\n'; ch = getchar()) {
		if (islower(ch)) putchar(toupper(ch));
		else if (isupper(ch)) putchar(tolower(ch));
		else putchar(ch);
	}
	printf("\n");*/

	/*int ch;
	FILE *src = fopen("input1.txt", "rt");
	FILE *dest = fopen("output1.txt", "wt");
	if (src == NULL || dest == NULL)exit(1);
	while ((ch = fgetc(src))!=EOF) {
		if (islower(ch))ch = toupper(ch);
		fputc(ch, dest);
	}
	fclose(src);
	fclose(dest);
	return 0; 진짜 나는 천재다*/

	/*FILE *src = fopen("input2.txt", "rt");
	FILE *dest = fopen("output2.txt", "wt");
	int ch,chh;
	while (!feof(src)) {
		fscanf(src,"%d%d", &ch, &chh);
		fprintf(dest,"%d\n", ch + chh);
	} 권태완 개천재 무서운놈 하나배우면 백을 아는놈*/
	/*int ar;
	scanf("%d", &ar);
	char *p = (char*)malloc(ar*sizeof(char));

	for (int i = 0; i < ar; i++) {
		scanf("%c", &p[i]);
	}
	*(p+ar) = '\0';
	printf("%s", p);
	*/
	/*	int ar,sum=0;
	scanf("%d", &ar);
	int *p = (int*)malloc(sizeof(int)*ar);
	for (int i = 0; i < ar; i++) {
		*(p + i) = 1 + rand() % ar;
		sum += *(p + i);
	}
	printf("%d", sum);*/

/*	int n, i;
	printf("n을 입력하세요: ");
	scanf("%d", &n);
	int *p = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		*(p + i) = i*i;
		printf("%d ", *(p + i));
	}
	printf("\nm을 입력하세요: ");
	int m;
	scanf("%d", &m);
	p = (int*)realloc(p, m * sizeof(int));
	for (i = n; i < m; i++) {
		*(p + i) = i*i;
	}
	for (i = 0; i < m; i++) printf("%d ", *(p + i));
	printf("\n");
*/

}