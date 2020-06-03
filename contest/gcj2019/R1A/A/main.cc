#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int nn,mm,n,m;
int ansc;
int ansx[405],ansy[405];
void add(int x,int y,int basex,int basey,int isc){
	if (isc) {ansx[ansc]=y+basey;ansy[ansc]=x+basex;}
	else  {ansy[ansc]=y+basey;ansx[ansc]=x+basex;}
	ansc++;
	return ;
}
void dodouble(int x,int y,int basex,int basey,int isc){
	add(1,1,basex,basey,isc);
	add(2,y-1,basex,basey,isc);
	add(1,2,basex,basey,isc);
	add(2,y,basex,basey,isc);
	for (int i=3;i<=y;i++){
		add(1,i,basex,basey,isc);
		add(2,i-2,basex,basey,isc);
	}
}
int pretri[4][21][2]={
	1,1, 2,3, 3,1, 1,4, 2,2, 3,4, 1,3, 3,2, 2,4, 1,2, 3,3, 2,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	1,1, 2,4, 3,2, 2,5, 1,3, 2,1, 3,4, 2,2, 1,5, 2,3, 3,1, 1,2, 3,3, 1,4, 3,5, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
	1,1, 2,5, 3,2, 2,6, 1,3, 2,1, 3,4, 2,2, 1,5, 2,3, 3,6, 2,4, 3,1, 1,2, 3,3, 1,4, 3,5, 1,6, 0,0, 0,0, 0,0,
	1,1, 2,6, 3,2, 2,7, 1,3, 2,1, 3,4, 2,2, 1,5, 2,3, 3,6, 2,4, 1,7, 2,5, 3,1, 1,2, 3,3, 1,4, 3,5, 1,6, 3,7
};
int prefour[16][2]={
	1,1, 3,2, 1,3, 3,4, 4,2, 2,3, 4,4, 2,1, 3,3, 1,4, 2,2, 4,3, 2,4, 4,1, 1,2, 3,1 
};
void dotrible(int x,int y,int basex,int basey,int isc){
	for (int i=0;i<x*y;i++){
		add(pretri[y-4][i][0],pretri[y-4][i][1],basex,basey,isc);
	}
}
void dofour(int x,int y,int basex,int basey,int isc){
	for (int i=0;i<x*y;i++){
		add(prefour[i][0],prefour[i][1],basex,basey,isc);
	}
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&nn,&mm);
		n=min(nn,mm);
		m=max(nn,mm);
		int isc;
		if (n==nn) isc=0;
		else isc=1;
		ansc=0;
		printf("Case #%d: ",ca++);
		if (n==1) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		if (n==2 && m<5) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		if (n==3&&m<4) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		if ((n%2==0 && m>=5) || (m%2==0 && n>=5)){
			if ((n%2==0 && m>=5)) {
				for (int i=0;i<n;i=i+2){
					dodouble(2,m,i,0,0^isc);
				}
			}
			else {
				for (int i=0;i<m;i=i+2){
					dodouble(2,n,i,0,1^isc);
				}
			}
		}
		else {
			if (m>=5 || n==3){
				for (int i=0;i<n-3;i=i+2){
					dodouble(2,m,i,0,0^isc);
				}
				for (int i=0;i<m-7;i=i+4){
					dotrible(3,4,n-3,i,0^isc);
				}
				dotrible(3,m%4+4,n-3,m-m%4-4,0^isc);
			}
			else {
				dofour(n,m,0,0,0^isc);
			}
		}
		printf("POSSIBLE\n");
		for (int i=0;i<ansc;i++){
			printf("%d %d\n",ansx[i],ansy[i]);
		}
	}
}
