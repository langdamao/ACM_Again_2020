#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 5*(1e5)+5;
int l[N];
int maxdp[N][36],mindp[N][36];
int n,k;
int a[N];

void work(){
	for (int i=0;i<n;i++){
		maxdp[i][0]=a[i];
		mindp[i][0]=a[i];
	}
	for (int j=1;(1<<j)<n;j++){
		for (int i=0;i+(1<<j)-1<n;i++){
			maxdp[i][j] = max(maxdp[i][j-1],maxdp[i+(1<<(j-1))][j-1]);
			mindp[i][j] = min(mindp[i][j-1],mindp[i+(1<<(j-1))][j-1]);
		}
	}
}
int getMax(int x,int y){
	int k = l[(y-x)+1];
	return max(maxdp[x][k],maxdp[y-(1<<k)+1][k]);
}
int getMin(int x,int y){
	int k = l[(y-x)+1];
	return min(mindp[x][k],mindp[y-(1<<k)+1][k]);
}
int main(){
	int now =0;
	int nower =1;
	for (int i=0;i<N;i++){
		if (nower<=i) {
			nower<<=1;
			now++;
		}
		l[i]=now-1;
	}
	l[0]=0;
	while(scanf("%d%d",&n,&k)!=EOF){
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		work();
		int x,y;
		for (int i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			x--;y--;
			printf("%d\n",getMax(x,y)-getMin(x,y));
		}
	}
	return 0;
}
