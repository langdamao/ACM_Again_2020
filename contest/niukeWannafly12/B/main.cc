#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int a[1000004];
int b[1000005];
int n,m;
inline bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		for (int i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		for (int i=0;i<n;i++)scanf("%d",&b[i]);
		sort(b,b+n,cmp);
		long long now=0;
		long long ans=0;
		for (int i=0;i<n;i++){
			now += b[i]-a[i];
			if (i%3==2) now+=m;
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
