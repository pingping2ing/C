#include<stdio.h>

int main(int argc, char** argv) {	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

int s,d;
double ar[120000]={0},max=0,mm=1, mk=1;

scanf("%d", &s);
for(d=0;d<s;d++){
	scanf("%lf", &ar[d]);
}
for(d=0;d<s;d++){
	printf("d=%d mm=%lf mk=%lf\n", d,mm,mk);
	if(ar[d]>mm*ar[d]) {mm=1;}
	mm*=ar[d];
	if(mk*ar[d]>mm) {mm=mk*ar[d];}
	printf("d=%d mm=%lf mk=%lf\n", d,mm,mk);
	if(ar[d]<mk*ar[d])  {mk=1;}
	mk*=ar[d];
	printf("d=%d mm=%lf mk=%lf\n", d,mm,mk);
	if(max<mm) 	max=mm;
}
printf("%.3lf",max);
} 