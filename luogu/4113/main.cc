#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int M=(1e6)*2+5;
const int N=(1e6)*2+5;
const int NUM=(1e6)*2+5;
struct node {
	int x,y;
	int wei;
}q[M], num[NUM];
int n,m,c;
int a[N];
int ans[M];
int d[N];
inline bool cmp(const node& x,const node& y){
	if (x.y!=y.y) return x.y<y.y;
	return x.x<y.x;
}
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
void add(int x, int wei, int& sumnow){
	if (num[x].x==-1 && num[x].y != -1) sumnow++;
	else if (num[x].x==-1 && num[x].y==-1){
			num[x].y=wei;
			return ;
	}
	else {
		update(num[x].x+1,-1);
	}
	update(num[x].y+1,1);
	num[x].x = num[x].y;
	num[x].y = wei;
}

int main(){
	while(scanf("%d%d%d",&n, &c, &m)!=EOF){
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for (int i=0;i<m;i++){
			scanf("%d%d",&q[i].x,&q[i].y);
			q[i].x--;q[i].y--;
			q[i].wei=i;
		}
		sort(q,q+m,cmp);
		memset(num,-1,sizeof(num));
		memset(d,0,sizeof(d));
		int now = 0;
		int sumnow = 0;
		for (int i=0;i<m;i++){
			node qy = q[i];
			while(now<=qy.y){
				add(a[now], now, sumnow);
				now++;
			}
			ans[qy.wei]=sumnow-sum(qy.x);
		}
		for (int i=0;i<m;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}

