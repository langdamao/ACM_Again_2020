#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		long l,r;
		scanf("%lld%lld",&l,&r);
		int now =1;
		while(now<=l || now<= r){
			if (l>=r) {
				l-=now;
				now++;
			}
			else{
				r-=now;
				now++;
			}
		}
		printf("Case #%d: %lld %lld %lld\n",ca++,now-1, l,r);
	}
	
	return 0;
}

