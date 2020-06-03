#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
int ans[1005];

int main(){
	int T,w;
	scanf("%d%d",&T,&w);
	while(T--){
		for (int i=1;i<=w;i++){
			printf("%d\n",i);
			 cout<<flush;
			scanf("%d",&a[i]);
			if (a[i]==-1) return 1;
		}
		int x=(a[2]-a[1]);
		int y=(a[6]-2*a[3])/4;
		ans[1]=(y-x)/10;
		ans[2]=x-2*ans[1];
		ans[3]=(a[3]-a[2]-4*ans[1]);
		x = a[1]-2*ans[1]-ans[2]-ans[3];
		y = a[4]-16*ans[1]-4*ans[2]-2*ans[3];
		ans[4] = y-x;
		x = x-ans[4];
		y = a[5]-32*ans[1]-4*ans[2]-2*ans[3]-2*ans[4];
		ans[5]=y-x;
		ans[6]=x-ans[5];
		for (int i=1;i<=w;i++){
			printf("%d",ans[i]);
			if (i!=w) printf(" ");
		}
		printf("\n");
	    cout<<flush;
		scanf("%d",&a[0]);
		if (a[0]!=1) return 1;
	}
}
