#include<stdio.h>
int s,d,ar[1200000]={0},max=-99999,mm,start[1200000],end,n, startt, max1=-99999,max2, max3=-99999;
int main(int argc, char** argv) {	
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
*/
scanf("%d", &s);
for(d=0;d<s;d++){
	scanf("%d", &ar[d]);
}
for(d=0;d<s;d++){
	if(ar[d]>mm+ar[d]) {
	mm=0; start[n++]=d;}
	mm+=ar[d];
	if(max<mm) {
	max=mm;
	end=d;
}
} mm=0; // 젤큰 구간 찾기 
for(d=0;d<s;d++){
	if(start[d]>end) break;
} //가장 큰 구간 시작부분 
startt=start[d-1]; n=0;
for(d=0;d<s;d++){
	if(startt<=d&&end>=d) {
		mm=0;
	continue;}
	if(ar[d]>mm+ar[d]) mm=0;
	mm+=ar[d];
	if(max1<mm) max1=mm;
} mm=0; //가장 큰 구간 제외하고 젤 큰 구간 찾 기 
for(d=startt;d<=end;d++){
	if(n>ar[d]) n=ar[d];
} //가장 큰 구간에서 젤 작은수 찾기 
for(d=startt;d<=end;d++){
	if(ar[d]==n) {
		max2=mm;
		mm=0;
	break;}
	mm+=ar[d];
}
max3=max-(n+max2);
if(max2>max3) max2=max3;
if(max2>max1) max= max-n;
else max=max+max1;
printf("%d", max);
}