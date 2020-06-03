#include <cstring>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int n,o;
long long d;
long long s[1000005],x[1000005],sum[1000005];
long long a,b,c,m,l;
multiset<long long> myset;
long long find(int x){
	long long tmp = sum[x-1]+d;
	multiset<long long>::iterator it = myset.upper_bound(tmp);
	//cout<<"findx: "<<tmp<<' '<<(*it)<<' '<<(*(it--))<<endl;
	if(it==myset.begin()) return -100000000000000000L;
	else return (*(--it)-sum[x-1]);
}
void printmyset(){
	multiset<long long>::iterator it = myset.begin();
	cout<<"myset: "<<myset.size()<<endl;
	while(it!=myset.end()){
		cout<<(*it)<<' ';
		it++;
	}
	cout<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	int ca=1;
	while(T--){
		scanf("%d%d%lld",&n,&o,&d);
		scanf("%lld%lld%lld%lld%lld%lld%lld",&x[1],&x[2],&a,&b,&c,&m,&l);
		sum[0]=0;
		for (int i=1;i<=n;i++){
			if (i<3) s[i]=x[i]+l;
			else {
				x[i]=(a*x[i-1]+b*x[i-2]+c)%m;
				s[i]=x[i]+l;
			}
			sum[i]=sum[i-1]+s[i];
			//printf("nihao: %d %lld\n",i,s[i]);
		}
		s[0]=x[0]=0;
		long long  ans = -100000000000000000L;
		int indexj=1;
		int	ji=0;
		myset.clear();
		for (int i=1;i<=n;i++){
			while(indexj<=n){
				if(s[indexj]%2+ji>o) break;
				myset.insert(sum[indexj]);
				if(s[indexj]%2) ji++;
				indexj++;
			}
			//printmyset();
			ans = max(find(i),ans);
			if (indexj<=i) {
				indexj++;
				ji=0;
				myset.clear();
			}
			else {
				if(s[i]%2)ji--;
				multiset<long long>::iterator it = myset.find(sum[i]);
				myset.erase(it);
			}
		}
		if(ans==-100000000000000000L)
		printf("Case #%d: IMPOSSIBLE\n",ca++);
		else 
		printf("Case #%d: %lld\n",ca++,ans);
	}
	return 0;
}
