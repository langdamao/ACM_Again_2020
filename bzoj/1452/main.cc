#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int N=305;
int n,m;
int a[N][N];
int d[104][N][N];
inline int lowbit(const int &x){
	return x&(-x);
}
void update(int c,int x,int y,int k){
	for (int i=x;i<=n;i+=lowbit(i)){
		for (int j=y;j<=n;j+=lowbit(j)){
			d[c][i][j]+=k;
		}
	}
}
int sum(int c,int x,int y){
	int ret =0;
	for (int i=x;i>0;i-=lowbit(i)){
		for (int j=y;j>0;j-=lowbit(j)){
			ret+=d[c][i][j];
		}
	}
	return ret;
}
int main(){
	while( scanf("%d%d",&n,&m)!=EOF){
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
				update(a[i][j],i+1,j+1,1);
			}
		}
		int x,y,x1,y1,c;
		int q,ty;
		scanf("%d",&q);
		for (int i=0;i<q;i++){
			scanf("%d",&ty);
			if (ty==1){
				scanf("%d%d%d",&x,&y,&c);
				update(a[x-1][y-1],x,y,-1);
				update(c,x,y,1);
				a[x-1][y-1]=c;
			}
			else {
				scanf("%d%d%d%d%d",&x,&x1,&y,&y1,&c);
				x--;y--;
				printf("%d\n",sum(c,x1,y1)-sum(c,x,y1)-sum(c,x1,y)+sum(c,x,y));
			}
		}
	}
	return 0;
}
