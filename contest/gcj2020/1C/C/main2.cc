#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
long long n,d,ans;
struct node {
	long long ge;
	long long dao;
	long long shu;
	node(){
		ge=0;
		dao=0;
		shu=0;
	}
	node (long long x,long y,long long z){
		ge=x;
		dao=y;
		shu=z;
	}
	bool islin(node y){
		if (ge<d && ge+y.ge>=d) return true;
		return false;
	}
	node add(node y){
		node tmp ;
		tmp.ge= ge+y.ge;
		tmp.dao = dao+y.dao;
		tmp.shu=shu+y.shu;
		return tmp;
	}
};
map<long long,node> has;
long long a[10005];
node get(map<long long, node>& myMap,long long x){
	map<long long, node>::iterator it;
	it = myMap.find(x);
	if (it!=myMap.end()) return it->second;
	else return node();
}
void findyinzi(long long x){
	for (int i=1;i<=d;i++){
		if (x%i==0){
			node tmp = get(has,x/i);
			node newtmp = node(i,i-1,1);
			long long tmpans=0;
			if (tmp.islin(newtmp)){
				tmpans = tmp.dao+ (d-tmp.ge);
			    if (tmp.ge + newtmp.ge	== d){
					tmpans--;
				}
				ans= min(ans,tmpans);
			}
			tmp=tmp.add(newtmp);
			has[x/i]=tmp;
		}
	}
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		long long x;
		scanf("%d%d",&n,&d);
		for (int i=0;i<n;i++){
			scanf("%lld",&x);
			a[i]=x;
		}
		sort(a,a+n);
		ans=d-1;
		for (int bei=1;bei<=d;bei++){
		    has.clear();
			for (int i=0;i<n;i++) a[i]=a[i]*bei;
			for (int i=0;i<n;i++) {
				findyinzi(a[i]);
			}
			map<long long ,node>::iterator it = has.begin();
			while(it!=has.end()){
				if (it->second.ge<d){
					node tmp = it->second;
					long long num = it->second.ge;
					for (int i=n;i>=0;i--){
						if (a[i]%it->first!=0 || a[i] > it->first*d){
							num+=a[i]/it->first;
							if (num>=d){
								ans = min(ans,tmp.dao+(d-tmp.ge));
								break;
							}
						}
					}
				}
				it++;
			}
			for (int i=0;i<n;i++) a[i]=a[i]/bei;
		}
		printf("Case #%d: %lld\n",ca++,ans);
	}
	return 0 ;
}

