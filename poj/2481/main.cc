#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e5+5;
struct node {
	int x,y;
	int wei;
}a[N];
inline bool cmp(const node& x,const node& y){
	if (x.y!=y.y) return x.y>y.y;
	return x.x<y.x;
}
int d[N];
int n;
int ans[N];
inline int lowbit(int x){
	return x&(-x);
}
int sum(int x){
	int ret=0;
	while(x>0){
		ret+=d[x];
		x-=lowbit(x);
	}
	return ret;
}
void update(int x){
	while(x<=N){
		d[x]+=1;
		x+=lowbit(x);
	}
}
int main(){
	while(scanf("%d",&n)!=EOF && n!=0){
		for (int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].x++;
			a[i].y++;
			a[i].wei=i;
		}
		sort(a,a+n,cmp);
		memset(d,0,sizeof(d));
		for(int i=0;i<n;i++){
			update(a[i].x);
			if (i!=0 && a[i].x==a[i-1].x && a[i].y==a[i-1].y){
				ans[a[i].wei]=ans[a[i-1].wei];
			}
			else {
				ans[a[i].wei]=sum(a[i].x)-1;
			}
		}
		for (int i=0;i<n;i++){
			if (i) printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
	}
	return 0;
}
