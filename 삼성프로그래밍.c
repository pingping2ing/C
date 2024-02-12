#include<stdio.h>
#pragma warning(disable:4996)
long long int aa[200005] = { 0 }, bb[200005] = { 0 },num=0,num2=0,n;
void quickSort(long long int data[],int l, int r) {
	int left = l;
	int right = r;
	long long int pivot = data[(l + r) / 2];

	while (left <= right) {
		while (data[left] < pivot) left++;
		while (data[right] > pivot) right--;
		if (left <= right) {
			long long int temp = data[left];
			data[left] = data[right];
			data[right] = temp;
			left++;
			right--;
		}
	}
	if (l < right) {
		quickSort(data, l, right);
	}
	if (r > left) {
		quickSort(data, left, r);
	}
}
int main() {
	int t, f, k, d;
	setbuf(stdout, NULL);
	scanf("%d", &t);
	for (d = 0; d < t; d++) {
		num2 = 0;
		scanf("%d%d", &n, &k);
		for (f = 0; f < n; f++) {
			scanf("%d", &aa[f]);
		}
		for (f = 0; f < n; f++) {
			scanf("%d", &bb[f]);
		}
		quickSort(aa, 0, n-1);
		quickSort(bb, 0, n-1);
		for (f = 0; f < k; f++) {
			num = aa[f] + bb[k - f - 1];
			if (num > num2) num2 = num;
		}
		printf("Case #%d\n%lld\n", d + 1, num2);
	}
}