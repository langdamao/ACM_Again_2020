#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int n,c,m,num[1005],wei[1005];
int ans,ans1;
int cal(){
	int now=0;
	int ret=0;
	for (int i=1;i<=n;i++){
		//cout<<i<<' '<<wei[i]<<' '<<ret<<' '<<now<<endl;
		if(wei[i]<=ret*i-now){
			now+=wei[i];
		}
		else {
			int tmp=wei[i];
			int left=ret*i-now;
			tmp-=left;
			ret+=(tmp+(i-1))/i;
			now+=wei[i];
		}
	}
	return ret;
}
int cal2(){
	int ret=0;
	for (int i=1;i<=n;i++){
		if(wei[i]>ans) ret+=wei[i]-ans;
	}
	return ret;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&c,&m);
		memset(wei,0,sizeof(wei));
		memset(num,0,sizeof(num));
		int x,y;
		for (int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			num[y]++;
			wei[x]++;
		}
		int maxnum=0;
		for (int i=1;i<=c;i++) maxnum=max(maxnum,num[i]);
		//cout<<maxnum<<endl;
		ans=cal();
		if(ans<maxnum) ans=maxnum;
		ans1=cal2();
		printf("Case #%d: %d %d\n",ca++,ans,ans1);
	}
	return 0;
}
