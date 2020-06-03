#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
long long mod = 998244353L;
long long a[200005];
long long n,k;
int main(){
	while(scanf("%lld%lld",&n,&k)!=EOF){
		long long ansmax = (n+n-k+1)*k/2;
		long long min_num = n-k+1;
		long long ans = 1;
		int last =-1;
		for (int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if (a[i]>=min_num){
				if (last>=0) {
					ans= ans*(i-last)%mod;
				}
				last = i;
			}
		}
		printf("%lld %lld\n",ansmax,ans);
	}
	return 0;
}
