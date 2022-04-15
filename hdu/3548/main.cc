#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int N=105;
int d[N][N][N];
int n,m;
inline int lowbit(int &x){
	return x&(-x);
}
int sum(int x,int y,int z){
	int ret=0;
	for (int i=x;i>0;i-=lowbit(i)){
		for (int j=y;j>0;j-=lowbit(j)){
			for (int k=z;k>0;k-=lowbit(k)){
				ret^=d[i][j][k];
			}
		}
	}
	return ret;
}
void  update(int x,int y,int z){
	for (int i=x;i<=n;i+=lowbit(i)){
		for (int j=y;j<=n;j+=lowbit(j)){
			for (int k=z;k<=n;k+=lowbit(k)){
				d[i][j][k]^=1;
			}
		}
	}
}
int main(){
	int x,y,z,x1,y1,z1;
	int ty;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(d,0,sizeof(d));
		for (int i=0;i<m;i++){
			scanf("%d",&ty);
			if (ty==0){
				scanf("%d%d%d",&x,&y,&z);
				printf("%d\n",sum(x,y,z));
			}
			else {
			  scanf("%d%d%d%d%d%d",&x,&y,&z,&x1,&y1,&z1);
			  x1++;y1++,z1++;
			  update(x,y,z);
			  update(x,y,z1);
			  update(x,y1,z);
			  update(x,y1,z1);
			  update(x1,y,z);
			  update(x1,y,z1);
			  update(x1,y1,z);
			  update(x1,y1,z1);
			}
		}
	}
	return 0;
}
