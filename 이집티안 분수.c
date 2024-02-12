#include<stdio.h>
int s,d,f,ar[1200000],n;
int main(int argc, char** argv) {	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

scanf("%d%d", &s,&f);
do{
	for(d=1;;d++){
		if((f/s)<d) {
			ar[n++]=d;
		break;}
	}
	s= s*d-f;
	f*=d;
	if(s==1) ar[n++]=f;
	else if(f%s==0) {
	ar[n++]=f/s; s=1;}
}while (s!=1);
for(d=0;d<n;d++){
	if(d==0) printf("1/%d", ar[d]);
	else printf("+1/%d", ar[d]);
}
}