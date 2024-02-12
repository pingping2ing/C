#include<stdio.h>
int s,d,f,ar[1200][1200],n=0;
int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &s);
	if(s%4==0){
		for(d=1;d<=s;d++){
			for(f=1;f<=s;f++){
				n++;
				if((d+f)%4==1||(d-f)%4==0) ar[d][f]=n;
			}
		} n=s*s+1;
		for(d=1;d<=s;d++){
			for(f=1;f<=s;f++){
				n--;
			if(ar[d][f]==0) ar[d][f]=n;	
			printf("%2d ", ar[d][f]);
			}
			printf("\n");
		}
	}
	else printf("impossible");
}