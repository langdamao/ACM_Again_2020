#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int N=1005;
int d[N][N];
int n,m;
inline int lowbit(int &x){
	return x&(-x);
}
int sum(int x,int y){
	int ret=0;
	for (int i=x;i>0;i-=lowbit(i)){
		for (int j=y;j>0;j-=lowbit(j)){
				ret^=d[i][j];
		}
	}
	return ret;
}
void  update(int x,int y){
	for (int i=x;i<=n;i+=lowbit(i)){
		for (int j=y;j<=n;j+=lowbit(j)){
				d[i][j]^=1;
		}
	}
}
int main(){
	int x,y,x1,y1;
	char ty;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(d,0,sizeof(d));
		for (int i=0;i<m;i++){
			scanf(" %c",&ty);
			if (ty=='Q'){
				scanf("%d%d",&x,&y);
				printf("%d\n",sum(x,y));
			}
			else {
			  scanf("%d%d%d%d",&x,&y,&x1,&y1);
			  x1++;y1++;
			  update(x,y);
			  update(x,y1);
			  update(x1,y);
			  update(x1,y1);
			}
		}
		puts("");
	}
	return 0;
}
