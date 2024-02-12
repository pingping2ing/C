#include <stdio.h>
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int s = 0, d, f, we[120] = { 0 }, n = 0,w=0,e=0;
	char ar[120][120] = { 0 };
	for (d = 1; d <= 10; d++) {
		for (f = 1; f <= 10; f++) {
			scanf(" %c", &ar[d][f]);
			if (ar[d][f] == '1'&&ar[d][f - 1] == '0'&&ar[d][f - 2] == '1')s++;
			if (ar[d][f] == '1') { 
				if(we[0] == 0 && we[1] == 0) { we[0] = d; we[1] = f; }
				we[4] = d; we[5] = f; }
		}
	}
	if (s > 0) printf("0");
	else {
		for (d = 1; d <= 10; d++) {
			if (ar[we[0]][we[1] + d] == '1') { we[2] = we[0]; we[3] = we[1] + d; w++; }
			else if (ar[we[4]][we[5] - d] == '1') { we[2] = we[4]; we[3] = we[5] - d; e++; }
			else if(w==0&&e==0&&ar[(we[0]+we[4])/2][d]=='1') { 
				if (d < we[1]&&n==0) {
					we[2] = (we[0] + we[4]) / 2; we[3] = d; n++;
				}
				if (n == 0) { we[2] = (we[0] + we[4]) / 2; we[3] = d; }
			}
		}
		for (d = 0; d < 6; d++) {
			printf("%d ", we[d]);
			if (d % 2 == 1) printf("\n");
		}
	}
}