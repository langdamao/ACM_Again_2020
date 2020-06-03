#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int a[10005];
int f[10005];
int n,k;
int T;
int calfei(int x){
	int retl = 0;
	int retr = 0;
	for (int i=x-1;i>=0;i--) {
		if(a[i]==-1) continue;
		if(a[i]<a[x])  {retl= a[i];break;}
	}
	for (int i=x+1;i<=n+1;i++){
		if(a[i]==-1) continue;
		if(a[i]<a[x]) {retr=a[i];break;}
	}
	return (a[x]-max(retl,retr));
}
int findleft(int x){
	for (int i=x-1;i>=0;i--){
		if(a[i]==-1) continue;
		return a[i];
	}
	return 0;
}
int findright(int x){
	for (int i=x+1;i<=n+1;i++){
		if(a[i]==-1) continue;
		return a[i];
	}
	return 0;
}
int cal(){
	int ret = 0;
	for (int i=1;i<=n;i++){
		int l = findleft(i);
		if(l==a[i]) a[i]=-1;
	}
	for (int i=1;i<=n;i++){
		if(a[i]==-1)continue;
		int l = findleft(i);
		int r = findright(i);
		if (l<a[i]&&r<a[i]) ret++;
	}
	//cout<<"cal :" <<ret<<endl;
	return ret;
}
bool isshan(int i){
	    if(a[i]==-1) return false;
		int l = findleft(i);
		int r = findright(i);
		if (l<a[i]&&r<a[i]) return true;
		return false;
}
int findmin(){
	int minv = 100;
	int minw = -1;
	for (int i=1;i<=n;i++){
		if(a[i]==-1) continue;
		if(isshan(i) &&f[i]<minv){
			minv = f[i];
			minw = i;
		}
	}
	//cout<<minv<<' '<<minw<<endl;
	a[minw]=-1;
	f[minw]=0;
	return minv;
}
int dfs(){
	int ret = 1000;
	if(cal()<=k) return 0;
	for (int i=1;i<=n;i++){
		if(isshan(i)){
			int tmp = a[i];
			a[i]=-1;
			ret =min(ret,f[i]+dfs()); 
			a[i]=tmp;
		}
	}
	return ret;
}
int main(){
	scanf("%d", &T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		a[0]=a[n+1]=0;
		//if(k>=3) {printf("0\n"); continue;}
		for (int i=1;i<=n;i++) if(a[i]==a[i-1]) a[i]=-1;
		for (int i=1;i<=n;i++){
			f[i]=calfei(i);
			//cout<<i<<' '<<a[i]<<' '<<f[i]<<endl;
		}
		int ans = dfs();
		printf("%d\n",ans);
	}
	return 0;
}
