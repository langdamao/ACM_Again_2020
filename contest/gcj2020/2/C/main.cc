#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int a[105];
struct node {
	int x,y;
}p[1005];
bool pingxing(int x,int y,int xx,int yy){
	if (p[x].x==p[y].x || p[xx].x==p[yy].x) return (p[xx].x==p[yy].x && p[x].x==p[y].x);
	if (p[x].y==p[y].y || p[xx].y==p[yy].y) return (p[xx].y==p[yy].y && p[x].y==p[y].y);
	long long k1 = (long long)((long long)p[y].y-p[x].y)*((long long)p[yy].x-p[xx].x);
	long long k2 = (long long)((long long)p[yy].y-p[xx].y)*((long long)p[y].x-p[x].x);
	return k1==k2;
}
bool pingxing(int x,int y,int xx,int yy,int xxx,int yyy){
	if (p[x].x==p[y].x || p[xx].x==p[yy].x || p[xxx].x==p[yyy].x) return (p[xx].x==p[yy].x && p[xxx].x==p[yyy].x && p[x].x==p[y].x);
	if (p[x].y==p[y].y || p[xx].y==p[yy].y || p[xxx].y==p[yyy].y) return (p[xx].y==p[yy].y && p[xxx].y==p[yyy].y && p[x].y==p[y].y);
	long long k1 = (long long)((long long)p[y].y-p[x].y)*((long long)p[yy].x-p[xx].x);
	long long k2 = (long long)((long long)p[yy].y-p[xx].y)*((long long)p[y].x-p[x].x);
	long long k3 = (long long)((long long)p[y].y-p[x].y)*((long long)p[yyy].x-p[xxx].x);
	long long k4 = (long long)((long long)p[yyy].y-p[xxx].y)*((long long)p[y].x-p[x].x);
	return k1==k2 && k3==k4;
}
bool have[105];
int n;
int check(int n){
	int ans=4;
	if (pingxing(a[0],a[1],a[2],a[3])) ans=6;
	if (n>6 && pingxing(a[0],a[1],a[2],a[3],a[4],a[5])) ans=8;
	return ans;
}
int dfs(int n,int step){
	int ret=0;
	if (step == n){
		return check(n);
	}
	for (int i=1;i<=n;i++){
		if (!have[i]){
			have[i]=true;
			a[step]=i;
			ret= max(ret,dfs(n,step+1));
			have[i]=false;
		}
	}
	 return ret;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans;
		for (int i=1;i<=n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		if (n<=4) ans=n;
		else {
			memset(have,0,sizeof(have));
			ans = min(n,dfs(n,0));
		}
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}
