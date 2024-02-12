#include<stdio.h>

int main(int argc, char** argv) {	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
int s,d;
double ar[12000]={0}, max=0, mm=1;
scanf("%d", &s);
for(d=0;d<s;d++)scanf("%lf", &ar[d]);
max=ar[0];
for(d=0;d<s;d++){
	if(ar[d]>mm*ar[d]) mm=1;
	mm*=ar[d];
	if(max<mm) max=mm;
}
printf("%.3lf",max);
}