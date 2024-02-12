#include<stdio.h>
int ar[220][220], we[1200],er[1200], color[1200], n, c,s,head,tail;
void rr(int a){
	tail=head+1;
	int d;
	we[a]=1;
	er[head]=a;
	color[a]=1;
	do{
	for(d=0;d<s;d++){
		if(ar[a][d]==1&&we[d]==0){
		    if(color[head]==1) color[tail]=2;
			else color[tail]=1;
			er[tail++]=d;
			we[d]=1;
		}
	}
	head++;
	a=er[head];
}while(head<tail);
}
int main(int argc, char** argv) {	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int d,f,s1,s2;
	scanf("%d%d", &s,&f);
	for(d=0;d<f;d++){
		scanf("%d%d", &s1, &s2);
		ar[s1][s2]=ar[s2][s1]=1;
	}
	rr(0);
	for(d=0;d<s;d++){
		if(we[d]==0) 
			rr(d);
	}
	if(n>0) printf("-1");
	else {
	for(d=0;d<s;d++){
		if(color[d]==1) n++;
		if(color[d]==2) c++;
	}
	if(n>=c) printf("%d",c);
	else printf("%d",n);
} 
}