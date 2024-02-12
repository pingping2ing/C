#include <stdio.h>
int main() {
	int s,d,f,ar[120][10]={0}, we[120]={0},n=0,e0=9999,e1=9999,e2=0,e3=0;
	
	scanf("%d",&s);
	for(d=0;d<s;d++){
	scanf("%d",&we[d]);
		for(f=0;f<we[d];d++){
		scanf("%d%d",&ar[f][0],&ar[f][0]);
			ar[f][2]=ar[f][0]+10;	ar[f][3]=ar[f][1]+10;
			if(e0>ar[f][0]) e0=ar[f][0];
			if(e1>ar[f][1]) e0=ar[f][1];
			if(e2<ar[f][2]) e0=ar[f][2];
			if(e3<ar[f][3]) e0=ar[f][3];
		}
	}
	n=(e3-e1)*(e2-e0);


}



#include <stdio.h>
int main() {
	int ar[120000]={0},s,d,f,e=999999;
	scanf("%d",&s);
	for(d=0;d<s;d++){
	scanf("%d",&f);
		ar[f]=1;
		if(e>f) e=f;
	} f=0;
	for(d=e;d<e+s;d++){
	if(ar[d]==0){printf("NO"); f++; break;}
	}
	if(f==0) printf("YES");
}





