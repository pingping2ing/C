#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

void insertion_sort(int* a, int n);
void shell_sort(int* a, int n);
void quick_sort(int* a, int left, int right);
void adjust(int* a, int root, int n);
void heap_sort(int* a, int n);

void insertion_sort( int * a, int n) {
	int i, j;
	int next;
	for (i = 1; i <= n - 1; i++) {
		next = a[i];
		for (j = i - 1; j >= 0 && next < a[j]; j--) a[j + 1] = a[j];
		a[j + 1] = next;
	}
}

void shell_sort( int* a, int n) {
	int i, j, k, l, m;
	for (i = n / 2; i > 0; i /= 2) {
		for (j = 0; j < i; j++) {
			for (k = i + j; k < n; k += i) {
				l = a[k];
				m = k;
				while (m > i - 1 && a[m - i] > l) {
					a[m] = a[m - i];
					m -= i;
				}
				a[m] = l;
			}
		}
	}
}
void quick_sort(int* a, int left, int right) {
	int pivot, i, j,temp;
	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left];
		do {
			do i++;
			while (a[i] < pivot);
			do j--;
			while (a[j] > pivot);
			if (i < j) swap(a[i], a[j],temp);
		} while (i < j);
		swap(a[left],a[j],temp);
		quick_sort(&(*a), left, j - 1);
		quick_sort(&(*a), j + 1, right);
	}
}

void adjust(int* a, int root, int n) {
	int child, rootkey, temp;
	temp = a[root];
	rootkey = a[root];
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child] < a[child + 1])) child++;
		if (rootkey > a[child]) break;
		else {
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void heap_sort(int* a, int n) {
	int i,temp;
	for (i = n / 2; i > 0; i--) adjust(&(*a), i, n);
	for (i = n - 1; i > 0; i--) {
		swap(a[1], a[i + 1],temp);
		adjust(&(*a), 1, i);
		
	}
}


int main() {
	int ascending_order[10005] = { 0 }, descending_order[10005] = { 0 }, random[10005] = { 0 };
	int seed, n, i;
	double duration;

	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		ascending_order[i] = i;
		descending_order[i] = n - i + 1;
		random[i] = i;
	}
	seed = time(0);
	srand(seed);
	for (i = 0; i < 5000; i++) {
		int temp,a= rand() % n + 1,b= rand() % n + 1;
		swap(random[a], random[b],temp);
	}
	for (i = 1; i <= n; i++) printf("%d ", ascending_order[i]);
	printf("\n");
	clock_t start, finish;
	start = clock();
	insertion_sort(&random, n+1);
	//shell_sort(&random, n+1);
	//quick_sort(&random, 1,n);
	//heap_sort(&random, n);
	finish = clock();
	printf("%f\n", (double)(finish - start));
}