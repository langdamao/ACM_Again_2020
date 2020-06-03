#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long findeq(long long x){
	long long head = 1;
	long long tail = (long long)sqrt(x*2)+10;
	while(head<=tail){
		long long mid = (head+tail)/2;
		long long fmid = (1+mid)*mid/2;
		if (fmid>=x) {
			tail=mid-1;
		}
		else {
			head = mid+1;
		}
	}
	return head;
}
long long find(long long x,long long st){
	long long head = 1;
	long long tail = (long long) sqrt(x*2)+10;
	while(head<=tail){
		long long mid = (head+tail)/2;
		long long fmid = (st+mid+st+mid-2)*(mid)/2;
		if (fmid<=x) {
			head = mid+1;
		}
		else {
			tail = mid-1;
		}
	}
	return tail;
}
long long remine(long long x,long long st,long long num){
	return x-(st+num+st+num-2)*num/2;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		long l,r;
		scanf("%lld%lld",&l,&r);
		long long x;
		if (l>=r) {
			x = findeq(l-r+1);
			if (x>1){
				l -= (x)*(x-1)/2;
				if (l<0) {
					l+=(x-1);
					x--;
				}
			}
		}
		else {
			x = findeq(r-l)+1;
			if (x>1){
				r -= x*(x-1)/2;
				if (r<0) {
					r+=x-1;
					x--;
				}
			}
		}
		long long lx = find(l,x);
		long long rx = find(r,x+1);
		long long ans = max(x+lx*2-2,x+1+rx*2-2);
		printf("Case #%d: %lld %lld %lld\n",ca++,ans, remine(l,x,lx),remine(r,x+1,rx));
	}
	
	return 0;
}

