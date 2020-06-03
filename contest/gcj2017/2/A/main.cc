#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int n,p,num[10];
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&p);
		memset(num,0,sizeof(num));
		int x;
		for (int i=0;i<n;i++) {
			scanf("%d",&x);
			num[x%p]++;
		}
		int ans=num[0];
		if(p==2) ans+=(num[1]+1)/2;
		if(p==3) {
			ans+=min(num[1],num[2]);
			ans+=(max(num[1],num[2])-min(num[1],num[2])+2)/3;
		}
		if(p==4) {
			ans+=num[2]/2;
			num[2]%=2;
			int tmp=min(num[1],num[3]);
			ans+=tmp;
			num[1]-=tmp;
			num[3]-=tmp;
			int tmpx=max(num[1],num[3]);
			if(num[2]) {ans+=1; tmpx-=2;}
			if(tmpx>0) ans+=(tmpx+3)/4;
		}
		printf("Case #%d: %d\n",ca++,ans);
	}
}
