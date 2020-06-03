#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<long long,int> has;
long long a[1000];
int get(map<long long, int>& myMap,long long x){
	map<long long, int>::iterator it;
	it = myMap.find(x);
	if (it!=myMap.end()) return it->second;
	else return 0;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		int n,d,ans;
		long long x;
		scanf("%d%d",&n,&d);
		has.clear();
		long long maxhas=0,hasx=0,maxx=0;
		for (int i=0;i<n;i++){
			scanf("%lld",&x);
			a[i]=x;
			has[x]=get(has,x)+1;
			if (has[x]>maxhas || (has[x]==maxhas&&x<maxx)){
				maxhas=has[x];
				hasx=x;
			}
			maxx = max(maxx,x);
		}
		if (maxhas>=d) ans=0;
		else if (d==2) ans=1;
		else if (maxhas>=2 && hasx<maxx) ans=1;
		else {
			ans = 2;
			for (int i=0;i<n;i++){
				if (get(has,a[i]*2)!=0){
					ans=1;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",ca++,ans);
			
	}
	return 0 ;
}
