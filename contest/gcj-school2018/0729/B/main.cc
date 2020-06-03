#include <cstring>
#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int N=100005;
long long a1,b1,c1,m1,a2,b2,c2,m2,a3,b3,c3,m3,a4,b4,c4,m4;
int n,k;
//bool ok(int i,int j){
//if(abs(x[i]-p[j])<=(h[j]-y[i])) return true;
//else return false;
//}
multiset<long long> rset,lset;
struct node {
	long long x;
	long long y;
}p[N],b[N];
inline const bool cmp(const node & x,const node &y){
	if (x.x!=y.x) return x.x<y.x;
	return x.y<y.y;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d%d",&n,&k);
		scanf("%lld%lld%lld%lld%lld%lld",&p[1].x,&p[2].x,&a1,&b1,&c1,&m1);
		scanf("%lld%lld%lld%lld%lld%lld",&p[1].y,&p[2].y,&a2,&b2,&c2,&m2);
		scanf("%lld%lld%lld%lld%lld%lld",&b[1].x,&b[2].x,&a3,&b3,&c3,&m3);
		scanf("%lld%lld%lld%lld%lld%lld",&b[1].y,&b[2].y,&a4,&b4,&c4,&m4);
		for (int i=3;i<=n;i++){
			p[i].x=(a1*p[i-1].x+b1*p[i-2].x+c1)%m1+1;
			p[i].y=(a2*p[i-1].y+b2*p[i-2].y+c2)%m2+1;
		}
		for (int i=3;i<=k;i++){
			b[i].x=(a3*b[i-1].x+b3*b[i-2].x+c3)%m3+1;
			b[i].y=(a4*b[i-1].y+b4*b[i-2].y+c4)%m4+1;
		}
		sort(p+1,p+1+n,cmp);
		sort(b+1,b+1+k,cmp);
		lset.clear();
		rset.clear();
		for (int i=1;i<=n;i++){
			rset.insert(p[i].y-p[i].x);
		}
		int indexj=1;
		for (int i=1;i<=k;i++){
			while(indexj<=n && (p[indexj].x<b[i].x)) {
				multiset<long long>::iterator it = rset.find(p[indexj].y-p[indexj].x);
				rset.erase(it);
				lset.insert(p[indexj].y+p[indexj].x);
				indexj++;
			}
			multiset<long long>::iterator it = rset.lower_bound(b[i].y-b[i].x); 
			//cout<<"r"<<' '<<i<<' '<<b[i].y-b[i].x<<' '<<(*it)<<endl;
			if(it!=rset.end()) {ans++;continue;}

			//cout<<"l"<<' '<<i<<' '<<b[i].y+b[i].x<<' '<<(*it)<<endl;
			it = lset.lower_bound(b[i].y+b[i].x); 
			if(it!=lset.end()) {ans++;continue;}
		}
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}

