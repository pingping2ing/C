#include<stdio.h>
int s,d,ar[1200000]={0},max=-9999,mm=0,start[1200000]={0},end=0,n=0;
int main(int argc, char** argv) {	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

scanf("%d", &s);
for(d=0;d<s;d++) {
scanf("%d", &ar[d]);
if(ar[d]<0)n++;}
if(n==s){
	for(d=0;d<s;d++){
		if(max<ar[d]) max=ar[d];
	}
}
else {
for(d=0;d<s;d++){
	mm+=ar[d];
	if(mm<0){mm=0;start[n++]=d+1;}
	if(max<mm) {
	max=mm;end=d;}
}
}
for(d=0;d<n;d++){
	if(start[d]>end) break;
}
printf("%d %d %d",start[d-1]+1,end+1,max);
} 