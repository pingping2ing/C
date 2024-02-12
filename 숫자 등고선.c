#include<stdio.h>
int s,d,f,ar[1200][1200],n=1, dd[4]={-1,0,0,1},ff[4]={0,-1,1,0},i,s1,s2;
int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

scanf("%d%d%d",&s,&s1,&s2); ar[s1][s2]=1;
for(i=0;;i++){
	for(d=1;d<=s;d++){
		for(f=1;f<=s;f++){
			if(ar[d][f]>0){
				for(int t=0;t<4;t++){
					if(ar[d+dd[t]][f+ff[t]]==0) ar[d+dd[t]][f+ff[t]]=ar[d][f]+1;
				}
			}
		}
	}
	if(ar[1][1]&&ar[1][s]&&ar[s][s]&&ar[s][1]>0) break; 
}
for(d=1;d<=s;d++){
	for(f=1;f<=s;f++){
		printf("%2d ", ar[d][f]);
	}
	printf("\n");
}

}