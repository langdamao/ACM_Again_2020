#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e6+4;
int d[N];
int n,k;
inline int lowbit(int x){
	return x&(-x);
}
void update(int x,int k){
	while(x<=n){
		d[x]+=k;
		x+=lowbit(x);
	}
}
int sum(int x){
	int ret=0;
	while(x>0){
		ret+=d[x];
		x-=lowbit(x);
	}
	return ret;
}

int cal(int x,int y){
	int xx = min(x,y);
	int yy = max(x,y);
	y=yy,x=xx;
	if ((y-x)*2>=n){
		return sum(n)-sum(y)+sum(x-1);
	}
	else return sum(y-1)-sum(x);
}
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(d,0,sizeof(d));
		int now=1;
		long long  ans=1L;
		for (int i=1;i<=n;i++){
			int next = now+k;
			if (next>n) next-=n;
			ans+=cal(now,next)+1L;
			printf("%lld ",ans);
			update(now,1);
			update(next,1);
			now=next;
		}
		puts("");
	}
	return 0;
}
